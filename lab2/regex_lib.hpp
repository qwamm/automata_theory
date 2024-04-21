#include <iostream>
#include "dfa.hpp"

class SRegex
{
	private:
		std::string regex; //не нужно хранить regex
	public:
		std::unordered_map<int, std::string> m;
		DFA *d;
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

		void set_capture_groups()
		{
			m = d->capture_groups;
		}

		bool language_addition(std::string &s) //переделать (возвращает объект рв, который не мэтчит все строки, которые мэтчит исходная регулярка
		{
			if (match(s) == false)
				return true;
			return false;
		}

		bool parsing(State *cur_state, std::string s, int ind, int call)
		{
				bool f = false;
				std::string b;
                m[cur_state->group_num].push_back(s[ind-1]);
        		for (int k = 0; k < cur_state->to.size(); k++)
        		{
                		b = std::string(1,s[ind]);
                		//std::cout << cur_state->to[k]->s << " " << s[ind] << "\n";
                		if (b == cur_state->to[k]->s)
                		{
                				//std::cout << "CUR STATE: " << cur_state->s_num << " " << cur_state->s << "\n";
								cur_state = cur_state->to[k];
								if (ind == s.size() - 1)
								{
									//std::cout << "END STATE: " << cur_state->s_num << " " << cur_state->s << "\n";
									for (int t = 0; t < d->EndStates.size(); t++)
									{
										if (cur_state == d->EndStates[t])
										{
				                                f = true;
				                                break;
										}
									}
								}
								if (f)
                        			break;
                        		f = parsing(cur_state, s, ++ind, call + 1);
                        		if (call > 0)
                        			ind--;
                        		if(f)
                        			break;
                		}
        		}
        		return f;
		}

		bool match(std::string s)
		{
			m.clear();
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
						if (s.size() == 1)
						{
								m[cur_state->group_num].push_back(s[0]);
	                            for (int t = 0; t < d->EndStates.size(); t++)
	                            {
	                                    if (cur_state == d->EndStates[t])
	                                    {
	                                        	return true;
	                                    }
	                            }
								break;
						}
               			f = parsing(cur_state, s, 1, 0);
						if (f)
                    			return true;
					}	
			}
			return false;
		}

		bool regex_traversal (std::string regex_2, std::string str)
		{
			DFA *d_2 = new DFA(), *d_3 = new DFA();
			d_2->create(regex_2);
			return d_3->automata_product(d, d_2, str);
		}

		void path_passing(State *current_state, int k, bool &flag, std::string &buf, std::string &res, int p_num, int ind, int i)
		{
						if(current_state->s != "$")
                                                	buf += current_state->s;
						std::string prev = buf;
                                                std::cout << buf << "\t" << i << "\t" << k << "\n";
                                                flag = false;
                                                for (int j = ind; j < current_state->to.size(); j++)
                                                {
                                                        if ((current_state->to[j]->s_num <= k || p_num == 0 || current_state->to[j]->to.size() == 0 || (current_state->to[j]->to.size() == 1 && current_state->to[j]->to[0]->s == "$"))
                                                        && current_state->to[j] != current_state)
                                                        {
                                                                //std::cout << k << "\t" << current_state->to[j]->s << "\n";
                                                                p_num++;
                                                                ind = 0;
								path_passing(current_state->to[j], k, flag, buf, res, p_num, ind, i);
								if (j < current_state->to.size() - 1)
									buf = prev;
								flag = true;
                                                        }
                                                        else if ((current_state->to[j]->s_num <= k || p_num == 0 || current_state->to[j]->to.size() == 0)
                                                        && current_state->to[j] == current_state)
                                                        {
                                                                buf += '+';
                                                                flag = true;
                                                                ind = j + 1;
                                                        }
                                                }
                                                if (current_state->to.size() == 0)
                                                        flag = true;
                                                // if (current_state->to.size() == 0 && current_state->s != "$" &&  current_state != d->StartStates[i])
                                                // {
                                                //          buf += current_state->s;
                                                // }
                                        if ((flag && current_state->to.size() == 0) || (flag && current_state->to.size() == 1 && current_state->to[0] ==
                                        	current_state))
                                        {
                                                res += buf;
                                                res.push_back('|');
                                        }
		}

		std::string restore_regex() //K-path algorithm
		{
			std::string res = "", buf = "";
			int k = 1;
			std::vector<State*> DStates = d->getDStates();
			bool flag = false; //condition means that path doesn't include vertices with number > k
			while (k < DStates.size())
			{
				State *current_state;
				for (int i = 0; i < d->StartStates.size(); i++)
				{
					 buf = "";
					current_state = d->StartStates[i];
					std::cout << "START SATTE: " << current_state->s << "\n";
					path_passing(current_state, k ,flag, buf, res, 0, 0, i);
					/*if (flag)
					{
						res += buf;
						res.push_back('|');
					}*/
				}
                                /*if (k < DStates.size() - 1 && buf.size() > 0 && flag)
                                {
                                        res += buf;
                                        res.push_back('|');
                                }
                                else if (flag)
                                {
                                        res += buf;
                                }*/
				k++;
			}
			if (res[res.size()-1] == '|')
				res = res.substr(0, res.size() - 1);
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
