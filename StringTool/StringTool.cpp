#include "StringTool.h"

#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

#include <functional>
#include <algorithm>	// std::transform 사용을 위해 필요.

#include <windows.h>
#include <strsafe.h>

const unsigned int MOONG::StringTool::max_buf_size_ = 2048;
const char MOONG::StringTool::BASE64_PADDING_CHAR = '=';

#ifndef INT32_MAX
#define INT32_MAX 2147483647 
#endif

const int MOONG::StringTool::compare(const std::string input1, const std::string iniput2, const bool ignoreCase)
{
	if (ignoreCase)
	{
		return _stricmp(input1.c_str(), iniput2.c_str());
	}
	else
	{
		return input1.compare(iniput2);
	}
}

const std::string MOONG::StringTool::encode_base64(const std::string& input)
{
	return encode_base64_(input);
}

const std::string MOONG::StringTool::decode_base64(const std::string& input)
{
	return decode_base64_(input);
}

const std::string MOONG::StringTool::encode_base64_url(const std::string& input)
{
	return encode_base64_(input, true);
}

const std::string MOONG::StringTool::decode_base64_url(const std::string& input)
{
	return decode_base64_(input, true);
}

const size_t MOONG::StringTool::find_index_rightmost(const std::string input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::find_index_rightmost(input, delimiters);
}

const size_t MOONG::StringTool::find_index_rightmost(const std::string input, const std::string delimiters, const bool delimiter_whole_use/* = false*/)
{
	size_t index_rightmost = 0;
	bool isFindDelimiter = false;

	if (delimiter_whole_use == true)
	{
		if (input.rfind(delimiters) != std::string::npos)
		{
			index_rightmost = input.rfind(delimiters);
		}
		else
		{
			return std::string::npos;
		}
	}
	else
	{
		isFindDelimiter = false;

		for (size_t i = 0; i < delimiters.length(); i++)
		{
			if (input.rfind(delimiters[i]) != std::string::npos)
			{
				isFindDelimiter = true;

				if (input.rfind(delimiters[i]) > index_rightmost)
				{
					index_rightmost = input.rfind(delimiters[i]);
				}
			}
		}

		if (isFindDelimiter == false)
		{
			return std::string::npos;
		}
	}
	
	return index_rightmost;
}

const size_t MOONG::StringTool::find_index_leftmost(const std::string input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::find_index_leftmost(input, delimiters);
}

const size_t MOONG::StringTool::find_index_leftmost(const std::string input, const std::string delimiters, const bool delimiter_whole_use)
{
	size_t index_leftmost = input.length();
	bool isFindDelimiter = false;

	if (delimiter_whole_use == true)
	{
		if (input.find(delimiters) != std::string::npos)
		{
			index_leftmost = input.find(delimiters);
		}
		else
		{
			return std::string::npos;
		}
	}
	else
	{
		isFindDelimiter = false;

		for (size_t i = 0; i < delimiters.length(); i++)
		{
			if (input.find(delimiters[i]) != std::string::npos)
			{
				isFindDelimiter = true;

				if (input.find(delimiters[i]) < index_leftmost)
				{
					index_leftmost = input.find(delimiters[i]);
				}
			}
		}

		if (isFindDelimiter == false)
		{
			return std::string::npos;
		}
	}

	return index_leftmost;
}

const std::string& MOONG::StringTool::cut_right(std::string& input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::cut_right(input, delimiters);
}

const std::string  MOONG::StringTool::cut_right_keep_origin(std::string input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::cut_right(input, delimiters);
}

const std::string& MOONG::StringTool::cut_right(std::string& input, const std::string delimiters, const bool delimiter_whole_use/* = false*/)
{
	size_t index_rightmost = MOONG::StringTool::find_index_rightmost(input, delimiters, delimiter_whole_use);

	if (index_rightmost != std::string::npos)
	{
		input.erase(index_rightmost, input.length() - index_rightmost);
	}

	return input;
}

