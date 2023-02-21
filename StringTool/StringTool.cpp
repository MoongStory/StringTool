#include "StringTool.h"

#include <functional>
#include <algorithm>	// std::transform 사용을 위해 필요.

#include <windows.h>
#include <strsafe.h>

const unsigned int MOONG::StringTool::max_buf_size_ = 2048;
const char MOONG::StringTool::BASE64_PADDING_CHAR = '=';

#ifndef INT32_MAX
#define INT32_MAX 2147483647 
#endif

const int MOONG::StringTool::compare(const std::string string1, const std::string string2, const bool ignoreCase)
{
	if (ignoreCase)
	{
		return _stricmp(string1.c_str(), string2.c_str());
	}
	else
	{
		return string1.compare(string2);
	}
}

const std::string MOONG::StringTool::encode_base64(const std::string& str)
{
	return _encode_base64(str);
}

const std::string MOONG::StringTool::decode_base64(const std::string& str)
{
	return _decode_base64(str);
}

const std::string MOONG::StringTool::encode_base64_url(const std::string& str)
{
	return _encode_base64(str, true);
}

const std::string MOONG::StringTool::decode_base64_url(const std::string& str)
{
	return _decode_base64(str, true);
}

const size_t MOONG::StringTool::find_index_rightmost(const std::string str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::find_index_rightmost(str, delimiters);
}

