#include <iostream>
#include "regex_lib.hpp"
int main()
{
	SRegex *reg = new SRegex("(abc){4,6}");
	std::string s = "abcabcabcabcabc";
	std::cout << reg->match(s) << "\n";
	delete reg;
}
