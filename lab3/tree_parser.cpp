#include <cmath>
#include "tree_parser.h"

void tree_parser::parse(node *ptr)
{
	if (ptr->left)
		parse(ptr->left);
	if(ptr->operation == VARN)
	{
			 decl_node *temp = dynamic_cast<decl_node*>(ptr);
			 std::string type = temp->type;
			 std::string var_name = temp->var_name;
			 if (temp->size == nullptr)
			 {
					 if (type == "NUMERIC")
					 {
						int val = parse_int(temp->child);
						std::cout << val << "\n";
						Value *store = new Int_Value(type, 1, val, true);
						if (!stab.add(var_name, store))
						{
							throw(std::runtime_error("multiple definition of variable"));
						}
					 }
					 else if(type == "LOGIC")
					 {
						bool val = parse_bool(temp->child);
						std::cout << val << "\n";
						Value *store = new Bool_Value(type, 1, val, true);
                        if (!stab.add(var_name, store))
                        {
                                throw(std::runtime_error("multiple definition of variable"));
                        }
					 }
					 else if (type == "STRING")
					 {
						str_node *sptr = dynamic_cast<str_node*>(temp->child);
						if (sptr->operation != LITERALN)
						{
							 throw(std::runtime_error("wrong type of variable"));
						}
						std::string val = sptr->str;
						std::cout << val << "\n";
						Value *store = new Char_Value(type, 1, val, true);
			            if (!stab.add(var_name, store))
			            {
			                     throw(std::runtime_error("multiple definition of variable"));
			            }
					 }
			}	
	}	
	else if (ptr->operation == UNDEFVARN)
	{
		 decl_node *temp = dynamic_cast<decl_node*>(ptr);
		 std::string type = temp->type;
		 std::string var_name = temp->var_name;
		 std::cout << type << "\n";
		 int size;
		 if (temp->size != nullptr)
		 	size = parse_int(temp->size);
		 else
		 	size = 0;
		 if (type == "NUMERIC")
		 {
				Value *store = new Int_Value(type, size, 0, false);
				if (!stab.add(var_name, store))
				{
					throw("multiple definition of variable");
				}
		 }
		 else if(type == "LOGIC")
		 {
				Value *store = new Bool_Value(type, size, 0, false);
	            if (!stab.add(var_name, store))
	            {
	                    throw(std::runtime_error("multiple definition of variable"));
	            }
		 }
		 else if (type == "STRING")
		 {
			    Value *store = new Char_Value(type, size, nullptr, false);
	            if (!stab.add(var_name, store))
	            {
	                     throw(std::runtime_error("multiple definition of variable"));
	            }
		 }
	}
	else if (ptr->operation == ASSIGNN)
	{
		assign_node *temp = dynamic_cast<assign_node*>(ptr);
		node *l = temp->left_op, *r = temp->child;
		std::string name;
		int ind_1;
		if (l->operation == STRN)
		{
			str_node *l_temp = dynamic_cast<str_node*>(l);
			name = l_temp->str;
			ind_1 = 0;
		}
		else if (l->operation == ARRASSIGNN)
		{
			arr_node *l_temp = dynamic_cast<arr_node*>(l);
			if (l_temp->name->operation == STRN)
			{
					str_node *t_2 = dynamic_cast<str_node*>(l_temp->name);
					name = t_2->str;
			}
			else
			{
				throw(std::runtime_error("wrong array name"));
			}
			ind_1 = parse_int(l_temp->index);	
		}
		if (r->operation == STRN)
		{
				str_node *r_temp = dynamic_cast<str_node*>(r);
	            if (!stab.assign_var(name, ind_1, r_temp->str, 0))
	            {
	                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
	            }
		}
		else if (r->operation == ARRASSIGNN)
		{
				arr_node *r_temp = dynamic_cast<arr_node*>(r);
				if (r_temp->name->operation == STRN)
				{
					int ind_2 = parse_int(r_temp->index);
					str_node *t = dynamic_cast<str_node*>(r_temp->name);
		            if (!stab.assign_var(name, ind_1, t->str, ind_2))
		            {
		                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
		            }
				}
		}
		else if (r->operation == LITERALN)
		{
				str_node *r_temp = dynamic_cast<str_node*>(r);
				Value *t = new Char_Value("STRING", 1, r_temp->str , true);
	            if (!stab.assign_val(name, ind_1, t))
	            {
	                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
	            }
		}
		else if (r->operation == INTN || (r->operation >= 4 && r->operation <= 13))
		{
				std::cout << parse_int(r) << "\n";
				Value *t = new Int_Value("NUMERIC", 1, parse_int(r) , true);
	            if (!stab.assign_val(name, ind_1, t))
	            {
	                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
	            }
		}
		else if (r->operation == BOOLN)
		{
				Value *t = new Bool_Value("LOGIC", 1, parse_bool(r) , true);
	            if (!stab.assign_val(name, ind_1, t))
	            {
	                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
	            }
		}
	
	}
	else if (ptr->operation == CONDN)
	{
		cond_node *temp = dynamic_cast<cond_node*>(ptr);
		while (parse_int(temp->condition))
		{
			block_node *b = dynamic_cast<block_node*>(temp->block);
			parse(b->child);
		}
	}
	stab.print();
}
bool tree_parser::parse_bool(node *ptr)
{
        if (ptr->operation == BOOLN)
        {
                bool_node *temp = dynamic_cast<bool_node*>(ptr);
                if (!temp->left && !temp->right)
                {
                        return temp->value;
                }
        }
        else if (ptr->operation >= 4 && ptr->operation <= 12)
        {
                switch(ptr->operation)
                {
                        case(4):
                                return parse_bool(ptr->left) ^ parse_bool(ptr->right);
                                break;
                        case(5):
                                return parse_bool(ptr->left) || parse_bool(ptr->right);
                                break;
                        case(6):
                                return parse_bool(ptr->left) && parse_bool(ptr->right);
                                break;
                        case(7):
                                return !(parse_bool(ptr->left) && parse_bool(ptr->right));
                                break;
                        case(8):
                               return !(parse_bool(ptr->left) || parse_bool(ptr->right));
                               break;
                        case(9):
                        	return parse_bool(ptr->left) != parse_bool(ptr->right);
                        	break;
                        case(10):
                        	return parse_bool(ptr->left) == parse_bool(ptr->right);
                        	break;
                        case(11):
                        	return parse_bool(ptr->left) < parse_bool(ptr->right);
                        	break;
                        case(12):
                        	return parse_bool(ptr->left) > parse_bool(ptr->right);
                        	break;
                }
        }
        else if (ptr->operation == 13)
        {
        	return !parse_bool(ptr->left);
        }
		else if (ptr->operation == STRN)
		{
			str_node *temp = dynamic_cast<str_node*>(ptr);
			if(stab.storval.contains(temp->str) && stab.storval[temp->str]->type == "STRING" &&
			 stab.storval[temp->str]->size == 1)
			{
				Bool_Value *temp_2 = dynamic_cast<Bool_Value*>(stab.storval[temp->str]);
				return *(temp_2->val);
			}
		}
        else
        {
                throw (std::runtime_error("wrong expression from the right side of ="));
        }
        return 0;
}

