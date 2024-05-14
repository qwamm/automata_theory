#include <iostream>
#include <unordered_map>
#include "values.h"

class symbol_table
{
	public:
		std::unordered_map<std::string, Value*> storval;
		symbol_table(){}
		~symbol_table(){}
		void print()
		{
			for (auto &c : storval)
			{
				if (c.second->type == "RECORD")
				{
					std::cout << "RECORD ";
				}
				std::cout << c.first << "\n";
				c.second->print();
				std::cout << "\n";
			}
		}
		bool assign_struct_to_var(std::string var_name, int ind_1, std::string name, std::string field_name, int ind_2)
		{
			if(!storval.contains(name) || !storval.contains(var_name))
			{
				std::cout << name << " " << var_name << "\n";
				this->print();
				std::cout <<"ISDFHJSDGJDSHV\n";
				return false;
			}
			else
			{
				Record_Value *record = dynamic_cast<Record_Value*>(storval[name]);
				if (!record->fields.contains(field_name))
				{
					throw(std::runtime_error("struct doesn't contain field"));
				}
				Value *val = record->fields[field_name], *cur = storval[var_name];
				if (cur->type == val->type && ind_1 < cur->size && ind_2 < val->size && ind_1 >= 0 && ind_2 >= 0)
				{
					if (cur->type == "NUMERIC")
					{
						Int_Value *v1 = dynamic_cast<Int_Value*>(cur);
						Int_Value *v2 = dynamic_cast<Int_Value*>(val);
					        v1->val[ind_1] = v2->val[ind_2];
					        storval[var_name] = v1;
					       	if(!storval[var_name]->defined)
								storval[var_name]->defined = true;
					        return true;
					}
					else if (cur->type == "LOGIC")
					{
						Bool_Value *v1 = dynamic_cast<Bool_Value*>(cur);
						Bool_Value *v2 = dynamic_cast<Bool_Value*>(val);
					        v1->val[ind_1] = v2->val[ind_2];
					       	storval[var_name] = v1;
					       	if(!storval[var_name]->defined)
								storval[var_name]->defined = true;
					        return true;
					}	
					else if (cur->type == "STRING")
					{
						Char_Value *v1 = dynamic_cast<Char_Value*>(cur);
						Char_Value *v2 = dynamic_cast<Char_Value*>(val);
					        v1->val[ind_1] = v2->val[ind_2];
					         storval[var_name] = v1;
					       	if(!storval[var_name]->defined)
								storval[var_name]->defined = true;
					        return true;
					}	
				}
			}
			return false;
		}
		bool assign_var_to_struct(std::string name, std::string field_name, int ind_1, std::string var_name, int ind_2)
		{
			if(!storval.contains(name) || !storval.contains(var_name))
			{
				return false;
			}
			else
			{
				std::cout << name << "\n";
				this->print();
				Record_Value *record = dynamic_cast<Record_Value*>(storval[name]);
				if (!record->fields.contains(field_name))
				{
					throw(std::runtime_error("struct doesn't contain field"));
				}
				Value *cur = record->fields[field_name], *val = storval[var_name];
				if (cur->type == val->type && ind_1 < cur->size && ind_2 < val->size && ind_1 >= 0 && ind_2 >= 0)
				{
					if (cur->type == "NUMERIC")
					{
						Int_Value *v1 = dynamic_cast<Int_Value*>(cur);
						Int_Value *v2 = dynamic_cast<Int_Value*>(val);
					        v1->val[ind_1] = v2->val[ind_2];
					        record->fields[field_name] = v1;
					       	if(!record->fields[field_name]->defined)
								record->fields[field_name]->defined = true;
				        return true;
					}
					else if (cur->type == "LOGIC")
					{
						Bool_Value *v1 = dynamic_cast<Bool_Value*>(cur);
						Bool_Value *v2 = dynamic_cast<Bool_Value*>(val);
					        v1->val[ind_1] = v2->val[ind_2];
					        record->fields[field_name] = v1;
					       	if(!record->fields[field_name]->defined)
								record->fields[field_name]->defined = true;
				        return true;
					}	
					else if (cur->type == "STRING")
					{
						Char_Value *v1 = dynamic_cast<Char_Value*>(cur);
						Char_Value *v2 = dynamic_cast<Char_Value*>(val);
					        v1->val[ind_1] = v2->val[ind_2];
					         record->fields[field_name] = v1;
					       	if(!record->fields[field_name]->defined)
								record->fields[field_name]->defined = true;
				        return true;
					}	
				}
			}
			return false;
		}
		bool assign_val_to_struct(std::string name, std::string field_name, int ind_1, Value *val)
		{
			if (!storval.contains(name))
			{
				return false;
			}
			else
			{
				Record_Value *record = dynamic_cast<Record_Value*>(storval[name]);
				if (!record->fields.contains(field_name))
				{
					throw(std::runtime_error("struct doesn't contain field"));
				}
				Value *cur = record->fields[field_name];
				if (cur->type == val->type && ind_1 < cur->size && ind_1 >= 0)
				{
					if (cur->type == "NUMERIC")
					{
						Int_Value *v1 = dynamic_cast<Int_Value*>(cur);
						Int_Value *v2 = dynamic_cast<Int_Value*>(val);
				        v1->val[ind_1] = v2->val[0];
				        record->fields[field_name] = v1;
				       	if(!record->fields[field_name]->defined)
							record->fields[field_name]->defined = true;
				        return true;
					}
					else if (cur->type == "LOGIC")
					{
						Bool_Value *v1 = dynamic_cast<Bool_Value*>(cur);
						Bool_Value *v2 = dynamic_cast<Bool_Value*>(val);
				        v1->val[ind_1] = v2->val[0];
				        record->fields[field_name] = v1;
				       	if(!record->fields[field_name]->defined)
							record->fields[field_name]->defined = true;
				        return true;
					}	
					else if (cur->type == "STRING")
					{
						Char_Value *v1 = dynamic_cast<Char_Value*>(cur);
						Char_Value *v2 = dynamic_cast<Char_Value*>(val);
				        v1->val[ind_1] = v2->val[0];
				        record->fields[field_name] = v1;
				       	if(!record->fields[field_name]->defined)
							record->fields[field_name]->defined = true;
				        return true;
					}	
				}
			}
			return false;
		}
		Value* find_var (std::string name)
		{
			//std::cout << "TRY TO FIND " << name << "\n";
			if (storval.contains(name))
			{
				return storval[name];
			}
			else
			{
				return nullptr;
			}
		}
		Value* is_func_in(std::string name)
		{
			if (storval.contains(name) && storval[name]->operation == PROCV)
			{
				return storval[name];
			}
			else
			{
				throw(std::runtime_error("function name wasn't defined"));
			}
		}
		bool add(std::string name, Value *val)
		{
				//std::cout << "TRY TO ADD " << name << "\n";
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
		bool assign_val(std::string name_1, int ind_1, Value *val)
		{
			if (!storval.contains(name_1))
			{
				return false;
			}
			else
			{
				Value *cur = storval[name_1];
				if (cur->type == val->type && ind_1 < cur->size && ind_1 >= 0)
				{
					if (cur->type == "NUMERIC")
					{
						Int_Value *v1 = dynamic_cast<Int_Value*>(cur);
						Int_Value *v2 = dynamic_cast<Int_Value*>(val);
					        v1->val[ind_1] = v2->val[0];
					        storval[name_1] = v1;
					       	if(!storval[name_1]->defined)
							storval[name_1]->defined = true;
				        	return true;
					}
					else if (cur->type == "LOGIC")
					{
						Bool_Value *v1 = dynamic_cast<Bool_Value*>(cur);
						Bool_Value *v2 = dynamic_cast<Bool_Value*>(val);
				        v1->val[ind_1] = v2->val[0];
				        storval[name_1] = v1;
				       	if(!storval[name_1]->defined)
							storval[name_1]->defined = true;
				        return true;
					}	
					else if (cur->type == "STRING")
					{
						Char_Value *v1 = dynamic_cast<Char_Value*>(cur);
						Char_Value *v2 = dynamic_cast<Char_Value*>(val);
				        v1->val[ind_1] = v2->val[0];
				        storval[name_1] = v1;
				       	if(!storval[name_1]->defined)
							storval[name_1]->defined = true;
				        return true;
					}	
				}
			}
			return false;
		}
		bool assign_var(std::string name_1, int ind_1, std::string name_2, int ind_2)
		{
			if(!storval.contains(name_1) || !storval.contains(name_2))
			{
				return false;
			}
			else
			{
				Value *cur = storval[name_1], *val = storval[name_2];
				//std::cout << cur->size << " " << val->size << "\n";
				if (cur->type == val->type && ind_1 < cur->size && ind_2 < val->size && ind_1 >= 0 && ind_2 >= 0)
				{
					if (cur->type == "NUMERIC")
					{
						Int_Value *v1 = dynamic_cast<Int_Value*>(cur);
						Int_Value *v2 = dynamic_cast<Int_Value*>(val);
				        v1->val[ind_1] = v2->val[ind_2];
				        storval[name_1] = v1;
				       	if(!storval[name_1]->defined)
							storval[name_1]->defined = true;
				        return true;
					}
					else if (cur->type == "LOGIC")
					{
						Bool_Value *v1 = dynamic_cast<Bool_Value*>(cur);
						Bool_Value *v2 = dynamic_cast<Bool_Value*>(val);
				        v1->val[ind_1] = v2->val[ind_2];
				        storval[name_1] = v1;
				       	if(!storval[name_1]->defined)
							storval[name_1]->defined = true;
				        return true;
					}	
					else if (cur->type == "STRING")
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