const std::string MOONG::StringTool::cut_right_keep_origin(std::string input, const std::string delimiters, const bool delimiter_whole_use/* = false*/)
{
	return MOONG::StringTool::cut_right(input, delimiters, delimiter_whole_use);
}

const std::string MOONG::StringTool::pop_right(std::string& input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::pop_right(input, delimiters);
}

const std::string MOONG::StringTool::pop_right_keep_origin(std::string input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::pop_right(input, delimiters);
}

const std::string MOONG::StringTool::pop_right(std::string& input, const std::string delimiters, const bool delimiter_whole_use)
{
	std::string tail = "";

	size_t index_rightmost = MOONG::StringTool::find_index_rightmost(input, delimiters, delimiter_whole_use);

	if (index_rightmost != std::string::npos)
	{
		if (delimiter_whole_use == true)
		{
			if (index_rightmost + delimiters.length() < input.length())
			{
				tail = input.substr(index_rightmost + delimiters.length(), input.length() - index_rightmost + delimiters.length());
			}
		}
		else
		{
			if (index_rightmost + 1 < input.length())
			{
				tail = input.substr(index_rightmost + 1, input.length() - index_rightmost + 1);
			}
		}

		input.erase(index_rightmost, input.length() - index_rightmost);
	}
	else
	{
		return input;
	}

	return tail;
}

const std::string MOONG::StringTool::pop_right_keep_origin(std::string input, const std::string delimiters, const bool delimiter_whole_use)
{
	return MOONG::StringTool::pop_right(input, delimiters, delimiter_whole_use);
}

const std::string& MOONG::StringTool::cut_left(std::string& input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::cut_left(input, delimiters);
}

const std::string MOONG::StringTool::cut_left_keep_origin(std::string input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::cut_left(input, delimiters);
}

const std::string& MOONG::StringTool::cut_left(std::string& input, const std::string delimiters, const bool delimiter_whole_use)
{
	size_t index_leftmost = MOONG::StringTool::find_index_leftmost(input, delimiters, delimiter_whole_use);

	if (index_leftmost != std::string::npos)
	{
		if (delimiter_whole_use == true)
		{
			input.erase(0, index_leftmost + delimiters.length());
		}
		else
		{
			input.erase(0, index_leftmost + 1);
		}
	}

	return input;
}

const std::string MOONG::StringTool::cut_left_keep_origin(std::string input, const std::string delimiters, const bool delimiter_whole_use)
{
	return MOONG::StringTool::cut_left(input, delimiters, delimiter_whole_use);
}

const std::string MOONG::StringTool::pop_left(std::string& input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::pop_left(input, delimiters);
}

const std::string MOONG::StringTool::pop_left_keep_origin(std::string input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::pop_left(input, delimiters);
}

const std::string MOONG::StringTool::pop_left(std::string& input, const std::string delimiters, const bool delimiter_whole_use)
{
	std::string head = "";

	size_t index_leftmost = MOONG::StringTool::find_index_leftmost(input, delimiters, delimiter_whole_use);

	if (index_leftmost != std::string::npos)
	{
		head = input.substr(0, index_leftmost);

		if (delimiter_whole_use == true)
		{
			input.erase(0, index_leftmost + delimiters.length());
		}
		else
		{
			input.erase(0, index_leftmost + 1);
		}
	}
	else
	{
		return input;
	}

	return head;
}

const std::string MOONG::StringTool::pop_left_keep_origin(std::string input, const std::string delimiters, const bool delimiter_whole_use)
{
	return MOONG::StringTool::pop_left(input, delimiters, delimiter_whole_use);
}

std::string MOONG::StringTool::format(const std::string format, ...)
{
	std::string output = "";

	va_list arg_ptr;

	va_start(arg_ptr, format);
	output = MOONG::StringTool::format_(format, arg_ptr);
	va_end(arg_ptr);

	return output;
}

