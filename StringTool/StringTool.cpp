#include "StringTool.h"

#include <functional>

#pragma region C++ 언어 표준 C++17 미만
// 앞에 있는 개행 문자 제거
std::string& MOONG::StringTool::ltrim(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));

	return s;
}
// 뒤에 있는 개행 문자 제거
std::string& MOONG::StringTool::rtrim(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());

	return s;
}
// 양쪽 끝의 개행 문자 제거
std::string& MOONG::StringTool::trim(std::string& s)
{
	return ltrim(rtrim(s));
}
#pragma endregion C++ 언어 표준 C++17 미만



#pragma region C++ 언어 표준 C++17 이상
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
#pragma endregion C++ 언어 표준 C++17 이상





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