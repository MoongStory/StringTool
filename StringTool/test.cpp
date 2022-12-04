#include "StringTool.h"

int main()
{
	std::string temp_string;

	std::cout << "compare same [" << MOONG::StringTool::compare("a", "a") << "]" << std::endl;
	std::cout << "compare different case [" << MOONG::StringTool::compare("a", "A") << "]" << std::endl;
	std::cout << "compare first [" << MOONG::StringTool::compare("a", "z") << "]" << std::endl;
	std::cout << "compare second [" << MOONG::StringTool::compare("z", "a") << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "compare ignore case same [" << MOONG::StringTool::compare("a", "A", true) << "]" << std::endl;
	std::cout << "compare ignore case first [" << MOONG::StringTool::compare("A", "z", true) << "]" << std::endl;
	std::cout << "compare ignore case second [" << MOONG::StringTool::compare("Z", "a", true) << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "remove [" << MOONG::StringTool::remove(temp_string, "cd") << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "remove one char[" << MOONG::StringTool::remove(temp_string, "a") << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "remove do not match[" << MOONG::StringTool::remove(temp_string, "ba") << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "remove keep origin[" << MOONG::StringTool::remove_keep_origin(temp_string, "cd") << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "a,bc..cde.f";
	std::vector<std::string> after_parse = MOONG::StringTool::split(temp_string, ",.");
	for (size_t i  = 0; i < after_parse.size(); i++)
	{
		std::cout << "split[" << after_parse.at(i) << "]" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	temp_string = "UPPER CASE";
	std::cout << "tolower [" << MOONG::StringTool::tolower(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "lower case";
	std::cout << "toupper [" << MOONG::StringTool::toupper(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "UPPER CASE";
	std::cout << "tolower keep origin[" << MOONG::StringTool::tolower_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "lower case";
	std::cout << "toupper keep origin [" << MOONG::StringTool::toupper_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = " a ";
	std::cout << "ltrim [" << MOONG::StringTool::trim_left(temp_string).c_str() << "]" << std::endl;
	std::cout << "rtrim [" << MOONG::StringTool::trim_right(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	temp_string = " a ";
	std::cout << "trim [" << MOONG::StringTool::trim(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = " a ";
	std::cout << "ltrim [" << MOONG::StringTool::trim_left_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "rtrim [" << MOONG::StringTool::trim_right_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "trim [" << MOONG::StringTool::trim_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}