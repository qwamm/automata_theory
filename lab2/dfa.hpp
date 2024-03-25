#include <iostream>
#include "syntax_tree.hpp"

struct State
{
		int s_num;
		std::string s;
		std::vector <State*> to;
		State(std::string _s, int _num)
		{
			s_num = _num;
			s = _s;
		}
};

class DFA
{
	private:
		std::vector<State*> DStates; 
	public:
		DFA() = default;
		~DFA() {}
		void create(std::string &s)
		{
			//creating of abstract syntax tree
        	Syntax_Tree *t = new Syntax_Tree();
        	std::vector<Vertex> v = t->create_ast(s);
			DStates.reserve(t->follow_pos.size());

			//copying vector of states
			for (int i = 0; i < v.size(); i++)
			{
				DStates.push_back(new State(v[i].s, v[i].n));
			}

			//transition definition
			for (int i = 0; i < DStates.size(); i++)
			{
				for (int j = 0; j < t->follow_pos[i].size(); j++)
				{
					DStates[i]->to.push_back(DStates[t->follow_pos[i][j].n - 1]);
				}
			}
			for (int i = 0; i < DStates.size(); i++)
			{
				std::cout << i+1 << " DFA STATE: ";
				for (int j = 0; j < DStates[i]->to.size(); j++)
				{
					std::cout << DStates[i]->to[j]->s_num << " " << DStates[i]->to[j]->s;
					if (j < DStates[i]->to.size())
						std::cout << ", ";
				}
				std::cout << "\n";
			}
		}
};
