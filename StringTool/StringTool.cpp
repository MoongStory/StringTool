#include "StringTool.h"

#include <functional>
#include <algorithm>	// std::transform 사용을 위해 필요.

#include <windows.h>
#include <strsafe.h>

const unsigned int MOONG::StringTool::max_buf_size_ = 2048;

const int MOONG::StringTool::compare(const std::string string1, const std::string string2, bool ignoreCase)
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

std::string MOONG::StringTool::format(const std::string format, ...)
{
	char build_string[MOONG::StringTool::max_buf_size_] = { 0 };

	va_list arg_ptr;

	va_start(arg_ptr, format);
	
	StringCchVPrintfA(build_string, MOONG::StringTool::max_buf_size_, format.c_str(), arg_ptr);

	va_end(arg_ptr);

	return std::string(build_string);
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

const std::vector<std::string> MOONG::StringTool::split(const std::string str, const std::string delimiters)
{
	size_t index_temp = 0;
	size_t index_nexe_token = INT32_MAX;
	size_t index_prev_token = 0;
	bool is_find_token = false;

	std::vector<std::string> return_value;

	for (;;)
	{
		is_find_token = false;

		for (int i = 0; i < delimiters.length(); i++)
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

		if (is_find_token == false)
		{
			return_value.push_back(str.substr(index_prev_token));

			break;
		}
		else
		{
			return_value.push_back(str.substr(index_prev_token, index_nexe_token - index_prev_token));

			index_prev_token = index_nexe_token + 1;
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

#pragma region C++ 언어 표준 C++17 미만
// 앞에 있는 개행 문자 제거
std::string& MOONG::StringTool::trim_left(std::string& str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));

	return str;
}
// 뒤에 있는 개행 문자 제거
std::string& MOONG::StringTool::trim_right(std::string& str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());

	return str;
}
// 양쪽 끝의 개행 문자 제거
std::string& MOONG::StringTool::trim(std::string& str)
{
	return trim_left(trim_right(str));
}
#pragma endregion C++ 언어 표준 C++17 미만



#pragma region C++ 언어 표준 C++17 이상
//// trim from start (in place)
//std::string& MOONG::StringTool::trim_left(std::string& str)
//{
//	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
//		return !std::isspace(ch);
//		}));
//
//	return str;
//}
//// trim from end (in place)
//std::string& MOONG::StringTool::trim_right(std::string& str)
//{
//	str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
//		return !std::isspace(ch);
//		}).base(), str.end());
//
//	return str;
//}
//// trim from both ends (in place)
//std::string& MOONG::StringTool::trim(std::string& str)
//{
//	return ltrim(rtrim(str));
//}
#pragma endregion C++ 언어 표준 C++17 이상





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
