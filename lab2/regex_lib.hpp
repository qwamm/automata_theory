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
			regex = reg;
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

		void language_addition()
		{
			std::vector<std::string> v;
			for (auto &c : regex)
				v.push_back(std::string(1,c));
			std::vector<std::string> buf;
			for (auto &c : v)
				buf.push_back(c);
			int count = buf.size();
			for (int z = 0; z < regex.size() - 1; z++)
			{
				std::vector<std::string> tmp; //stores all combinations of length z
				for (int i = 0; i < regex.size(); i++)
				{
					for (int k = 0; k < buf.size(); k++)
					{
						if(v[i] != buf[k])
						{
							tmp.push_back(buf[k] + regex[i]);
							count++;
						}
					}
				}
				for (int i = 0; i < tmp.size(); i++)
					std::cout << tmp[i] << " ";
				std::cout << "\n";
				buf.clear();
				for (auto &c : tmp)
					buf.push_back(c);
				//buf = tmp;
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
					int ind = 0;
					int p_num = 0;
					buf = "";
					current_state = d->StartStates[i];
					do
					{
						buf += current_state->s;
						std::cout << buf << "\t" << i << "\t" << k << "\n";
						flag = false;
						for (int j = ind; j < current_state->to.size(); j++)
						{
							if ((current_state->to[j]->s_num <= k || p_num == 0 || current_state->to[j]->to.size() == 0)
							&& current_state->to[j] != current_state)
							{
								//std::cout << k << "\t" << current_state->to[j]->s << "\n";
								flag = true;
								current_state = current_state->to[j];
								p_num++;
								break;
							}
							else if ((current_state->to[j]->s_num <= k || p_num == 0 || current_state->to[j]->to.size() == 0)
                                                        && current_state->to[j] == current_state)
							{
								buf += '+';
								flag = true;
								ind = j+1;
								//break;
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
