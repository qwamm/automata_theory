#include <iostream>
#include <unordered_map>
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
		std::vector <State*> StartStates;
		std::vector <State*> EndStates;
		std::unordered_map<int, std::string> capture_groups;
		DFA() = default;
		~DFA()
		{
			for (int i = 0 ; i < DStates.size(); i++)
			{
				delete DStates[i];
			}
		}

		void automata_product(DFA *d_1, DFA *d_2)
		{
                        std::vector <State*> DStates_1 = d_1->getDStates(), DStates_2 = d_2->getDStates(), DStates_3;
			int num = 1;
			if (DStates_1.size() > DStates_2.size())
			{
                        	for (int i = 0; i < DStates_1.size(); i++)
                        	{
					for (int j = 0; j < DStates_2.size(); j++)
					{
						DStates_3.push_back(new State(DStates_1[i]->s + DStates_2[j]->s,
						num++));
					}
                        	}
			}
		}

		std::vector<State*> getDStates()
		{
			return DStates;
		}

		//Передавать константные ссылки на строки
		void create(std::string &s)
		{
			//creating of abstract syntax tree
        		Syntax_Tree *t = new Syntax_Tree();
        		std::vector<Vertex> v = t->create_ast(s);
			capture_groups = t->capture_groups;
			DStates.reserve(t->follow_pos.size());

			//copying vector of states
			for (int i = 0; i < v.size(); i++)
			{
				State *cur_state = new State(v[i].s, v[i].n);
				for (int j = 0; j < t->root->f.size(); j++)
				{
					if (t->root->f[j].n == v[i].n && t->root->f[j].s == v[i].s)
					{
							StartStates.push_back(cur_state);
					}
				}
                                for (int j = 0; j < t->root->l.size(); j++)
                                {
                                        if (t->root->l[j].n == v[i].n && t->root->l[j].s == v[i].s)
                                        {
                                                        EndStates.push_back(cur_state);
                                        }
                                }
				DStates.push_back(cur_state);
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
			delete t;
		}
};
