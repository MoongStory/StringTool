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
#pragma region C++ 언어 표준 C++17 미만
		static std::string& ltrim(std::string& s);
		static std::string& rtrim(std::string& s);
		static std::string& trim(std::string& s);
#pragma endregion C++ 언어 표준 C++17 미만

#pragma region C++ 언어 표준 C++17 이상
		//static std::string& ltrim(std::string& s);
		//static std::string& rtrim(std::string& s);
		//static std::string& trim(std::string& s);
#pragma endregion C++ 언어 표준 C++17 이상

		static const std::string ltrim_copy(std::string s);
		static const std::string rtrim_copy(std::string s);
		static const std::string trim_copy(std::string s);
	protected:
	private:
	};
}
#endif	// _STRING_TOOL_H_