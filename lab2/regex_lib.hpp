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
		bool match(const std::string &s)
		{
			State *cur_state;
			bool f = false;
			for(int i = 0; i < d->StartStates.size(); i++)
			{
				std::string b = std::string(1,s[0]);
				if (b == d->StartStates[i]->s)
				{
					cur_state = d->StartStates[i];
					f = true;
				}
			}
			if (!f)
				return false;
			for (int i = 1; i < s.size(); i++)
			{
				f = false;
				if (cur_state->to.size() == 0)
					break;
				for (int j = 0; j < cur_state->to.size(); j++)
				{
					std::string b = std::string(1,s[i]);
					if (b == cur_state->to[j]->s)
					{
						cur_state = cur_state->to[j];
						f = true;
					}
				}
				if (!f)
					return false;
			}
			return true;
		}
};
