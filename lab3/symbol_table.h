#include <iostream>
#include <unordered_map>
#include "values.h"

class symbol_table
{
	public:
		std::unordered_map<char*, Value*> storval;
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
		bool assign(char *name_1, int ind, char *name_2)
		{
			if(!storval.contains(name_1) || !storval.contains(name_2))
			{
				return false;
			}
			else
			{
				Value *cur = storval[name_1], *val = storval[name_2];
				if (strcmp(cur->type, val->type) == 0 && ind < cur->size)
				{
					if (strcmp(cur->type, "NUMERIC") == 0)
					{
						Int_Value *v1 = dynamic_cast<Int_Value*>(cur);
						Int_Value *v2 = dynamic_cast<Int_Value*>(val);
					        v1->val = v2->val[ind];
					        storval[name_1] = v1;
					        storval[name_2] = v2;
					}
					else if (strcmp(cur->type, "LOGIC") == 0)
					{
						Bool_Value *v1 = dynamic_cast<Bool_Value*>(cur);
						Bool_Value *v2 = dynamic_cast<Bool_Value*>(val);
					        v1->val = v2->val[ind];
					        storval[name_1] = v1;
					        storval[name_2] = v2;
					}	
					else if (strcmp(cur->type, "STRING") == 0)
					{
						Char_Value *v1 = dynamic_cast<Char_Value*>(cur);
						Char_Value *v2 = dynamic_cast<Char_Value*>(val);
					        v1->val = v2->val[ind];
					        storval[name_1] = v1;
					        storval[name_2] = v2;
					}	
					if(!storval[name_1]->defined)
						storval[name_1]->defined = true;
					return true;
				}
			}
			return false;
		}
};