const size_t MOONG::StringTool::find_index_rightmost(const std::string str, const std::string delimiters, const bool delimiter_whole_use/* = false*/)
{
	size_t index_rightmost = 0;
	bool isFindDelimiter = false;

	if (delimiter_whole_use == true)
	{
		if (str.rfind(delimiters) != std::string::npos)
		{
			index_rightmost = str.rfind(delimiters);
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
			if (str.rfind(delimiters[i]) != std::string::npos)
			{
				isFindDelimiter = true;

				if (str.rfind(delimiters[i]) > index_rightmost)
				{
					index_rightmost = str.rfind(delimiters[i]);
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

const size_t MOONG::StringTool::find_index_leftmost(const std::string str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::find_index_leftmost(str, delimiters);
}

const size_t MOONG::StringTool::find_index_leftmost(const std::string str, const std::string delimiters, const bool delimiter_whole_use)
{
	size_t index_leftmost = str.length();
	bool isFindDelimiter = false;

	if (delimiter_whole_use == true)
	{
		if (str.find(delimiters) != std::string::npos)
		{
			index_leftmost = str.find(delimiters);
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
			if (str.find(delimiters[i]) != std::string::npos)
			{
				isFindDelimiter = true;

				if (str.find(delimiters[i]) < index_leftmost)
				{
					index_leftmost = str.find(delimiters[i]);
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

const std::string& MOONG::StringTool::cut_right(std::string& str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::cut_right(str, delimiters);
}

const std::string  MOONG::StringTool::cut_right_keep_origin(std::string str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::cut_right(str, delimiters);
}

const std::string& MOONG::StringTool::cut_right(std::string& str, const std::string delimiters, const bool delimiter_whole_use/* = false*/)
{
	size_t index_rightmost = MOONG::StringTool::find_index_rightmost(str, delimiters, delimiter_whole_use);

	if (index_rightmost != std::string::npos)
	{
		str.erase(index_rightmost, str.length() - index_rightmost);
	}

	return str;
}

const std::string MOONG::StringTool::cut_right_keep_origin(std::string str, const std::string delimiters, const bool delimiter_whole_use/* = false*/)
{
	return MOONG::StringTool::cut_right(str, delimiters, delimiter_whole_use);
}

const std::string MOONG::StringTool::pop_right(std::string& str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::pop_right(str, delimiters);
}

const std::string MOONG::StringTool::pop_right_keep_origin(std::string str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::pop_right(str, delimiters);
}

const std::string MOONG::StringTool::pop_right(std::string& str, const std::string delimiters, const bool delimiter_whole_use)
{
	std::string tail = "";

	size_t index_rightmost = MOONG::StringTool::find_index_rightmost(str, delimiters, delimiter_whole_use);

	if (index_rightmost != std::string::npos)
	{
		if (delimiter_whole_use == true)
		{
			if (index_rightmost + delimiters.length() < str.length())
			{
				tail = str.substr(index_rightmost + delimiters.length(), str.length() - index_rightmost + delimiters.length());
			}
		}
		else
		{
			if (index_rightmost + 1 < str.length())
			{
				tail = str.substr(index_rightmost + 1, str.length() - index_rightmost + 1);
			}
		}

		str.erase(index_rightmost, str.length() - index_rightmost);
	}

	return tail;
}

const std::string MOONG::StringTool::pop_right_keep_origin(std::string str, const std::string delimiters, const bool delimiter_whole_use)
{
	return MOONG::StringTool::pop_right(str, delimiters, delimiter_whole_use);
}

const std::string& MOONG::StringTool::cut_left(std::string& str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::cut_left(str, delimiters);
}

const std::string MOONG::StringTool::cut_left_keep_origin(std::string str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::cut_left(str, delimiters);
}

const std::string& MOONG::StringTool::cut_left(std::string& str, const std::string delimiters, const bool delimiter_whole_use)
{
	size_t index_leftmost = MOONG::StringTool::find_index_leftmost(str, delimiters, delimiter_whole_use);

	if (index_leftmost != std::string::npos)
	{
		if (delimiter_whole_use == true)
		{
			str.erase(0, index_leftmost + delimiters.length());
		}
		else
		{
			str.erase(0, index_leftmost + 1);
		}
	}

	return str;
}

const std::string MOONG::StringTool::cut_left_keep_origin(std::string str, const std::string delimiters, const bool delimiter_whole_use)
{
	return MOONG::StringTool::cut_left(str, delimiters, delimiter_whole_use);
}

const std::string MOONG::StringTool::pop_left(std::string& str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::pop_left(str, delimiters);
}

const std::string MOONG::StringTool::pop_left_keep_origin(std::string str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::pop_left(str, delimiters);
}

const std::string MOONG::StringTool::pop_left(std::string& str, const std::string delimiters, const bool delimiter_whole_use)
{
	std::string head = "";

	size_t index_leftmost = MOONG::StringTool::find_index_leftmost(str, delimiters, delimiter_whole_use);

	if (index_leftmost != std::string::npos)
	{
		head = str.substr(0, index_leftmost);

		if (delimiter_whole_use == true)
		{
			str.erase(0, index_leftmost + delimiters.length());
		}
		else
		{
			str.erase(0, index_leftmost + 1);
		}
	}

	return head;
}

const std::string MOONG::StringTool::pop_left_keep_origin(std::string str, const std::string delimiters, const bool delimiter_whole_use)
{
	return MOONG::StringTool::pop_left(str, delimiters, delimiter_whole_use);
}

std::string MOONG::StringTool::format(const std::string format, ...)
{
	char build_string[MOONG::StringTool::max_buf_size_] = { 0 };

	va_list arg_ptr;

	va_start(arg_ptr, format);
	
	StringCchVPrintfA(build_string, MOONG::StringTool::max_buf_size_, format.c_str(), arg_ptr);

	va_end(arg_ptr);

	return std::string(build_string);
}

std::string& MOONG::StringTool::remove(std::string& str, const char remove_char)
{
	std::string remove_string;
	remove_string = remove_char;

	return MOONG::StringTool::remove(str, remove_string);
}

std::string& MOONG::StringTool::remove(std::string& str, const std::string remove_string)
{
	while (str.find(remove_string) != std::string::npos)
	{
		str.replace(str.find(remove_string), remove_string.length(), "");
	}

	return str;
}

std::string MOONG::StringTool::remove_keep_origin(std::string str, const std::string remove_string)
{
	return MOONG::StringTool::remove(str, remove_string);
}

std::string& MOONG::StringTool::replace(std::string& str, const std::string str_find, const std::string str_change)
{
	while(str.find(str_find) != std::string::npos)
	{
		str.replace(str.find(str_find), str_find.length(), str_change);
	}

	return str;
}

std::string MOONG::StringTool::replace_keep_origin(std::string str, const std::string str_find, const std::string str_change)
{
	return MOONG::StringTool::replace(str, str_find, str_change);
}

const std::vector<std::string> MOONG::StringTool::split(const std::string str, const char delimiter)
{
	std::string delimiters;
	delimiters.push_back(delimiter);

	return MOONG::StringTool::split(str, delimiters);
}

const std::vector<std::string> MOONG::StringTool::split(const std::string str, const std::string delimiters, const bool delimiter_whole_use/* = false*/)
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
			index_temp = str.find(delimiters, index_prev_token);

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
				index_temp = str.find(delimiters.at(i), index_prev_token);

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
			return_value.push_back(str.substr(index_prev_token));

			break;
		}
		else
		{
			return_value.push_back(str.substr(index_prev_token, index_nexe_token - index_prev_token));

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

std::string& MOONG::StringTool::tolower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);

	return str;
}

std::string& MOONG::StringTool::toupper(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);

	return str;
}

std::string MOONG::StringTool::tolower_keep_origin(std::string str)
{
	return MOONG::StringTool::tolower(str);
}

std::string MOONG::StringTool::toupper_keep_origin(std::string str)
{
	return MOONG::StringTool::toupper(str);
}

// 앞에 있는 개행 문자 제거
std::string& MOONG::StringTool::trim_left(std::string& str)
{
	if(str.length() == 0)
	{
		return str;
	}

	size_t index = 0;

	for(size_t i = 0; i < str.length(); i++)
	{
		if(str.at(i) != ' ' && str.at(i) != '\t' && str.at(i) != '\n' && str.at(i) != '\r\n')
		{
			index = i;

			break;
		}
	}

	str.erase(0, index);

	return str;
}
// 뒤에 있는 개행 문자 제거
std::string& MOONG::StringTool::trim_right(std::string& str)
{
	if(str.length() == 0)
	{
		return str;
	}

	size_t index = 0;

	for(size_t i = str.length() - 1; i >= 0; i--)
	{
		if(str.at(i) != ' ' && str.at(i) != '\t' && str.at(i) != '\n' && str.at(i) != '\r\n')
		{
			index = i + 1;

			break;
		}
	}

	str.erase(index);

	return str;
}
// 양쪽 끝의 개행 문자 제거
std::string& MOONG::StringTool::trim(std::string& str)
{
	return trim_left(trim_right(str));
}

// trim from start (copying)
std::string MOONG::StringTool::trim_left_keep_origin(std::string str)
{
	return MOONG::StringTool::trim_left(str);
}
// trim from end (copying)
std::string MOONG::StringTool::trim_right_keep_origin(std::string str)
{
	return MOONG::StringTool::trim_right(str);
}
// trim from both ends (copying)
std::string MOONG::StringTool::trim_keep_origin(std::string str)
{
	return MOONG::StringTool::trim(str);
}

const std::string MOONG::StringTool::_encode_base64(const std::string& str, const bool use_url_encoding_characters/* = false*/)
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

	for (size_t i = 0; i < str.length(); i += 3)
	{
		if ((i + 2) < str.length())
		{
			encoded_str += BASE64_INDEX_TABLE.at((str.at(i) >> 2) & 0x3F);
			encoded_str += BASE64_INDEX_TABLE.at(((str.at(i) & 0x3) << 4) | ((str.at(i + 1) >> 4) & 0xF));
			encoded_str += BASE64_INDEX_TABLE.at(((str.at(i + 1) & 0xF) << 2) | ((str.at(i + 2) >> 6) & 0x3));
			encoded_str += BASE64_INDEX_TABLE.at(str.at(i + 2) & 0x3F);
		}
		else if ((i + 1) < str.length())
		{
			encoded_str += BASE64_INDEX_TABLE.at((str.at(i) >> 2) & 0x3F);
			encoded_str += BASE64_INDEX_TABLE.at(((str.at(i) & 0x3) << 4) | ((str.at(i + 1) >> 4) & 0xF));
#if _MSC_VER > 1200
			encoded_str += BASE64_INDEX_TABLE.at((static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(str.at(i + 1) & 0xF)) << 2);
#else
			encoded_str += BASE64_INDEX_TABLE.at((str.at(i + 1) & 0xF) << 2);
#endif

			encoded_str += MOONG::StringTool::BASE64_PADDING_CHAR;

			break;
		}
		else
		{
			encoded_str += BASE64_INDEX_TABLE.at((str.at(i) >> 2) & 0x3F);
#if _MSC_VER > 1200
			encoded_str += BASE64_INDEX_TABLE.at((static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(str.at(i) & 0x3)) << 4);
#else
			encoded_str += BASE64_INDEX_TABLE.at((str.at(i) & 0x3) << 4);
#endif

			encoded_str += MOONG::StringTool::BASE64_PADDING_CHAR;
			encoded_str += MOONG::StringTool::BASE64_PADDING_CHAR;

			break;
		}
	}

	return encoded_str;
}

const std::string MOONG::StringTool::_decode_base64(const std::string& str, const bool use_url_encoding_characters/* = false*/)
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

	std::string encoded_str = str;
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