std::wstring MOONG::StringTool::format(const std::wstring format, ...)
{
	std::string output = "";

	va_list arg_ptr;

	va_start(arg_ptr, format);
	output = MOONG::StringTool::format_(MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
	va_end(arg_ptr);

	return MOONG::ConvertDataType::string_to_wstring(output);
}

std::string MOONG::StringTool::format(const std::string format, va_list arg_ptr)
{
	char build_string[MOONG::StringTool::max_buf_size_] = { 0 };

	StringCchVPrintfA(build_string, MOONG::StringTool::max_buf_size_, format.c_str(), arg_ptr);

	return std::string(build_string);
}

std::wstring MOONG::StringTool::format(const std::wstring format, va_list arg_ptr)
{
	return MOONG::ConvertDataType::string_to_wstring(MOONG::StringTool::format(MOONG::ConvertDataType::wstring_to_string(format), arg_ptr));
}

std::string& MOONG::StringTool::remove(std::string& input, const char remove_char)
{
	std::string remove_string;
	remove_string = remove_char;

	return MOONG::StringTool::remove(input, remove_string);
}

std::string& MOONG::StringTool::remove(std::string& input, const std::string remove_string)
{
	while (input.find(remove_string) != std::string::npos)
	{
		input.replace(input.find(remove_string), remove_string.length(), "");
	}

	return input;
}

std::string MOONG::StringTool::remove_keep_origin(std::string input, const std::string remove_string)
{
	return MOONG::StringTool::remove(input, remove_string);
}

std::string& MOONG::StringTool::replace(std::string& string_original, const std::string string_find, const std::string string_change)
{
	while(string_original.find(string_find) != std::string::npos)
	{
		string_original.replace(string_original.find(string_find), string_find.length(), string_change);
	}

	return string_original;
}

std::string MOONG::StringTool::replace_keep_origin(std::string string_original, const std::string string_find, const std::string string_change)
{
	return MOONG::StringTool::replace(string_original, string_find, string_change);
}

const std::vector<std::string> MOONG::StringTool::split(const std::string input, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::split(input, delimiters);
}

const std::vector<std::string> MOONG::StringTool::split(const std::string input, const std::string delimiters, const bool delimiter_whole_use/* = false*/)
{
	size_t index_temp = 0;
	size_t index_nexe_token = INT32_MAX;
	size_t index_prev_token = 0;
	bool is_find_token = false;

	std::vector<std::string> return_value;

	for (;;)
	{
		is_find_token = false;

		if(delimiter_whole_use == true) // delimiters 문자열 전체를 하나의 구분자로 사용.
		{
			index_temp = input.find(delimiters, index_prev_token);

			if (index_temp != std::string::npos)
			{
				is_find_token = true;

				index_nexe_token = index_temp;
			}
		}
		else
		{
			for (size_t i = 0; i < delimiters.length(); i++)
			{
				index_temp = input.find(delimiters.at(i), index_prev_token);

				if (index_temp != std::string::npos)
				{
					is_find_token = true;

					if (index_temp < index_nexe_token)
					{
						index_nexe_token = index_temp;
					}
				}
			}
		}

		if (is_find_token == false)
		{
			return_value.push_back(input.substr(index_prev_token));

			break;
		}
		else
		{
			return_value.push_back(input.substr(index_prev_token, index_nexe_token - index_prev_token));

			if(delimiter_whole_use == true)
			{
				index_prev_token = index_nexe_token + delimiters.length();
			}
			else
			{
				index_prev_token = index_nexe_token + 1;
			}
			
			index_nexe_token = INT32_MAX;
		}
	}

	return return_value;
}

std::string& MOONG::StringTool::tolower(std::string& input)
{
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	return input;
}

std::string& MOONG::StringTool::toupper(std::string& input)
{
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	return input;
}

std::string MOONG::StringTool::tolower_keep_origin(std::string input)
{
	return MOONG::StringTool::tolower(input);
}

std::string MOONG::StringTool::toupper_keep_origin(std::string input)
{
	return MOONG::StringTool::toupper(input);
}

// 앞에 있는 화이트 스페이스 문자 제거
std::string& MOONG::StringTool::trim_left(std::string& input)
{
	if(input.length() == 0)
	{
		return input;
	}

	size_t index = 0;

	for(size_t i = 0; i < input.length(); i++)
	{
		if(input.at(i) != ' ' && input.at(i) != '\t' && input.at(i) != '\n' && input.at(i) != '\r\n')
		{
			index = i;

			break;
		}
	}

	input.erase(0, index);

	return input;
}
// 뒤에 있는 화이트 스페이스 문자 제거
std::string& MOONG::StringTool::trim_right(std::string& input)
{
	if(input.length() == 0)
	{
		return input;
	}

	size_t index = 0;

	for(size_t i = input.length() - 1; i >= 0; i--)
	{
		if(input.at(i) != ' ' && input.at(i) != '\t' && input.at(i) != '\n' && input.at(i) != '\r\n')
		{
			index = i + 1;

			break;
		}
	}

	input.erase(index);

	return input;
}
// 양쪽 끝의 화이트 스페이스 문자 제거
std::string& MOONG::StringTool::trim(std::string& input)
{
	return trim_left(trim_right(input));
}

// trim from start (copying)
std::string MOONG::StringTool::trim_left_keep_origin(std::string input)
{
	return MOONG::StringTool::trim_left(input);
}
// trim from end (copying)
std::string MOONG::StringTool::trim_right_keep_origin(std::string input)
{
	return MOONG::StringTool::trim_right(input);
}
// trim from both ends (copying)
std::string MOONG::StringTool::trim_keep_origin(std::string input)
{
	return MOONG::StringTool::trim(input);
}

std::string MOONG::StringTool::pad_start(const std::string& input, const size_t target_length, const char padding_char)
{
	if (input.length() >= target_length)
	{
		return input;
	}

	return std::string(target_length - input.length(), padding_char) + input;
}

std::string MOONG::StringTool::pad_end(const std::string& input, const size_t target_length, const char padding_char)
{
	if (input.length() >= target_length)
	{
		return input;
	}

	return input + std::string(target_length - input.length(), padding_char);
}

const std::string MOONG::StringTool::encode_base64_(const std::string& input, const bool use_url_encoding_characters/* = false*/)
{
	std::string BASE64_INDEX_TABLE;
	BASE64_INDEX_TABLE += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	BASE64_INDEX_TABLE += "abcdefghijklmnopqrstuvwxyz";
	BASE64_INDEX_TABLE += "0123456789";
	if (true == use_url_encoding_characters)
	{
		BASE64_INDEX_TABLE += "-_";
	}
	else
	{
		BASE64_INDEX_TABLE += "+/";
	}

	std::string encoded_str;

	for (size_t i = 0; i < input.length(); i += 3)
	{
		if ((i + 2) < input.length())
		{
			encoded_str += BASE64_INDEX_TABLE.at((input.at(i) >> 2) & 0x3F);
			encoded_str += BASE64_INDEX_TABLE.at(((input.at(i) & 0x3) << 4) | ((input.at(i + 1) >> 4) & 0xF));
			encoded_str += BASE64_INDEX_TABLE.at(((input.at(i + 1) & 0xF) << 2) | ((input.at(i + 2) >> 6) & 0x3));
			encoded_str += BASE64_INDEX_TABLE.at(input.at(i + 2) & 0x3F);
		}
		else if ((i + 1) < input.length())
		{
			encoded_str += BASE64_INDEX_TABLE.at((input.at(i) >> 2) & 0x3F);
			encoded_str += BASE64_INDEX_TABLE.at(((input.at(i) & 0x3) << 4) | ((input.at(i + 1) >> 4) & 0xF));
#if _MSC_VER > 1200
			encoded_str += BASE64_INDEX_TABLE.at((static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(input.at(i + 1) & 0xF)) << 2);
#else
			encoded_str += BASE64_INDEX_TABLE.at((input.at(i + 1) & 0xF) << 2);
#endif

			encoded_str += MOONG::StringTool::BASE64_PADDING_CHAR;

			break;
		}
		else
		{
			encoded_str += BASE64_INDEX_TABLE.at((input.at(i) >> 2) & 0x3F);
#if _MSC_VER > 1200
			encoded_str += BASE64_INDEX_TABLE.at((static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(input.at(i) & 0x3)) << 4);
#else
			encoded_str += BASE64_INDEX_TABLE.at((input.at(i) & 0x3) << 4);
#endif

			encoded_str += MOONG::StringTool::BASE64_PADDING_CHAR;
			encoded_str += MOONG::StringTool::BASE64_PADDING_CHAR;

			break;
		}
	}

	return encoded_str;
}

const std::string MOONG::StringTool::decode_base64_(const std::string& input, const bool use_url_encoding_characters/* = false*/)
{
	std::string BASE64_INDEX_TABLE;
	BASE64_INDEX_TABLE += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	BASE64_INDEX_TABLE += "abcdefghijklmnopqrstuvwxyz";
	BASE64_INDEX_TABLE += "0123456789";
	if (true == use_url_encoding_characters)
	{
		BASE64_INDEX_TABLE += "-_";
	}
	else
	{
		BASE64_INDEX_TABLE += "+/";
	}

	std::string encoded_str = input;
	MOONG::StringTool::remove(encoded_str, MOONG::StringTool::BASE64_PADDING_CHAR);

	size_t i = 0;
	// base64 인코딩 외의 문자가 있는경우.
	for (i = 0; i < encoded_str.length(); i++)
	{
		if (BASE64_INDEX_TABLE.find(encoded_str.at(i)) == std::string::npos)
		{
			return std::string("It contains characters other than the Base64 index table or need to check Base64 and Base64Url.");
		}
	}

	std::string decoded_str;
	char decoded_str_block[4] = { 0 };

	for (i = 0; i < encoded_str.length(); i += 4)
	{
		ZeroMemory(decoded_str_block, sizeof(decoded_str_block));

		if ((i + 3) < encoded_str.length())
		{
			decoded_str_block[0] |= BASE64_INDEX_TABLE.find(encoded_str.at(i)) << 2;
			decoded_str_block[0] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 1)) >> 4;

			decoded_str_block[1] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 1)) << 4;
			decoded_str_block[1] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 2)) >> 2;

			decoded_str_block[2] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 2)) << 6;
			decoded_str_block[2] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 3));

			decoded_str += decoded_str_block;
		}
		else if ((i + 2) < encoded_str.length())
		{
			decoded_str_block[0] |= BASE64_INDEX_TABLE.find(encoded_str.at(i)) << 2;
			decoded_str_block[0] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 1)) >> 4;

			decoded_str_block[1] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 1)) << 4;
			decoded_str_block[1] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 2)) >> 2;

			decoded_str_block[2] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 2)) << 6;

			decoded_str += decoded_str_block;

			break;
		}
		else if ((i + 1) < encoded_str.length())
		{
			decoded_str_block[0] |= BASE64_INDEX_TABLE.find(encoded_str.at(i)) << 2;
			decoded_str_block[0] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 1)) >> 4;

			decoded_str_block[1] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 1)) << 4;

			decoded_str += decoded_str_block;

			break;
		}
		else
		{
			decoded_str_block[0] |= BASE64_INDEX_TABLE.find(encoded_str.at(i)) << 2;
			decoded_str_block[0] |= BASE64_INDEX_TABLE.find(encoded_str.at(i + 1)) >> 4;

			decoded_str += decoded_str_block;

			break;
		}
	}

	return decoded_str;
}

const std::string MOONG::StringTool::format_(const std::string format, va_list arg_ptr)
{
	char build_string[MOONG::StringTool::max_buf_size_] = { 0 };

	StringCchVPrintfA(build_string, MOONG::StringTool::max_buf_size_, format.c_str(), arg_ptr);

	return std::string(build_string);
}
