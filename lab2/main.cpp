#include <iostream>
#include "regex_lib.hpp"

int main()
{
	std::string regex;
	std::cout << "Enter regular expression:\n";
	std::cin >> regex;
	SRegex reg(regex);
	SMatch m;
	while (!cin.eof())
	{
		std::string s;
		std::cin >> s;
		reg.match(s);
	}
}
