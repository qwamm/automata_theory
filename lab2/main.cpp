#include <iostream>
#include "regex_lib.hpp"
int main()
{
	/*std::string regex;
	std::cout << "Enter regular expression:\n";
	std::cin >> regex;
	SRegex reg(regex);
	SMatch m;
	while (!cin.eof())
	{
		std::string s;
		std::cin >> s;
		reg.match(s);
	}*/
	SRegex *reg = new SRegex("(A|B)D+H");
	std::cout << reg->match("BDODDH") << "\n";
	delete reg;
	//delete t;
	//std::cout << t->root->data->value() << "\n";
	//t->putTree(t->root, 0);
}
