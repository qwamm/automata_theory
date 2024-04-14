#include <iostream>
#include <utility>
#include <vector>
#include <queue>
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
			//states definition
                        for (int i = 0; i < DStates_1.size(); i++)
                        {
				for (int j = 0; j < DStates_2.size(); j++)
				{
					DStates_3.push_back(new State(DStates_1[i]->s + DStates_2[j]->s,
					num++));
				}
                        }

			//transition definition
                        for (int i = 0; i < DStates_1.size(); i++)
                        {
                                for (int j = 0; j < DStates_2.size(); j++)
                                {
                                         if(DStates_1[i]->to.size() == 0)
                                         {
						for (int t = 0; t < DStates_2[j]->to.size(); t++)
						{
                                                    for (int h = 0; h < DStates_3.size(); h++)
                                                    {
                                                                if (DStates_3[h]->s[1] == DStates_2[j]->to[t]->s[0])
                                                                {
                                                                        DStates_3[j + DStates_2.size()*i]->to.push_back(DStates_3[h]);
                                                                }
                                                    }
						}
                                         }
                                        for (int k = 0; k < DStates_1[i]->to.size(); k++)
					{
						if(DStates_2[j]->to.size() == 0)
						{
							for (int h = 0; h < DStates_3.size(); h++)
                                                        {
                                                                if (DStates_3[h]->s[0] == DStates_1[i]->to[k]->s[0])
                                                                {
                                                                        DStates_3[j + DStates_2.size()*i]->to.push_back(DStates_3[h]);
                                                                }
                                                        }
						}
						for (int t = 0; t < DStates_2[j]->to.size(); t++)
						{
							for (int h = 0; h < DStates_3.size(); h++)
							{
								if (DStates_3[h]->s == DStates_1[i]->to[k]->s + DStates_2[j]->to[t]->s)
								{
									DStates_3[j + DStates_2.size()*i]->to.push_back(DStates_3[h]);
								}
							}
						}
					}
                                }
                        }
			for (int i = 0; i < DStates_3.size(); i++)
			{
				std::cout << i+1 << ": " << DStates_3[i]->s << "\n";
			}
			//printing dfa states
                        for (int i = 0; i < DStates_3.size(); i++)
                        {
                                std::cout << i+1 << " TRAVERSAL_DFA STATE: ";
                                for (int j = 0; j < DStates_3[i]->to.size(); j++)
                                {
                                        std::cout << DStates_3[i]->to[j]->s_num << " " << DStates_3[i]->to[j]->s;
                                        if (j < DStates_3[i]->to.size())
                                                std::cout << ", ";
                                }
                                std::cout << "\n";
                        }
		}

		std::vector<State*> getDStates()
		{
			return DStates;
		}

		std::pair<std::vector<State*>, std::vector<State*>> split(std::vector<State*> &R,
		 std::string c, std::vector<State*> &splitter)
		{
			std::vector<State*> R1, R2;
			for (int i = 0; i < R.size(); i++)
			{
				bool flag = false;
				for (int j = 0; j < R[i]->to.size(); j++)
				{
					flag = true;
					for (int k = 0; k < splitter.size(); k++)
					{
						if (R[i]->to[j]->s == c && R[i]->to[j] != splitter[k])
						{
							flag = false;
							break;
						}
					}
					if (!flag)
						break;
				}
				if(flag)
					R1.push_back(R[i]);
				else
					R2.push_back(R[i]);
			}
			return std::make_pair(R1, R2);
		}

		//Минимизация ДКА
		std::vector<std::vector<State*>> minimize()
		{
			std::vector<std::vector<State*>> classes;
			std::vector<State*> terminal_states, not_terminal_states;
			std::queue< std::pair < std::string , std::vector<State*> > > S;
			for (int i = 0; i < EndStates.size(); i++)
			{
				terminal_states.push_back(EndStates[i]);
			}
			for (int i = 0; i < DStates.size(); i++)
			{
				if (DStates[i]->to.size() > 0)
					not_terminal_states.push_back(DStates[i]);
			}
			classes.push_back(terminal_states);
			classes.push_back(not_terminal_states);
			for (int i = 0; i < DStates.size(); i++)
                        {
				std::string s = DStates[i]->s;
                                S.push(std::make_pair(s, terminal_states));
				S.push(std::make_pair(s, not_terminal_states));
                        }
			while (!S.empty())
			{
				std::pair <std::string , std::vector<State*>> splitter = S.front();
				S.pop();
				for (int i = 0; i < classes.size(); i++)
				{
					std::vector<State*> R = classes[i];
					std::pair<std::vector<State*>, std::vector<State*>> R_sets =
					split( R, splitter.first, splitter.second);
					std::vector<State*> R1 = R_sets.first, R2 = R_sets.second;
					if (R1.size() > 0 && R2.size() > 0)
					{
						classes.erase(classes.begin() + i);
						classes.push_back(R1);
						classes.push_back(R2);
						for (int i = 0; i < DStates.size(); i++)
						{
							S.push(std::make_pair(DStates[i]->s, R1));
							S.push(std::make_pair(DStates[i]->s, R2));
						}
					}
				}
			}
			return classes;
		}

		void minimize_DFA()
		{
			std::vector<std::vector<State*>> min_states = minimize();
			std::vector<State*> min_StartStates, min_EndStates, min_DStates;
			State *min_state;
			std::string min_s;
			for (int i = 0 ; i < min_states.size(); i++)
			{
				min_s = "";
				for (int j = 0; j < min_states[i].size(); j++)
				{
					min_s += min_states[i][j]->s;
				}
				min_state = new State(min_s, min_states[i][0]->s_num);
				min_DStates.push_back(min_state);
			}

			//min DFA start states definition
			for (int i = 0; i < min_DStates.size(); i++)
			{
				for (int j = 0; j < min_DStates[i]->s.size(); j++)
				{
					bool flag = false;
					for (int k = 0; k < StartStates.size(); k++)
					{
						if (min_DStates[i]->s[j] == StartStates[k]->s[0])
						{
							flag = true;
							min_StartStates.push_back(min_DStates[i]);
							break;
						}
					}
					if (flag)
						break;
				}
			}
			//min DFA endstates definition
                        for (int i = 0; i < min_DStates.size(); i++)
                        {
                                for (int j = 0; j < min_DStates[i]->s.size(); j++)
                                {
                                        bool flag = false;
                                        for (int k = 0; k < EndStates.size(); k++)
                                        {
                                                if (min_DStates[i]->s[j] == EndStates[k]->s[0])
                                                {
                                                        flag = true;
                                                        min_EndStates.push_back(min_DStates[i]);
                                                        break;
                                                }
                                        }
                                        if (flag)
                                                break;
                                }
                        }

			//min DFA transition definition
			for (int i = 0; i < min_DStates.size(); i++)
			{
				for (int j = 0; j < min_DStates[i]->s.size(); j++)
				{
					//std::cout << min_DStates[i]->s_num + j << "\n";
					bool flag = false;
					for (int k = 0; k < DStates[min_DStates[i]->s_num + j - 1]->to.size(); k++)
					{
						for (int t = 0; t < min_DStates.size(); t++)
						{
							if (DStates[min_DStates[i]->s_num + j - 1]->to[k]->s_num
							== min_DStates[t]->s_num)
							{
								flag = true;
								min_DStates[i]->to.push_back(min_DStates[t]);
								break;
							}
						}
						if (flag)
							break;
					}
						if (flag)
							break;
				}
			}
                        for (int i = 0; i < min_DStates.size(); i++)
                        {
                                std::cout << i+1 << "MIN DFA STATE \"" << min_DStates[i]->s << "\": ";
                                for (int j = 0; j < min_DStates[i]->to.size(); j++)
                                {
                                        std::cout << min_DStates[i]->to[j]->s_num << " " << min_DStates[i]->to[j]->s;
                                        if (j < min_DStates[i]->to.size())
                                                std::cout << ", ";
                                }
                                std::cout << "\n";
                        }
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
