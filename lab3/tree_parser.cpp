#include <cmath>
#include "tree_parser.h"

void tree_parser::parse(node *ptr, symbol_table& stab, robot *rob)
{
	if (ptr->left)
		parse(ptr->left, stab, rob);
	// if (ptr->operation == CALLN)
	// {
	// 	stab.print();
	// 	std::cout << "\n";
	// 	rob.print_field();
	// 	std::cout << "\n";
	// }
	if(ptr->operation == VARN)
	{
			 decl_node *temp = dynamic_cast<decl_node*>(ptr);
			 std::string type = temp->type;
			 std::string var_name = temp->var_name;
			 if (temp->size == nullptr)
			 {
					 if (type == "NUMERIC")
					 {
						int val = parse_int(temp->child, stab, rob);
						Value *store = new Int_Value(type, 1, val, true, VAR);
						if (!stab.add(var_name, store))
						{
							throw(std::runtime_error("multiple definition of variable"));
						}
					 }
					 else if(type == "LOGIC")
					 {
						bool val = parse_bool(temp->child, stab, rob);
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
					else if (types.storval.contains(type))
					 {
					 		//std::cout << "OOOOOOOO\n";
					 		Record_Value *rec = dynamic_cast<Record_Value*>(types.storval[type]);
					 		std::unordered_map<std::string, Value*> cur_struct_fields = copy_fields(rec->fields);
						    Record_Value *store = new Record_Value(type, cur_struct_fields, true, VAR);
				            if (!stab.add(var_name, store))
				            {
				                     throw(std::runtime_error("multiple definition of variable"));
				            }
				            std::string r_type;
				            if (temp->child->operation == INTN || (temp->operation >= 4 && temp->operation <= 13))
				            {
				            	r_type = "NUMERIC";
				            }
				            else if (temp->child->operation == BOOLN)
				            {
				            	r_type = "LOGIC";
				            }
				            else if (temp->child->operation == STRN)
				            {
				            	r_type = "STRING";
				            }
					        std::string s = "CONVERT_" + stab.storval[var_name]->type + "_FROM_" + r_type;
							std::cout << s << "\n";
									std::cout << "ISRGIOJHSU\n";
									std::cout << temp->child->operation << "\n";
							if (functions.storval.contains(s))
							{
								if (r_type == "NUMERIC")
								{
									proc_node *func = dynamic_cast<proc_node*>(functions.storval[s]);
									decl_node *ut;
									int_node *x = new int_node(parse_int(temp->child, stab, rob), INTN); 
									std::cout << parse_int(temp->child, stab, rob) << "\n";
									ut = new decl_node("NUMERIC", "from", nullptr, x, VARN);
									str_node *u = new str_node("from", STRN);
									parse(ut, stab, rob);
									//stab.print();
									std::cout <<"VAR_NAME: " << var_name << "\n";
									str_node *v = new str_node(var_name, STRN);
									Record_Value *r_t = store;
									u->set_left(v);
									node *t = new proc_node(s, u, nullptr,  CALLN);
									parse(t, stab, rob);
									stab.storval.erase("from");
								}
								else if (r_type == "LOGIC")
								{
									proc_node *func = dynamic_cast<proc_node*>(functions.storval[s]);
									decl_node *ut = new decl_node("NUMERIC", "from", nullptr, temp->child, VARN);
									str_node *u = new str_node("from", STRN);
									parse(ut, stab, rob);
									//stab.print();
									std::cout <<"VAR_NAME: " << var_name << "\n";
									str_node *v = new str_node(var_name, STRN);
									Record_Value *r_t = store;
									u->set_left(v);
									node *t = new proc_node(s, u, nullptr,  CALLN);
									parse(t, stab, rob);
									stab.storval.erase("from");
								}
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
		 	size = parse_int(temp->size, stab, rob);
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
		 else if (types.storval.contains(type))
		 {
		 		Record_Value *rec = dynamic_cast<Record_Value*>(types.storval[type]);
		 		std::unordered_map<std::string, Value*> cur_struct_fields = copy_fields(rec->fields);
				    Record_Value *store = new Record_Value(type, cur_struct_fields, true, VAR);
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
		int ind_1 = 0;
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
			ind_1 = parse_int(l_temp->index, stab, rob);	
		}
		else if (l->operation == STRUCTREFN)
		{
			struct_ref_node *l_temp = dynamic_cast<struct_ref_node*>(l);
			name = l_temp->struct_name;
			std::string field_name = l_temp->struct_field;
			if (r->operation == STRN)
			{
				str_node *r_temp = dynamic_cast<str_node*>(r);
			            if (!stab.assign_var_to_struct(name, field_name, 0, r_temp->str, 0))
			            {
			                     throw(std::runtime_error("variadble wasn't declared or index out of range or types dismatch"));
			            }
			}
			else if (r->operation == LITERALN)
			{
					str_node *r_temp = dynamic_cast<str_node*>(r);
					Value *t = new Char_Value("STRING", 1, r_temp->str , true, VAR);
				            if (!stab.assign_val_to_struct(name, field_name, ind_1, t))
				            {
				                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
				            }
			}
			else if (r->operation == INTN || (r->operation >= 4 && r->operation <= 13))
			{
					Value *t = new Int_Value("NUMERIC", 1, parse_int(r, stab, rob) , true, VAR);
				            if (!stab.assign_val_to_struct(name, field_name, ind_1, t))
				            {
				                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
				            }
			}
			else if (r->operation == BOOLN)
			{
					Value *t = new Bool_Value("LOGIC", 1, parse_bool(r, stab, rob) , true, VAR);
				            if (!stab.assign_val_to_struct(name, field_name, ind_1, t))
				         	{
				                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
				            }
			}
			return;
		}
		if (r->operation == STRN)
		{
			    str_node *r_temp = dynamic_cast<str_node*>(r), *temp = r_temp;
			    if (stab.storval.contains(r_temp->str))
			    {
			    	Value *c = stab.storval[r_temp->str];
			    	if(types.storval.contains(c->type))
			    	{
		    			std::string type = stab.storval[name]->type;
		    			std::string s = "CONVERT_" + stab.storval[temp->str]->type + "_TO_" + type;
						std::cout << s << "\n";
						if ( functions.storval.contains(s))
						{
							std::cout << type << "\n";
							if (type == "NUMERIC")
							{
								proc_node *func = dynamic_cast<proc_node*>(functions.storval[s]);
								decl_node *ut = new decl_node("NUMERIC", "to", nullptr, nullptr, UNDEFVARN);
								str_node *u = new str_node("to", STRN);
								parse(ut, stab, rob);
								str_node *v = new str_node(temp->str, STRN);
								Record_Value *r_t = dynamic_cast<Record_Value*>(stab.storval[temp->str]);
								u->set_left(v);
								node *t = new proc_node(s, u, nullptr,  CALLN);
								parse(t, stab, rob);
								Int_Value *res = dynamic_cast<Int_Value*>(stab.storval["to"]);
								int result = res->val[0];
								stab.storval.erase("to");
								stab.assign_val(name, ind_1, res);
							}
							else if (type == "LOGIC")
							{
								proc_node *func = dynamic_cast<proc_node*>(functions.storval[s]);
								decl_node *ut = new decl_node("NUMERIC", "to", nullptr, nullptr, UNDEFVARN);
								str_node *u = new str_node("to", STRN);
								parse(ut, stab, rob);
								str_node *v = new str_node(temp->str, STRN);
								Record_Value *r_t = dynamic_cast<Record_Value*>(stab.storval[temp->str]);
								u->set_left(v);
								node *t = new proc_node(s, u, nullptr,  CALLN);
								parse(t, stab, rob);
								Int_Value *res = dynamic_cast<Int_Value*>(stab.storval["to"]);
								int result = res->val[0];
								stab.storval.erase("to");
								dynamic_cast<Bool_Value*>(stab.storval[name])->val[0] = result;
								//stab.assign_val(name, ind_1, res);							
							}
						}
						else
						{
							throw(std::runtime_error("CONVERTION WASN'T DEFINED"));
						}				
			    	}
			    }
		            else if (!stab.assign_var(name, ind_1, r_temp->str, 0))
		            {
		                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
		            }
		}
		else if (r->operation == STRUCTREFN)
		{
				struct_ref_node *r_temp = dynamic_cast<struct_ref_node*>(r);
		            if (!stab.assign_struct_to_var(name, ind_1, r_temp->struct_name, r_temp->struct_field , 0))
		            {
		            	            	std::cout <<"FKLEWNFJLNSJDNV\n";
		                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
		            }			
		}
		else if (r->operation == ARRASSIGNN)
		{
				arr_node *r_temp = dynamic_cast<arr_node*>(r);
				if (r_temp->name->operation == STRN)
				{
					int ind_2 = parse_int(r_temp->index, stab, rob);
					str_node *t = dynamic_cast<str_node*>(r_temp->name);
		            if (!stab.assign_var(name, ind_1, t->str, ind_2))
		            {
		            		 //std::cout << "HERE " << ind_1 << " " << ind_2 << " " << name << " " << t->str << "\n";
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
				Value *t = new Int_Value("NUMERIC", 1, parse_int(r, stab, rob) , true, VAR);
	            if (!stab.assign_val(name, ind_1, t))
	            {
	            	// std::cout << "UJSHGUIOSHRG\n";
	            	// std::cout << l->operation << " " << parse_int(r, stab, rob) << "\n";
	            	// ast x;
	            	// x.put_tree(l, 0);
	            	// x.put_tree(r, 0);
	                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
	            }
		}
		else if (r->operation == BOOLN)
		{
			    Value *t = new Bool_Value("LOGIC", 1, parse_bool(r, stab, rob) , true, VAR);
	            if (!stab.assign_val(name, ind_1, t))
	            {
	                     throw(std::runtime_error("variadble wasn't declared or index out of range"));
	            }
		}
		else if (r->operation >= 22 && r->operation <= 25)
		{
			int res = parse_move(r, rob, stab);
			Value *t = new Int_Value("NUMERIC", 1, res , true, VAR);
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
		//std::cout << "BOOL PARSE RESULT\n" << parse_bool(temp->condition, stab, rob) << "\n";
		while (parse_bool(temp->condition, stab, rob))
		{
			block_node *b = dynamic_cast<block_node*>(temp->block);
			parse(b->child, stab, rob);
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
		// local.print();
		// std::cout << "\n";
		// rob->print_field();
		// std::cout << "\n";
		parse(b->child, local, rob);
		// local.print();
		// std::cout << "\n";
		// rob->print_field();
		// std::cout << "\n";
	}
	else if(ptr->operation == RECORDN)
	{
		record_node *record = dynamic_cast<record_node*>(ptr);
		std::unordered_map<std::string, Value*> struct_fields;
		get_fields(record->сhild, struct_fields);
		Record_Value *store = new Record_Value("RECORD",struct_fields, true, VAR);
		std::cout << "RECORD NAME: " << record->type_name << "\n";
	    	if (!types.add(record->type_name, store))
		{
		       	throw(std::runtime_error("multiple definition of records"));
		}
		if (record->conv_to)
		{
			conv_node *convert = dynamic_cast<conv_node*>(record->conv_to);
			Value *store;
			decl_node *p_1 = new decl_node(convert->type, "to", nullptr, nullptr, UNDEFVARN);
			decl_node *p_2 = new decl_node(record->type_name, "from", nullptr, nullptr
			, UNDEFVARN);
			p_1->set_left(p_2);
			store = new Proc_Value(p_1, convert->body, true, PROCV);
			std::string f_name = "CONVERT_" + record->type_name + "_TO_" + convert->type;
			std::cout << "HEREKSDHGKJSNDBGSSBGU\n";
			std::cout << f_name << "\n";
		        if (!functions.add(f_name, store))
			{
			       	throw(std::runtime_error("multiple definition of function"));
			}
		}
		if (record->conv_from)
		{
			conv_node *convert = dynamic_cast<conv_node*>(record->conv_from);
			Value *store;
			decl_node *p_2 = new decl_node(record->type_name, "to", nullptr, nullptr, UNDEFVARN);
			decl_node *p_1 = new decl_node(convert->type, "from", nullptr, nullptr
			, UNDEFVARN);
			p_1->set_left(p_2);
			store = new Proc_Value(p_1, convert->body, true, PROCV);
			std::string f_name = "CONVERT_" + record->type_name + "_FROM_" + convert->type;
			std::cout << "HEREKSDHGKJSNDBGSSBGU\n";
			std::cout << f_name << "\n";
		    if (!functions.add(f_name, store))
			{
			       	throw(std::runtime_error("multiple definition of function"));
			}
		}
	}
	else if (ptr->operation >= 22 && ptr->operation <= 25) //MOVE
	{
		//std::cout << "MOVE!!!! " << ptr->operation << "\n";
		int res = parse_move(ptr, rob, stab);
		//rob->print_field();
	}
	else
	{
		throw(std::runtime_error("wrong expr"));
	}
}

std::unordered_map<std::string, Value*> tree_parser::copy_fields(std::unordered_map<std::string, Value*> &fields)
{
	std::unordered_map<std::string, Value*> m;
	for (auto &c : fields)
	{
		if (c.second->type == "NUMERIC")
		{
			Int_Value *temp = dynamic_cast<Int_Value*>(c.second);
			Int_Value *n = new Int_Value("NUMERIC", temp->size, temp->val[0], false, VAR);
			m[c.first] = n;
		}
		else if (c.second->type == "STRING")
		{
			Char_Value *temp = dynamic_cast<Char_Value*>(c.second);
			Char_Value *n = new Char_Value("STRING", temp->size, temp->val[0], false, VAR);
			m[c.first] = n;
		}
		else if (c.second->type == "LOGIC")
		{
			Bool_Value *temp = dynamic_cast<Bool_Value*>(c.second);
			Bool_Value *n = new Bool_Value("LOGIC", temp->size, temp->val[0], false, VAR);
			m[c.first] = n;
		}
	}
	return m;
}

bool tree_parser::parse_ping(node *ptr, robot *r, symbol_table &stab)
{
	ping_node *ping = dynamic_cast<ping_node*>(ptr);
	if (ping->child->operation != INTN)
	{
		throw(std::runtime_error("parameter of PING functions must be a number"));
	}
	int steps = parse_int(ping->child, stab, r);
	bool res;
	switch(ptr->operation)
	{
		case(26):
			res = r->PUP(steps);
			break;
		case(27):
			res = r->PRIGHT(steps);
			break;
		case(28):
			res = r->PLEFT(steps);
			break;
		case(29):
			res = r->PDOWN(steps);
			break;
	}
	return res;
}

int tree_parser::parse_move(node *ptr, robot *r, symbol_table &stab)
{
	move_node *move = dynamic_cast<move_node*>(ptr);
	if (move->child->operation != INTN && move->child->operation != STRN)
	{
		throw(std::runtime_error("parameter of MOVE functions must be a number"));
	}
	int steps = parse_int(move->child, stab, r);
	//std::cout << ptr->operation << "\n";
	int res;
	switch(ptr->operation)
	{
		case(22):
			res = r->MRIGHT(steps);
			break;
		case(23):
			res = r->MLEFT(steps);
			break;
		case(24):
			res = r->MUP(steps);
			break;
		case(25):
			res = r->MDOWN(steps);
			break;
	}
	return res;
}

void tree_parser::get_fields(node *child, std::unordered_map<std::string, Value*>& struct_fields)
{
	if (child->left)
	{
		get_fields(child->left, struct_fields);
	}
	if (child->operation == VARN || child->operation == UNDEFVARN)
	{
		decl_node *cur = dynamic_cast<decl_node*>(child);
		Value *t;
		bool d = child->operation == VARN ? true : false;
		if (cur->type == "STRING")
		{
			str_node *val = dynamic_cast<str_node*>(cur->child);
			//std::cout << "HERE BRBR " <<  s->str << "\n";
			std::string s = child->operation == UNDEFVARN ? "" : val->str;
			t = new Char_Value("STRING", 1, s, d, VAR);
			struct_fields[cur->var_name] = t;
		}
		else if (cur->type == "NUMERIC")
		{
			int_node *val = dynamic_cast<int_node*>(cur->child);
			int s = child->operation == UNDEFVARN ? 0 : val->value;
			t = new Int_Value("NUMERIC", 1, s, d, VAR);
			struct_fields[cur->var_name] = t;
		}
		else if (cur->type == "LOGIC")
		{
			bool_node *val = dynamic_cast<bool_node*>(cur->child);
			bool s = child->operation == UNDEFVARN ? 0 : val->value;
			t = new Bool_Value("LOGIC", 1, s, d, VAR);
			struct_fields[cur->var_name] = t;
		}
	}
	else
	{
		throw(std::runtime_error("wrong filed in struct"));
	}
}

void tree_parser::assign_params (node *func_params, node *call_params, symbol_table &local, symbol_table &lglobal)
{
	if (call_params->left && func_params->left)
	{
		assign_params(func_params->left, call_params->left, local, lglobal);
	}
	decl_node *f = dynamic_cast<decl_node*>(func_params);
	//std::cout << (f == nullptr) << "\n";
	//if (call_params->operation != STRN)
	// {throw (std::runtime_error("parameter of function must be a reference on global variable"));}
	if (call_params->operation == STRN)
	{
		str_node *s = dynamic_cast<str_node*>(call_params);
		Value *v;
		if (!(v = lglobal.find_var(s->str)))
		{
			//std::cout << s->str << "\n";
			//lglobal.print();
			throw (std::runtime_error("global variable put as func parameter wasn't found"));
		}
		//std::cout << s->str << "\n";
		local.add(f->var_name, v);
	}
	else
	{
		if (call_params->operation == INTN)
		{
			int_node *s = dynamic_cast<int_node*>(call_params);
			Value *v = new Int_Value("NUMERIC", 1, s->value, true, VAR);
			local.add(f->var_name, v);
		}
		else if (call_params->operation == STRUCTREFN)
		{
			struct_ref_node *s = dynamic_cast<struct_ref_node*>(call_params);
			if (!local.storval.contains(s->struct_name))
			{
				throw(std::runtime_error("Structure doesn't exist"));
			}
			Value *v = local.storval[s->struct_name];
			Record_Value *r = dynamic_cast<Record_Value*>(v);
			local.add(f->var_name, r->fields[s->struct_field]);
		}
	}
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

int tree_parser::parse_bool(node *ptr, symbol_table& stab, robot *rob)
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
                                return parse_bool(ptr->left, stab, rob) ^ parse_bool(ptr->right, stab, rob);
                                break;
                        case(5):
                                return parse_bool(ptr->left, stab, rob) || parse_bool(ptr->right, stab, rob);
                                break;
                        case(6):
                                return parse_bool(ptr->left, stab, rob) && parse_bool(ptr->right, stab, rob);
                                break;
                        case(7):
                                return !(parse_bool(ptr->left, stab, rob) && parse_bool(ptr->right, stab, rob));
                                break;
                        case(8):
                               return parse_bool(ptr->left, stab, rob) == parse_bool(ptr->right, stab, rob);
                               break;
                        case(9):
	                        	return parse_bool(ptr->left, stab, rob) != parse_bool(ptr->right, stab, rob);
	                        	break;
                        case(10):
	                        	return !(parse_bool(ptr->left, stab, rob) || parse_bool(ptr->right, stab, rob));
	                        	break;
                        case(11):
	                        	return parse_bool(ptr->left, stab, rob) < parse_bool(ptr->right, stab, rob);
	                        	break;
                        case(12):
	                        	return parse_bool(ptr->left, stab, rob) > parse_bool(ptr->right, stab, rob);
	                        	break;
                }
        }
        else if (ptr->operation == 13)
        {
        	return !parse_bool(ptr->left, stab, rob);
        }
		else if (ptr->operation == STRN)
		{
			str_node *temp = dynamic_cast<str_node*>(ptr);
			std::string s = "CONVERT_" + stab.storval[temp->str]->type + "_TO_LOGIC";
			std::cout << s << "\n";
			if(stab.storval.contains(temp->str) && (stab.storval[temp->str]->type == "NUMERIC" || stab.storval[temp->str]->type == "LOGIC") &&
			 stab.storval[temp->str]->size == 1)
			{
				if (stab.storval[temp->str]->type == "NUMERIC")
				{
					Int_Value *temp_2 = dynamic_cast<Int_Value*>(stab.storval[temp->str]);
					return *(temp_2->val);
				}
				else if (stab.storval[temp->str]->type == "LOGIC")
				{
					Bool_Value *temp_2 = dynamic_cast<Bool_Value*>(stab.storval[temp->str]);
					return *(temp_2->val);
				}
			}
			else if (stab.storval.contains(temp->str) && functions.storval.contains(s))
			{
				proc_node *func = dynamic_cast<proc_node*>(functions.storval[s]);
				decl_node *ut = new decl_node("NUMERIC", "to", nullptr, nullptr, UNDEFVARN);
				str_node *u = new str_node("to", STRN);
				parse(ut, stab, rob);
				std::cout <<"TEMP->STR: " << temp->str << "\n";
				str_node *v = new str_node(temp->str, STRN);
				Record_Value *r_t = dynamic_cast<Record_Value*>(stab.storval[temp->str]);
				u->set_left(v);
				node *t = new proc_node(s, u, nullptr,  CALLN);
				parse(t, stab, rob);
				Int_Value *res = dynamic_cast<Int_Value*>(stab.storval["to"]);
				int result = res->val[0];
				stab.storval.erase("to");
				return result;
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
			int index = parse_int(temp->index, stab, rob);
			if(stab.storval.contains(name) && stab.storval[name]->type == "NUMERIC" &&
			 index < stab.storval[name]->size )
			{
				Int_Value *temp_2 = dynamic_cast<Int_Value*>(stab.storval[name]);
				return temp_2->val[index];
			}
		}
		else if(ptr->operation == STRUCTREFN)
		{
			struct_ref_node *temp = dynamic_cast<struct_ref_node*>(ptr);
			std::string struct_name = temp->struct_name, field_name = temp->struct_field;
			if (!stab.storval.contains(struct_name))
			{
				throw(std::runtime_error("struct wasn't declared"));
			}
			Record_Value *record = dynamic_cast<Record_Value*>(stab.storval[struct_name]);
			if(record->fields.contains(field_name) && (record->fields[field_name]->type == "NUMERIC" || record->fields[field_name]->type == "LOGIC"))
			{
				Value *val = record->fields[field_name];
				Int_Value *temp_2 = dynamic_cast<Int_Value*>(record->fields[field_name]);
				return temp_2->val[0];
			}
		}
		else if (ptr->operation >= 22 && ptr->operation <= 25)
		{
			return parse_move(ptr, rob, stab);
		}
		else if (ptr->operation >= 26 && ptr->operation <= 29)
		{
			return parse_ping(ptr, rob,stab);
		}
        else
        {
                throw (std::runtime_error("wrong expression from the right side of ="));
        }
        return 0;
}

int tree_parser::parse_int(node *ptr, symbol_table& stab, robot *rob)
{
	if (ptr->operation == INTN)
	{
		int_node *temp = dynamic_cast<int_node*>(ptr);
		if (!temp->left && !temp->right)
		{
			return temp->value;
		}
	}
    else if (ptr->operation == BOOLN)
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
					return parse_int(ptr->left, stab, rob) - parse_int(ptr->right, stab, rob);
					break;
				case(5):
	                return parse_int(ptr->left, stab, rob) + parse_int(ptr->right, stab, rob);
	                break;
				case(6):
	                return parse_int(ptr->left, stab, rob) * parse_int(ptr->right, stab, rob);
	                break;
	            case(7):
	                return parse_int(ptr->left, stab, rob) / parse_int(ptr->right, stab, rob);
	                break;
	            case(8):
	            	return pow(parse_int(ptr->left, stab, rob), parse_int(ptr->right, stab, rob));
	            	break;
	            case(9):
	            	return parse_int(ptr->left, stab, rob) != parse_int(ptr->right, stab, rob);
	            	break;
	            case(10):
	            	return parse_int(ptr->left, stab, rob) == parse_int(ptr->right, stab, rob);
	            	break;
	            case(11):
	            	return parse_int(ptr->left, stab, rob) < parse_int(ptr->right, stab, rob);
	            	break;
	            case(12):
	            	return parse_int(ptr->left, stab, rob) > parse_int(ptr->right, stab, rob);
	            	break;
			}
	}
 	else if (ptr->operation == 13)
	    {
	    	return -parse_int(ptr->left, stab, rob);
	    }
	else if (ptr->operation == STRN)
	{
		str_node *temp = dynamic_cast<str_node*>(ptr);
		std::string s = "CONVERT_" + stab.storval[temp->str]->type + "_TO_NUMERIC";
		std::cout << s << "\n";
		if(stab.storval.contains(temp->str) && stab.storval[temp->str]->type == "NUMERIC" &&
		 stab.storval[temp->str]->size == 1)
		{
				Int_Value *temp_2 = dynamic_cast<Int_Value*>(stab.storval[temp->str]);
				return *(temp_2->val);
		}
		else if (stab.storval.contains(temp->str) && functions.storval.contains(s))
		{
			proc_node *func = dynamic_cast<proc_node*>(functions.storval[s]);
			decl_node *ut = new decl_node("NUMERIC", "to", nullptr, nullptr, UNDEFVARN);
			str_node *u = new str_node("to", STRN);
			parse(ut, stab, rob);
			std::cout <<"TEMP->STR: " << temp->str << "\n";
			str_node *v = new str_node(temp->str, STRN);
			Record_Value *r_t = dynamic_cast<Record_Value*>(stab.storval[temp->str]);
			u->set_left(v);
			node *t = new proc_node(s, u, nullptr,  CALLN);
			parse(t, stab, rob);
			Int_Value *res = dynamic_cast<Int_Value*>(stab.storval["to"]);
			int result = res->val[0];
			stab.storval.erase("to");
			return result;
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
		int index = parse_int(temp->index, stab, rob);
		if(stab.storval.contains(name) && stab.storval[name]->type == "NUMERIC" &&
		 index < stab.storval[name]->size)
		{
			Int_Value *temp_2 = dynamic_cast<Int_Value*>(stab.storval[name]);
			return temp_2->val[index];
		}
	}
	else if(ptr->operation == STRUCTREFN)
	{
		struct_ref_node *temp = dynamic_cast<struct_ref_node*>(ptr);
		std::string struct_name = temp->struct_name, field_name = temp->struct_field;
		if (!stab.storval.contains(struct_name))
		{
			throw(std::runtime_error("struct wasn't declared"));
		}
		Record_Value *record = dynamic_cast<Record_Value*>(stab.storval[struct_name]);
		if(record->fields.contains(field_name) && record->fields[field_name]->type == "NUMERIC")
		{
			Value *val = record->fields[field_name];
			Int_Value *temp_2 = dynamic_cast<Int_Value*>(record->fields[field_name]);
			return temp_2->val[0];
		}
	}
	else if (ptr->operation >= 22 && ptr->operation <= 25)
	{
		return parse_move(ptr, rob, stab);
	}
	else if (ptr->operation >= 26 && ptr->operation <= 29)
	{
		return parse_ping(ptr, rob,stab);
	}
	else
	{
		throw (std::runtime_error("wrong expression from the right side of ="));
	}
	return 0;
}
