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

std::string& MOONG::StringTool::tolower(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	return s;
}

std::string& MOONG::StringTool::toupper(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);

	return s;
}

const std::string MOONG::StringTool::tolower_keep_origin(std::string s)
{
	return MOONG::StringTool::tolower(s);
}

const std::string MOONG::StringTool::toupper_keep_origin(std::string s)
{
	return MOONG::StringTool::toupper(s);
}

#pragma region C++ ��� ǥ�� C++17 �̸�
// �տ� �ִ� ���� ���� ����
std::string& MOONG::StringTool::trim_left(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));

	return s;
}
// �ڿ� �ִ� ���� ���� ����
std::string& MOONG::StringTool::trim_right(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());

	return s;
}
// ���� ���� ���� ���� ����
std::string& MOONG::StringTool::trim(std::string& s)
{
	return trim_left(trim_right(s));
}
#pragma endregion C++ ��� ǥ�� C++17 �̸�



#pragma region C++ ��� ǥ�� C++17 �̻�
//// trim from start (in place)
//std::string& MOONG::StringTool::trim_left(std::string& s)
//{
//	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
//		return !std::isspace(ch);
//		}));
//
//	return s;
//}
//// trim from end (in place)
//std::string& MOONG::StringTool::trim_right(std::string& s)
//{
//	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
//		return !std::isspace(ch);
//		}).base(), s.end());
//
//	return s;
//}
//// trim from both ends (in place)
//std::string& MOONG::StringTool::trim(std::string& s)
//{
//	return ltrim(rtrim(s));
//}
#pragma endregion C++ ��� ǥ�� C++17 �̻�





// trim from start (copying)
const std::string MOONG::StringTool::trim_left_keep_origin(std::string s)
{
	return MOONG::StringTool::trim_left(s);
}
// trim from end (copying)
const std::string MOONG::StringTool::trim_right_keep_origin(std::string s)
{
	return MOONG::StringTool::trim_right(s);
}
// trim from both ends (copying)
const std::string MOONG::StringTool::trim_keep_origin(std::string s)
{
	return MOONG::StringTool::trim(s);
}
