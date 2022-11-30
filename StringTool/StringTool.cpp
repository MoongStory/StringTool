#include "StringTool.h"

#include <functional>

#pragma region C++ ��� ǥ�� C++17 �̸�
// �տ� �ִ� ���� ���� ����
std::string& MOONG::StringTool::ltrim(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));

	return s;
}
// �ڿ� �ִ� ���� ���� ����
std::string& MOONG::StringTool::rtrim(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());

	return s;
}
// ���� ���� ���� ���� ����
std::string& MOONG::StringTool::trim(std::string& s)
{
	return ltrim(rtrim(s));
}
#pragma endregion C++ ��� ǥ�� C++17 �̸�



#pragma region C++ ��� ǥ�� C++17 �̻�
//// trim from start (in place)
//std::string& MOONG::StringTool::ltrim(std::string& s)
//{
//	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
//		return !std::isspace(ch);
//		}));
//
//	return s;
//}
//// trim from end (in place)
//std::string& MOONG::StringTool::rtrim(std::string& s)
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
std::string MOONG::StringTool::ltrim_copy(std::string s)
{
	return MOONG::StringTool::ltrim(s);
}
// trim from end (copying)
std::string MOONG::StringTool::rtrim_copy(std::string s)
{
	return MOONG::StringTool::rtrim(s);
}
// trim from both ends (copying)
std::string MOONG::StringTool::trim_copy(std::string s)
{
	return MOONG::StringTool::trim(s);
}