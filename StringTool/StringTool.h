// https://github.com/MoongStory/StringTool

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _STRING_TOOL_H_
#define _STRING_TOOL_H_

#include <iostream>

namespace MOONG
{
	class StringTool
	{
	public:
	protected:
	private:

	public:
		static const int compare(const std::string string1, const std::string string2, bool ignoreCase = false);

		static std::string& tolower(std::string& s);
		static std::string& toupper(std::string& s);

		static const std::string tolower_keep_origin(std::string s);
		static const std::string toupper_keep_origin(std::string s);

#pragma region C++ 언어 표준 C++17 미만
		static std::string& trim_left(std::string& s);
		static std::string& trim_right(std::string& s);
		static std::string& trim(std::string& s);
#pragma endregion C++ 언어 표준 C++17 미만

#pragma region C++ 언어 표준 C++17 이상
		//static std::string& trim_left(std::string& s);
		//static std::string& trim_right(std::string& s);
		//static std::string& trim(std::string& s);
#pragma endregion C++ 언어 표준 C++17 이상

		static const std::string trim_left_keep_origin(std::string s);
		static const std::string trim_right_keep_origin(std::string s);
		static const std::string trim_keep_origin(std::string s);
	protected:
	private:
	};
}
#endif	// _STRING_TOOL_H_