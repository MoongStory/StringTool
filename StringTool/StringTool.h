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
		static const unsigned int max_buf_size_;

	public:
		static const int compare(const std::string string1, const std::string string2, const bool ignoreCase = false);

		static const std::string CutTail(std::string str, const char delimiter);
		// TODO: static const std::string CutTail(std::string str, const std::string delimiters, const bool delimiter_whole_use = false); ��� �߰�
		// TODO: PopTail ��� �߰�.
		// TDOO: CutHead ��� �߰�.
		// TODO: PopHead ��� �߰�.

		static std::string format(const std::string format, ...);

		static std::string& remove(std::string& str, const std::string remove_string);
		static std::string remove_keep_origin(std::string str, const std::string remove_string);

		static std::string& replace(std::string& str, const std::string str_find, const std::string str_change);
		static std::string replace_keep_origin(std::string str, const std::string str_find, const std::string str_change);

		static const std::vector<std::string> split(const std::string str, const char delimiter);
		static const std::vector<std::string> split(const std::string str, const std::string delimiters, const bool delimiter_whole_use = false);

		static std::string& tolower(std::string& str);
		static std::string& toupper(std::string& str);

		static std::string tolower_keep_origin(std::string str);
		static std::string toupper_keep_origin(std::string str);

//#pragma region C++ ��� ǥ�� C++17 �̸�
		static std::string& trim_left(std::string& str);
		static std::string& trim_right(std::string& str);
		static std::string& trim(std::string& str);
//#pragma endregion C++ ��� ǥ�� C++17 �̸�

//#pragma region C++ ��� ǥ�� C++17 �̻�
		//static std::string& trim_left(std::string& str);
		//static std::string& trim_right(std::string& str);
		//static std::string& trim(std::string& str);
//#pragma endregion C++ ��� ǥ�� C++17 �̻�

		static std::string trim_left_keep_origin(std::string str);
		static std::string trim_right_keep_origin(std::string str);
		static std::string trim_keep_origin(std::string str);
	protected:
	private:
	};
}
#endif	// _STRING_TOOL_H_