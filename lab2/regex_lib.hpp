#include <iostream>
#include "dfa.hpp"

class SRegex
{
	private:
		std::string regex;
		DFA *d;
	public:
		SRegex(std::string reg)
		{
			d = new DFA();
			d->create(reg);
		}
		~SRegex()
		{
			delete d;
		}

		void print_capture_groups()
		{
			std::unordered_map<int, std::string> capture_groups = d->capture_groups;
			for (auto &c : capture_groups)
			{
				std::cout << c.first << "\t" << c.second << "\n";
			}
		}

		bool match(std::string &s)
		{
			s.push_back('$');
			std::cout << s << "\n";
			State *cur_state;
			bool f = false;
			std::string b = std::string(1,s[0]);
			for(int i = 0; i < d->StartStates.size(); i++)
			{
				b = std::string(1,s[0]);
				if (b == d->StartStates[i]->s)
				{
					cur_state = d->StartStates[i];
                       			for (int j = 1; j < s.size(); j++)
                        		{
						f = false;
                                		/*if (cur_state->to.size() == 0 && j == s.size() - 1)
						{
							f = true;
                                        		break;
						}*/
						if (j == s.size() - 1)
						{
							std::cout << "MARKER\n";
							for (int t = 0; t < d->EndStates.size(); t++)
							{
								if (cur_state == d->EndStates[t])
								{
									f = true;
									break;
								}
							}
						}
                                		for (int k = 0; k < cur_state->to.size(); k++)
                                		{
                                        		b = std::string(1,s[j]);
							//std::cout << b << "\n";
                                        		if (b == cur_state->to[k]->s)
                                        		{
                                                		cur_state = cur_state->to[k];
                                                		f = true;
                                                		break;
                                        		}
                                		}
                                		if (!f)
                                        		break;
                        		}
					if (f)
                        			return true;
				}
			}
			return false;
		}

		DFA* regex_traversal (std::string regex_2)
		{
			DFA *d_2 = new DFA(), *d_3 = new DFA();
			d_2->create(regex_2);
			d_3->automata_product(d, d_2);
			return d_3;
		}

		std::string restore_regex() //K-path algorithm
		{
			std::string res = "", buf = "";
			int k = 1;
			std::vector<State*> DStates = d->getDStates();
			bool flag; //condition means that path doesn't include vertices with number > k
			//std::cout << d->StartStates.size() << "\n";
			while (k < DStates.size())
			{
				buf = "";
				State *current_state;
				for (int i = 0; i < d->StartStates.size(); i++)
				{
					buf = "";
					current_state = d->StartStates[i];
					do
					{
						buf += current_state->s;
						std::cout << buf << "\t" << i << "\t" << k << "\n";
						flag = false;
						for (int j = 0; j < current_state->to.size(); j++)
						{
							if (current_state->to[j]->s_num <= k || current_state->to[j]->to.size() == 0)
							{
								//std::cout << k << "\t" << current_state->to[j]->s_num << "\n";
								flag = true;
								current_state = current_state->to[j];
								break;
							}
						}
						if (current_state->to.size() == 0)
							flag = true;
						if (current_state->to.size() == 0 && current_state->s != "$" &&  current_state != d->StartStates[i])
						{
							 buf += current_state->s;
							 break;
						}
					}  while (current_state->to.size() > 0 && flag);
					if (flag)
					{
						res += buf;
						res.push_back('|');
					}
				}
                                if (k < DStates.size() - 1 && buf.size() > 0 && flag)
                                {
                                        res += buf;
                                        res.push_back('|');
                                }
                                else if (flag)
                                {
                                        res += buf;
                                }
				k++;
			}
			return res;
		}
};

class RegexMatch
{
	private:
		std::vector<std::string> m;
		bool match;
	public:
		RegexMatch(std::string str, SRegex reg)
		{
			match = reg.match(str);
		}

		RegexMatch (std::string s, std::string regex)
		{
			DFA *d;
			d = new DFA();
			d->create(regex);
			s.push_back('$');
			//std::cout << s << "\n";
			State *cur_state;
			bool f = false;
			std::string b = std::string(1,s[0]);
			for(int i = 0; i < d->StartStates.size(); i++)
			{
				if (b == d->StartStates[i]->s)
				{
					cur_state = d->StartStates[i];
					f = true;
				}
			}

			for (int i = 1; i < s.size(); i++)
			{
				f = false;
				if (cur_state->to.size() == 0)
					break;
				for (int j = 0; j < cur_state->to.size(); j++)
				{
					b = std::string(1,s[i]);
					//std::cout << b << "\n";
					if (b == cur_state->to[j]->s)
					{
						cur_state = cur_state->to[j];
						f = true;
						break;
					}
				}
				if (!f)
				{
					match = false;
					break;
				}
			}
			match =  true;
		}
};
