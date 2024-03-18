#include <iostream>
//#include "regex_lib.hpp"
#include "syntax_tree.hpp"
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
	Syntax_Tree *t = new Syntax_Tree();
	std::string s = "ABC|D";
	//std::cout << t->root->data->value() << "\n";
	t->create_ast(s);
	t->putTree(t->root, 0);
}
