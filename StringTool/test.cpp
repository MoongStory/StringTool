#include "StringTool.h"

int main()
{
	std::string temp_string;
	char delimiter = NULL;
	std::string delimiters = "";

	std::cout << "compare same\n\t[" << MOONG::StringTool::compare("a", "a") << "]" << std::endl;
	std::cout << "compare different case\n\t[" << MOONG::StringTool::compare("a", "A") << "]" << std::endl;
	std::cout << "compare first\n\t[" << MOONG::StringTool::compare("a", "z") << "]" << std::endl;
	std::cout << "compare second\n\t[" << MOONG::StringTool::compare("z", "a") << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "compare ignore case same\n\t[" << MOONG::StringTool::compare("a", "A", true) << "]" << std::endl;
	std::cout << "compare ignore case first\n\t[" << MOONG::StringTool::compare("A", "z", true) << "]" << std::endl;
	std::cout << "compare ignore case second\n\t[" << MOONG::StringTool::compare("Z", "a", true) << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "C:\\Program Files (x86)\\Microsoft Visual Studio" << std::endl;
	for (size_t i = 0; i < temp_string.length(); i++)
	{
		std::cout << i % 10;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	delimiter = '\\';
	delimiters = "Visual";
	std::cout << "FindIndexRightmost 구분자[" << delimiter << "] 사용\n\t인덱스[" << MOONG::StringTool::FindIndexRightmost(temp_string, delimiter) << "]" << std::endl;
	std::cout << "FindIndexRightmost 구분자[" << delimiters << "] 사용\n\t인덱스[" << MOONG::StringTool::FindIndexRightmost(temp_string, delimiters) << "]" << std::endl;
	std::cout << "FindIndexRightmost 구분자[" << delimiters << "] 전체를 하나의 구분자로 사용\n\t인덱스[" << MOONG::StringTool::FindIndexRightmost(temp_string, delimiters, true) << "]" << std::endl;

	delimiters = "VisualA";
	if (MOONG::StringTool::FindIndexRightmost(temp_string, delimiters, true) == std::string::npos)
	{
		std::cout << "FindIndexRightmost 구분자[" << delimiters << "] 전체를 하나의 구분자로 사용\n\t[못찾음]" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "cut_right[" << temp_string << "]" << std::endl;
	std::cout << "cut_right 구분자[" << delimiter << "] 사용\n\t결과[" << MOONG::StringTool::cut_right(temp_string, delimiter).c_str() << "]" << std::endl;
	std::cout << "cut_right[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "cut_right_keep_origin[" << temp_string << "]" << std::endl;
	std::cout << "cut_right_keep_origin 구분자[" << delimiter << "] 사용\n\t결과[" << MOONG::StringTool::cut_right_keep_origin(temp_string, delimiter).c_str() << "]" << std::endl;
	std::cout << "cut_right_keep_origin[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	delimiters = "Microsoft";
	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "cut_right[" << temp_string << "]" << std::endl;
	std::cout << "cut_right 구분자[" << delimiters << "] 사용\n\t결과[" << MOONG::StringTool::cut_right(temp_string, delimiters).c_str() << "]" << std::endl;
	std::cout << "cut_right[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "cut_right_keep_origin[" << temp_string << "]" << std::endl;
	std::cout << "cut_right_keep_origin 구분자[" << delimiters << "] 사용\n\t결과[" << MOONG::StringTool::cut_right_keep_origin(temp_string, delimiters).c_str() << "]" << std::endl;
	std::cout << "cut_right_keep_origin[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "cut_right[" << temp_string << "]" << std::endl;
	std::cout << "cut_right 구분자[" << delimiters << "] 전체를 하나의 구분자로 사용\n\t결과[" << MOONG::StringTool::cut_right(temp_string, delimiters, true).c_str() << "]" << std::endl;
	std::cout << "cut_right[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "cut_right[" << temp_string << "]" << std::endl;
	std::cout << "cut_right 구분자[" << delimiters << "] 전체를 하나의 구분자로 사용\n\t결과[" << MOONG::StringTool::cut_right(temp_string, delimiters, true).c_str() << "]" << std::endl;
	std::cout << "cut_right[" << temp_string << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiters << "] 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiters).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiters << "] 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiters).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiters << "] 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiters).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiters << "] 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiters).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	delimiters = "Studio";
	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio Studio";
	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiters << "] 전체를 하나의 구분자로 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiters, true).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiters << "] 전체를 하나의 구분자로 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiters, true).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiters << "] 전체를 하나의 구분자로 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiters, true).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	delimiter = 'o';
	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiter << "] 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiter).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	delimiter = '\\';
	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiter << "] 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiter).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	delimiter = 'C';
	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailPop[" << temp_string << "]" << std::endl;
	std::cout << "TailPop 구분자[" << delimiter << "] 사용\n\t결과[" << MOONG::StringTool::TailPop(temp_string, delimiter).c_str() << "]" << std::endl;
	std::cout << "TailPop[" << temp_string << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	delimiters = "Visual";
	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailPop_keep_origin[" << temp_string << "]" << std::endl;
	std::cout << "TailPop_keep_origin 구분자[" << delimiters << "] 사용\n\t결과[" << MOONG::StringTool::TailPop_keep_origin(temp_string, delimiters).c_str() << "]" << std::endl;
	std::cout << "TailPop_keep_origin[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "TailPop_keep_origin[" << temp_string << "]" << std::endl;
	std::cout << "TailPop_keep_origin 구분자[" << delimiters << "] 전체를 하나의 구분자로 사용\n\t결과[" << MOONG::StringTool::TailPop_keep_origin(temp_string, delimiters, true).c_str() << "]" << std::endl;
	std::cout << "TailPop_keep_origin[" << temp_string << "]" << std::endl;

	std::cout << std::endl;

	delimiter = '\\';
	temp_string = "C:\\Program Files (x86)\\Microsoft Visual Studio";
	std::cout << "TailPop_keep_origin[" << temp_string << "]" << std::endl;
	std::cout << "TailPop_keep_origin 구분자[" << delimiter << "] 사용\n\t결과[" << MOONG::StringTool::TailPop_keep_origin(temp_string, delimiter).c_str() << "]" << std::endl;
	std::cout << "TailPop_keep_origin[" << temp_string << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "format\n\t[" << MOONG::StringTool::format("%d, %.2lf, %s, %4c", 3, 3.2345, "string 문자열", 'A').c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::string remove_target_string = "cd";
	temp_string = "abcd abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "remove, remove_target_string[" << remove_target_string << "]\n\t결과[" << MOONG::StringTool::remove(temp_string, remove_target_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "remove one char\n\t[" << MOONG::StringTool::remove(temp_string, "a").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "remove do not match\n\t[" << MOONG::StringTool::remove(temp_string, "ba").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "remove keep origin\n\t[" << MOONG::StringTool::remove_keep_origin(temp_string, "cd").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "abcd/|/abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "replace\n\t[" << MOONG::StringTool::replace(temp_string, "/|/", "/").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "abcd/|/abcd";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "replace keep origin\n\t[" << MOONG::StringTool::replace_keep_origin(temp_string, "/|/", "/").c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "a,bc|/|cde.f  gs|/||/|fu.sd";
	std::cout << "split delimiters" << std::endl;
	std::vector<std::string> after_parse = MOONG::StringTool::split(temp_string, "|/|");
	for (size_t i  = 0; i < after_parse.size(); i++)
	{
		std::cout << "split\n\t[" << after_parse.at(i).c_str() << "]" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "a,bc|/|cde.f  gs|/||/|fu.sd";
	std::cout << "split delimiter whole" << std::endl;
	after_parse = MOONG::StringTool::split(temp_string, "|/|", true);
	for (size_t i  = 0; i < after_parse.size(); i++)
	{
		std::cout << "split\n\t[" << after_parse.at(i).c_str() << "]" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = "a,bc|/|cde.f  gs|/||/|fu.sd";
	std::cout << "split delimiter" << std::endl;
	after_parse = MOONG::StringTool::split(temp_string, '.');
	for (size_t i  = 0; i < after_parse.size(); i++)
	{
		std::cout << "split\n\t[" << after_parse.at(i).c_str() << "]" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	temp_string = "UPPER CASE";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "tolower\n\t[" << MOONG::StringTool::tolower(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "lower case";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "toupper\n\t[" << MOONG::StringTool::toupper(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "UPPER CASE";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "tolower keep origin\n\t[" << MOONG::StringTool::tolower_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "lower case";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "toupper keep origin\n\t[" << MOONG::StringTool::toupper_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	temp_string = " \na\n	 ";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "trim_left\n\t[" << MOONG::StringTool::trim_left(temp_string).c_str() << "]" << std::endl;
	std::cout << "trim_right\n\t[" << MOONG::StringTool::trim_right(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "		\na ";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "trim\n\t[" << MOONG::StringTool::trim(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = " a		";
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;
	std::cout << "trim_left_keep_origin\n\t[" << MOONG::StringTool::trim_left_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "trim_right_keep_origin\n\t[" << MOONG::StringTool::trim_right_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "trim_keep_origin\n\t[" << MOONG::StringTool::trim_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string [" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;

	temp_string = "";
	std::cout << "temp_string[" << temp_string.c_str() << "]" << std::endl;
	std::cout << "trim. 빈 문자열일 경우 오류 발생 여부 확인\n\t[" << MOONG::StringTool::trim_keep_origin(temp_string).c_str() << "]" << std::endl;
	std::cout << "temp_string[" << temp_string.c_str() << "]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}