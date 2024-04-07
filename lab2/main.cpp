#include <iostream>
#include "regex_lib.hpp"
int main()
{
	SRegex *reg = new SRegex("(ab)|(cef)|(o|g|h)");
	std::string s = "ab";
	std::cout << reg->match(s) << "\n";
	reg->print_capture_groups();
	std::cout << reg->restore_regex() << "\n";
	delete reg;
}
