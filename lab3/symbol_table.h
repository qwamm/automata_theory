#include <iostream>
#include <unordered_map>
#include "values.h"

class symbol_table
{
	std::unordered_map<char*, Value*> storval;
	public:
		symbol_table(){}
		~symbol_table(){}
		bool add(char *name, Value *val)
		{
                        if(storval.contains(name))
                        {
                                return false;
                        }
                        else
                        {
                                storval[name] = val;
				return true;
                        }
		}
		bool assign(char *name, Value *val)
		{
			if(!storval.contains(name))
			{
				return false;
			}
			else
			{
				storval[name] = val;
				return true;
			}
		}
};
