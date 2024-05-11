#include <cmath>
#include "tree_parser.h"

void tree_parser::parse(node *ptr, symbol_table& stab, robot &r)
{
	if (ptr->left)
		parse(ptr->left, stab);
	if(ptr->operation == VARN)
	{
			 decl_node *temp = dynamic_cast<decl_node*>(ptr);
			 std::string type = temp->type;
			 std::string var_name = temp->var_name;
			 if (temp->size == nullptr)
			 {
					 if (type == "NUMERIC")
					 {
						int val = parse_int(temp->child, stab);
						Value *store = new Int_Value(type, 1, val, true, VAR);
						if (!stab.add(var_name, store))
						{
							std::cout << var_name << "\n";
							throw(std::runtime_error("multiple definition of variable"));
						}
					 }
					 else if(type == "LOGIC")
					 {
						bool val = parse_bool(temp->child, stab);
						Value *store = new Bool_Value(type, 1, val, true, VAR);
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
						Value *store = new Char_Value(type, 1, val, true, VAR);
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
		 int size;
		 if (temp->size != nullptr)
		 	size = parse_int(temp->size, stab);
		 else
		 	size = 1;
		 if (type == "NUMERIC")
		 {
				Value *store = new Int_Value(type, size, 0, false, VAR);
				if (!stab.add(var_name, store))
				{
					throw(std::runtime_error("multiple definition of variable"));
				}
		 }
		 else if(type == "LOGIC")
		 {
				Value *store = new Bool_Value(type, size, 0, false, VAR);
	            if (!stab.add(var_name, store))
	            {
	                    throw(std::runtime_error("multiple definition of variable"));
	            }
		 }
		 else if (type == "STRING")
		 {
			    Value *store = new Char_Value(type, size, nullptr, false, VAR);
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
			ind_1 = parse_int(l_temp->index, stab);	
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
					int ind_2 = parse_int(r_temp->index, stab);
					str_node *t = dynamic_cast<str_node*>(r_temp->name);
		            if (!stab.assign_var(name, ind_1, t->str, ind_2))
		            {
		            		 std::cout << "HERE " << ind_1 << " " << ind_2 << " " << name << " " << t->str << "\n";
		                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
		            }
				}
		}
		else if (r->operation == LITERALN)
		{
				str_node *r_temp = dynamic_cast<str_node*>(r);
				Value *t = new Char_Value("STRING", 1, r_temp->str , true, VAR);
	            if (!stab.assign_val(name, ind_1, t))
	            {
	                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
	            }
		}
		else if (r->operation == INTN || (r->operation >= 4 && r->operation <= 13))
		{
				Value *t = new Int_Value("NUMERIC", 1, parse_int(r, stab) , true, VAR);
	            if (!stab.assign_val(name, ind_1, t))
	            {
	                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
	            }
		}
		else if (r->operation == BOOLN)
		{
				Value *t = new Bool_Value("LOGIC", 1, parse_bool(r, stab) , true, VAR);
	            if (!stab.assign_val(name, ind_1, t))
	            {
	                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
	            }
		}
	
	}
	else if (ptr->operation == CONDN)
	{
		cond_node *temp = dynamic_cast<cond_node*>(ptr);
		ast t;
		//t.put_tree(temp->condition, 0);
		std::cout << "BOOL PARSE RESULT\n" << parse_bool(temp->condition, stab) << "\n";
		while (parse_bool(temp->condition, stab))
		{
			block_node *b = dynamic_cast<block_node*>(temp->block);
			parse(b->child, stab);
		}
	}
	else if (ptr->operation == PROCN)
	{
		proc_node *temp = dynamic_cast<proc_node*>(ptr);
		Value *store = new Proc_Value(temp->parameters, temp->body, true, PROCV);
        if (!functions.add(temp->name, store))
		{
		       	throw(std::runtime_error("multiple definition of function"));
		}
	}
	else if (ptr->operation == CALLN)
	{
		proc_node *call = dynamic_cast<proc_node*>(ptr);
		Proc_Value *p = dynamic_cast<Proc_Value*>(functions.is_func_in(call->name));
		node *func_params = p->parameters;
		node *func_body = p->body;
		block_node *b = dynamic_cast<block_node*>(func_body);
		symbol_table local;
		check_height(func_params, call->parameters);
		assign_params(func_params, call->parameters, local, stab);
		parse(b->child, local);
	}
	else if (ptr->operation >= 22 && ptr->operation <= 25) //MOVE
	{
		move_node *move = dynamic_cast<move_node*>(ptr);
		if (move->child->operation != INTN)
		{
			throw(std::runtime_error("parameter of MOVE functions must be a number"));
		}
		int steps = parse_int(move->child);

	}
}

void tree_parser::assign_params (node *func_params, node *call_params, symbol_table &local, symbol_table &lglobal)
{
	if (call_params->left && func_params->left)
	{
		assign_params(func_params->left, call_params->left, local, lglobal);
	}
	if (call_params->operation != STRN) {throw (std::runtime_error("parameter of function must be a reference on global variable"));}
	str_node *s = dynamic_cast<str_node*>(call_params);
	decl_node *f = dynamic_cast<decl_node*>(func_params);
	Value *v;
	if (!(v = lglobal.find_var(s->str)))
	{
		throw (std::runtime_error("global variable put as func parameter wasn't found"));
	}
	local.add(f->var_name, v);
}

void tree_parser::check_height(node *func_params, node *call_params)
{
	while (call_params->left && func_params->left)
	{
		call_params = call_params->left;
		func_params = func_params->left;
	}
	if (func_params->left || call_params->left)
	{
		throw (std::runtime_error("too less or too many arguments for function"));
	}
}

int tree_parser::parse_bool(node *ptr, symbol_table& stab)
{
        if (ptr->operation == BOOLN)
        {
                bool_node *temp = dynamic_cast<bool_node*>(ptr);
                if (!temp->left && !temp->right)
                {
                        return temp->value;
                }
        }
        else if (ptr->operation == INTN)
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
                                return parse_bool(ptr->left, stab) ^ parse_bool(ptr->right, stab);
                                break;
                        case(5):
                                return parse_bool(ptr->left, stab) || parse_bool(ptr->right, stab);
                                break;
                        case(6):
                                return parse_bool(ptr->left, stab) && parse_bool(ptr->right, stab);
                                break;
                        case(7):
                                return !(parse_bool(ptr->left, stab) && parse_bool(ptr->right, stab));
                                break;
                        case(8):
                               return parse_bool(ptr->left, stab) == parse_bool(ptr->right, stab);
                               break;
                        case(9):
	                        	return parse_bool(ptr->left, stab) != parse_bool(ptr->right, stab);
	                        	break;
                        case(10):
	                        	return !(parse_bool(ptr->left, stab) || parse_bool(ptr->right, stab));
	                        	break;
                        case(11):
	                        	return parse_bool(ptr->left, stab) < parse_bool(ptr->right, stab);
	                        	break;
                        case(12):
	                        	return parse_bool(ptr->left, stab) > parse_bool(ptr->right, stab);
	                        	break;
                }
        }
        else if (ptr->operation == 13)
        {
        	return !parse_bool(ptr->left, stab);
        }
		else if (ptr->operation == STRN)
		{
			str_node *temp = dynamic_cast<str_node*>(ptr);
			if(stab.storval.contains(temp->str) && (stab.storval[temp->str]->type == "NUMERIC" || stab.storval[temp->str]->type == "LOGIC") &&
			 stab.storval[temp->str]->size == 1)
			{
				Int_Value *temp_2 = dynamic_cast<Int_Value*>(stab.storval[temp->str]);
				std::cout << temp->str << " " <<  *(temp_2->val) << "\n";
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
			int index = parse_int(temp->index, stab);
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

int tree_parser::parse_int(node *ptr, symbol_table& stab)
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
					return parse_int(ptr->left, stab) - parse_int(ptr->right, stab);
					break;
				case(5):
	                return parse_int(ptr->left, stab) + parse_int(ptr->right, stab);
	                break;
				case(6):
	                return parse_int(ptr->left, stab) * parse_int(ptr->right, stab);
	                break;
	            case(7):
	                return parse_int(ptr->left, stab) / parse_int(ptr->right, stab);
	                break;
	            case(8):
	            	return pow(parse_int(ptr->left, stab), parse_int(ptr->right, stab));
	            	break;
	            case(9):
	            	return parse_int(ptr->left, stab) != parse_int(ptr->right, stab);
	            	break;
	            case(10):
	            	return parse_int(ptr->left, stab) == parse_int(ptr->right, stab);
	            	break;
	            case(11):
	            	return parse_int(ptr->left, stab) < parse_int(ptr->right, stab);
	            	break;
	            case(12):
	            	return parse_int(ptr->left, stab) > parse_int(ptr->right, stab);
	            	break;
			}
	}
 	else if (ptr->operation == 13)
    {
    	return -parse_int(ptr->left, stab);
    }
	else if (ptr->operation == STRN)
	{
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
		int index = parse_int(temp->index, stab);
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
