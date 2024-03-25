#include <iostream>
#include "dfa.hpp"
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
	DFA *t = new DFA();
	std::string s = "ABF(G|H)";
	t->create(s);
	//delete t;
	//std::cout << t->root->data->value() << "\n";
	//t->putTree(t->root, 0);
}