int tree_parser::parse_int(node *ptr)
{
	if (ptr->operation == INTN)
	{
		int_node *temp = dynamic_cast<int_node*>(ptr);
		if (!temp->left && !temp->right)
		{
			return temp->value;
		}
	}
	else if (ptr->operation >= 4 && ptr->operation <= 12)
	{
			switch(ptr->operation)
			{
				case(4):
					return parse_int(ptr->left) - parse_int(ptr->right);
					break;
				case(5):
	                return parse_int(ptr->left) + parse_int(ptr->right);
	                break;
				case(6):
	                return parse_int(ptr->left) * parse_int(ptr->right);
	                break;
	            case(7):
	                return parse_int(ptr->left) / parse_int(ptr->right);
	                break;
	            case(8):
	            	return pow(parse_int(ptr->left), parse_int(ptr->right));
	            	break;
	            case(9):
	            	return parse_int(ptr->left) != parse_int(ptr->right);
	            	break;
	            case(10):
	            	return parse_int(ptr->left) == parse_int(ptr->right);
	            	break;
	            case(11):
	            	return parse_int(ptr->left) < parse_int(ptr->right);
	            	break;
	            case(12):
	            	return parse_int(ptr->left) > parse_int(ptr->right);
	            	break;
			}
	}
 	else if (ptr->operation == 13)
    {
    	return -parse_int(ptr->left);
    }
	else if (ptr->operation == STRN)
	{
		std::cout <<"ARRMARKER\n";
		str_node *temp = dynamic_cast<str_node*>(ptr);
		if(stab.storval.contains(temp->str) && stab.storval[temp->str]->type == "NUMERIC" &&
		 stab.storval[temp->str]->size == 1)
		{
			Int_Value *temp_2 = dynamic_cast<Int_Value*>(stab.storval[temp->str]);
			return *(temp_2->val);
		}
	}
	else if (ptr->operation == ARRASSIGNN)
	{
		arr_node *temp = dynamic_cast<arr_node*>(ptr);
		std::string name;
		if (temp->name->operation == STRN)
		{
			str_node *nm = dynamic_cast<str_node*>(temp->name);
			name = nm->str;
		}
		else
		{
				throw(std::runtime_error("wrong array name"));
		}
		int index = parse_int(temp->index);
		if(stab.storval.contains(name) && stab.storval[name]->type == "NUMERIC" &&
		 index < stab.storval[name]->size )
		{
			Int_Value *temp_2 = dynamic_cast<Int_Value*>(stab.storval[name]);
			return temp_2->val[index];
		}
	}
	else
	{
		throw (std::runtime_error("wrong expression from the right side of ="));
	}
	return 0;
}
