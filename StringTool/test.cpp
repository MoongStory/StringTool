#include "StringTool.h"

int main()
{
	std::string temp000 = " a ";
	std::cout << "[" << MOONG::StringTool::ltrim(temp000).c_str() << "]" << std::endl;
	temp000 = " a ";
	std::cout << "[" << MOONG::StringTool::rtrim(temp000).c_str() << "]" << std::endl;
	temp000 = " a ";
	std::cout << "[" << MOONG::StringTool::trim(temp000).c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp000 = " a ";
	std::cout << "[" << MOONG::StringTool::ltrim_copy(temp000).c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::StringTool::rtrim_copy(temp000).c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::StringTool::trim_copy(temp000).c_str() << "]" << std::endl;

	return 0;
}