// https://github.com/MoongStory/StringTool

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _STRING_TOOL_H_
#define _STRING_TOOL_H_

#include <iostream>
#include <vector>

namespace MOONG
{
	class StringTool
	{
	public:
	protected:
	private:

	public:
		static const int compare(const std::string string1, const std::string string2, bool ignoreCase = false);

		//TODO: format 기능 추가.

		static std::string& remove(std::string& str, const std::string remove_string);
		static std::string remove_keep_origin(std::string str, const std::string remove_string);

		static const std::vector<std::string> split(const std::string str, const std::string delimiters);

		static std::string& tolower(std::string& str);
		static std::string& toupper(std::string& str);

		static std::string tolower_keep_origin(std::string str);
		static std::string toupper_keep_origin(std::string str);

#pragma region C++ 언어 표준 C++17 미만
		static std::string& trim_left(std::string& str);
		static std::string& trim_right(std::string& str);
		static std::string& trim(std::string& str);
#pragma endregion C++ 언어 표준 C++17 미만

#pragma region C++ 언어 표준 C++17 이상
		//static std::string& trim_left(std::string& str);
		//static std::string& trim_right(std::string& str);
		//static std::string& trim(std::string& str);
#pragma endregion C++ 언어 표준 C++17 이상

		static std::string trim_left_keep_origin(std::string str);
		static std::string trim_right_keep_origin(std::string str);
		static std::string trim_keep_origin(std::string str);
	protected:
	private:
	};
}
#endif	// _STRING_TOOL_H_