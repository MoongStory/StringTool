#include "StringTool.h"

int main()
{
	std::string temp000 = " a ";
	std::cout << "ltrim [" << MOONG::StringTool::ltrim(temp000).c_str() << "]" << std::endl;
	temp000 = " a ";
	std::cout << "rtrim [" << MOONG::StringTool::rtrim(temp000).c_str() << "]" << std::endl;
	temp000 = " a ";
	std::cout << "trim [" << MOONG::StringTool::trim(temp000).c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp000 = " a ";
	std::cout << "ltrim [" << MOONG::StringTool::ltrim_copy(temp000).c_str() << "]" << std::endl;
	std::cout << "rtrim [" << MOONG::StringTool::rtrim_copy(temp000).c_str() << "]" << std::endl;
	std::cout << "trim [" << MOONG::StringTool::trim_copy(temp000).c_str() << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "compare same [" << MOONG::StringTool::compare("a", "a") << "]" << std::endl;
	std::cout << "compare different case [" << MOONG::StringTool::compare("a", "A") << "]" << std::endl;
	std::cout << "compare first [" << MOONG::StringTool::compare("a", "z") << "]" << std::endl;
	std::cout << "compare second [" << MOONG::StringTool::compare("z", "a") << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "compare ignore case same [" << MOONG::StringTool::compare("a", "A", true) << "]" << std::endl;
	std::cout << "compare ignore case first [" << MOONG::StringTool::compare("A", "z", true) << "]" << std::endl;
	std::cout << "compare ignore case second [" << MOONG::StringTool::compare("Z", "a", true) << "]" << std::endl;

	return 0;
}