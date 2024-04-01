#include <iostream>
#include "regex_lib.hpp"
int main()
{
	SRegex *reg = new SRegex("a{1,2}");
	std::string s = "aa";
	std::cout << reg->match(s) << "\n";
	delete reg;
}
