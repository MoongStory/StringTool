#include "StringTool.h"

#include <functional>
#include <algorithm>	// std::transform ����� ���� �ʿ�.

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

#pragma region C++ ��� ǥ�� C++17 �̸�
// �տ� �ִ� ���� ���� ����
std::string& MOONG::StringTool::trim_left(std::string& str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));

	return str;
}
// �ڿ� �ִ� ���� ���� ����
std::string& MOONG::StringTool::trim_right(std::string& str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());

	return str;
}
// ���� ���� ���� ���� ����
std::string& MOONG::StringTool::trim(std::string& str)
{
	return trim_left(trim_right(str));
}
#pragma endregion C++ ��� ǥ�� C++17 �̸�



#pragma region C++ ��� ǥ�� C++17 �̻�
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
#pragma endregion C++ ��� ǥ�� C++17 �̻�





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
