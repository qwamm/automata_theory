#include <iostream>
#include "regex_lib.hpp"
int main()
{
	std::cout << "Enter REGEX:\n";
	std::string in;
	std::cin >> in;
	SRegex *reg = new SRegex(in);
	std::string s = "aabbcc", s_1 = "cd";
	reg->d->minimize_DFA();
	//std::cout << "MIN_STATES SIZE: " << min_states.size() << "\n";
	/*for (int i = 0; i < min_states.size(); i++)
	{
		std::cout << i + 1 << " STATE SIZE: " << "\t";
		for (int j = 0; j < min_states[i].size(); j++)
		{
			std::cout << min_states[i][j]->s << " ";
		}
		std::cout << "\n";
	}*.
	/*if (reg->match(s))
		std::cout << "MATCHED\n";
	else
		std::cout << "UNMATCHED\n";*/
	//reg->regex_traversal(s_1, in);
	//reg->language_addition();
	//reg->print_capture_groups();
	//std::cout << reg->restore_regex() << "\n";
	//SRegex restore_reg(reg->restore_regex());
	delete reg;
}
