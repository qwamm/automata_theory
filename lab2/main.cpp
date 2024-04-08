#include <iostream>
#include "regex_lib.hpp"
int main()
{
	SRegex *reg = new SRegex("abc");
	std::string s = "ab", s_1 = "ab";
	std::cout << reg->match(s) << "\n";
	//reg->regex_traversal(s_1);
	reg->language_addition();
	//reg->print_capture_groups();
	//std::cout << reg->restore_regex() << "\n";
	delete reg;
}
