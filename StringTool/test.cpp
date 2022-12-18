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

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailCut before[" << temp_string << "]" << std::endl;
	std::cout << "TailCut [" << MOONG::StringTool::TailCut(temp_string, '\\').c_str() << "]" << std::endl;
	std::cout << "TailCut after[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailCut_keep_origin before[" << temp_string << "]" << std::endl;
	std::cout << "TailCut_keep_origin [" << MOONG::StringTool::TailCut_keep_origin(temp_string, '\\').c_str() << "]" << std::endl;
	std::cout << "TailCut_keep_origin after[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailCut before[" << temp_string << "]" << std::endl;
	std::cout << "TailCut [" << MOONG::StringTool::TailCut(temp_string, std::string(":\\ ")).c_str() << "]" << std::endl;
	std::cout << "TailCut after[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailCut_keep_origin before[" << temp_string << "]" << std::endl;
	std::cout << "TailCut_keep_origin [" << MOONG::StringTool::TailCut_keep_origin(temp_string, std::string(":\\ ")).c_str() << "]" << std::endl;
	std::cout << "TailCut_keep_origin after[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailCut before[" << temp_string << "]" << std::endl;
	std::cout << "TailCut [" << MOONG::StringTool::TailCut(temp_string, std::string("(x86)"), true).c_str() << "]" << std::endl;
	std::cout << "TailCut after[" << temp_string << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "format [" << MOONG::StringTool::format("%d, %.2lf, %s, %4c", 3, 3.2345, "string ¹®ÀÚ¿­", 'A').c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "remove [" << MOONG::StringTool::remove(temp_string, "cd").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "remove one char[" << MOONG::StringTool::remove(temp_string, "a").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "remove do not match[" << MOONG::StringTool::remove(temp_string, "ba").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "remove keep origin[" << MOONG::StringTool::remove_keep_origin(temp_string, "cd").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "abcd/|/abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "replace[" << MOONG::StringTool::replace(temp_string, "/|/", "/").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd/|/abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "replace keep origin[" << MOONG::StringTool::replace_keep_origin(temp_string, "/|/", "/").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "a,bc|/|cde.f  gs|/||/|fu.sd";
	std::cout << "split delimiters" << std::endl;
	std::vector<std::string> after_parse = MOONG::StringTool::split(temp_string, "|/|");
	for (size_t i  = 0; i < after_parse.size(); i++)
	{
		std::cout << "split[" << after_parse.at(i).c_str() << "]" << std::endl;
	}

	std::cout << std::endl;

	temp_string = "a,bc|/|cde.f  gs|/||/|fu.sd";
	std::cout << "split delimiter whole" << std::endl;
	after_parse = MOONG::StringTool::split(temp_string, "|/|", true);
	for (size_t i  = 0; i < after_parse.size(); i++)
	{
		std::cout << "split[" << after_parse.at(i).c_str() << "]" << std::endl;
	}

	std::cout << std::endl;

	temp_string = "a,bc|/|cde.f  gs|/||/|fu.sd";
	std::cout << "split delimiter" << std::endl;
	after_parse = MOONG::StringTool::split(temp_string, '.');
	for (size_t i  = 0; i < after_parse.size(); i++)
	{
		std::cout << "split[" << after_parse.at(i).c_str() << "]" << std::endl;
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

	temp_string = " \na\n	 ";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "trim_left [" << MOONG::StringTool::trim_left(temp_string).c_str() << "]" << std::endl;
	std::cout << "trim_right [" << MOONG::StringTool::trim_right(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	temp_string = "		\na ";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "trim [" << MOONG::StringTool::trim(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = " a		";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "trim_left_keep_origin [" << MOONG::StringTool::trim_left_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "trim_right_keep_origin [" << MOONG::StringTool::trim_right_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "trim_keep_origin [" << MOONG::StringTool::trim_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "trim [" << MOONG::StringTool::trim_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}