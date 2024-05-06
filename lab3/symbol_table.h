#include <iostream>
#include <unordered_map>
#include "values.h"

class symbol_table
{
	public:
		std::unordered_map<char*, Value*> storval;
		symbol_table(){}
		~symbol_table(){}
		bool in_table(char *s)
		{
			for (auto &c : storval)
			{
				if (strcmp(c.first, s) == 0)
					return true;
			}
			return false;
		}
		void print()
		{
			for (auto &c : storval)
			{
				std::cout << c.first << " ";
				c.second->print();
				std::cout << "\n";
			}
		}
		bool add(char *name, Value *val)
		{
                if(in_table(name))
                {
                        return false;
                }
                else
                {
                        storval[name] = val;
			return true;
                }
		}
		bool assign(char *name_1, int ind_1, char *name_2, int ind_2)
		{
			if(!in_table(name_1) || !in_table(name_2))
			{
				return false;
			}
			else
			{
				Value *cur = storval[name_1], *val = storval[name_2];
				std::cout << "SYMBOLIC TABLE\n";
				if (strcmp(cur->type, val->type) == 0 && ind_1 < cur->size && ind_2 < val->size && ind_1 >= 0 && ind_2 >= 0)
				{
					if (strcmp(cur->type, "NUMERIC") == 0)
					{
						Int_Value *v1 = dynamic_cast<Int_Value*>(cur);
						Int_Value *v2 = dynamic_cast<Int_Value*>(val);
				        v1->val[ind_1] = v2->val[ind_2];
				        storval[name_1] = v1;
				       	if(!storval[name_1]->defined)
							storval[name_1]->defined = true;
				        return true;
					}
					else if (strcmp(cur->type, "LOGIC") == 0)
					{
						Bool_Value *v1 = dynamic_cast<Bool_Value*>(cur);
						Bool_Value *v2 = dynamic_cast<Bool_Value*>(val);
				        v1->val[ind_1] = v2->val[ind_2];
				        storval[name_1] = v1;
				       	if(!storval[name_1]->defined)
							storval[name_1]->defined = true;
				        return true;
					}	
					else if (strcmp(cur->type, "STRING") == 0)
					{
						Char_Value *v1 = dynamic_cast<Char_Value*>(cur);
						Char_Value *v2 = dynamic_cast<Char_Value*>(val);
				        v1->val[ind_1] = v2->val[ind_2];
				        storval[name_1] = v1;
				       	if(!storval[name_1]->defined)
							storval[name_1]->defined = true;
				        return true;
					}	
				}
			}
			return false;
		}
};
