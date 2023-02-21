// https://github.com/MoongStory/StringTool

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _STRING_TOOL_H_
#define _STRING_TOOL_H_

#include <iostream>
#include <vector>

#if _MSC_VER <= 1200
	// Visual Studio 6.0에서만 발생.
	#pragma warning(disable: 4786) // identifier was truncated to '255' characters in the browser information.
#endif

namespace MOONG
{
	class StringTool
	{
	public:
	protected:
	private:
		static const unsigned int max_buf_size_;
		static const char BASE64_PADDING_CHAR;

	public:
		static const int compare(const std::string input1, const std::string input2, const bool ignoreCase = false);

		static const std::string encode_base64(const std::string& input);
		static const std::string decode_base64(const std::string& input);

		static const std::string encode_base64_url(const std::string& input);
		static const std::string decode_base64_url(const std::string& input);

		static const size_t find_index_rightmost(const std::string input, const char delimiter);
		static const size_t find_index_rightmost(const std::string input, const std::string delimiters, const bool delimiter_whole_use = false);

		static const size_t find_index_leftmost(const std::string input, const char delimiter);
		static const size_t find_index_leftmost(const std::string input, const std::string delimiters, const bool delimiter_whole_use = false);

		static const std::string& cut_right(std::string& input, const char delimiter);
		static const std::string cut_right_keep_origin(std::string input, const char delimiter);
		static const std::string& cut_right(std::string& input, const std::string delimiters, const bool delimiter_whole_use = false);
		static const std::string cut_right_keep_origin(std::string input, const std::string delimiters, const bool delimiter_whole_use = false);

		static const std::string pop_right(std::string& input, const char delimiter);
		static const std::string pop_right_keep_origin(std::string input, const char delimiter);
		static const std::string pop_right(std::string& input, const std::string delimiters, const bool delimiter_whole_use = false);
		static const std::string pop_right_keep_origin(std::string input, const std::string delimiters, const bool delimiter_whole_use = false);

		static const std::string& cut_left(std::string& input, const char delimiter);
		static const std::string cut_left_keep_origin(std::string input, const char delimiter);
		static const std::string& cut_left(std::string& input, const std::string delimiters, const bool delimiter_whole_use = false);
		static const std::string cut_left_keep_origin(std::string input, const std::string delimiters, const bool delimiter_whole_use = false);

		static const std::string pop_left(std::string& input, const char delimiter);
		static const std::string pop_left_keep_origin(std::string input, const char delimiter);
		static const std::string pop_left(std::string& input, const std::string delimiters, const bool delimiter_whole_use = false);
		static const std::string pop_left_keep_origin(std::string input, const std::string delimiters, const bool delimiter_whole_use = false);

		static std::string format(const std::string format, ...);

		static std::string& remove(std::string& input, const char remove_char);
		static std::string& remove(std::string& input, const std::string remove_string);
		static std::string remove_keep_origin(std::string input, const std::string remove_string);

		static std::string& replace(std::string& string_original, const std::string string_find, const std::string string_change);
		static std::string replace_keep_origin(std::string string_original, const std::string string_find, const std::string string_change);

		static const std::vector<std::string> split(const std::string input, const char delimiter);
		static const std::vector<std::string> split(const std::string input, const std::string delimiters, const bool delimiter_whole_use = false);

		static std::string& tolower(std::string& input);
		static std::string& toupper(std::string& input);

		static std::string tolower_keep_origin(std::string input);
		static std::string toupper_keep_origin(std::string input);

		static std::string& trim_left(std::string& input);
		static std::string& trim_right(std::string& input);
		static std::string& trim(std::string& input);

		static std::string trim_left_keep_origin(std::string input);
		static std::string trim_right_keep_origin(std::string input);
		static std::string trim_keep_origin(std::string input);
	protected:
	private:
		// https://en.wikipedia.org/wiki/Base64
		static const std::string _encode_base64(const std::string& input, const bool use_url_encoding_characters = false);
		static const std::string _decode_base64(const std::string& input, const bool use_url_encoding_characters = false);
	};
}
#endif	// _STRING_TOOL_H_