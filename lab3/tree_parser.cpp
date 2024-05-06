#include "tree_parser.h"

void tree_parser::parse(node *ptr)
{
	if (ptr->left)
		parse(ptr->left);
	if(ptr->operation == VARN)
	{
			 decl_node *temp = dynamic_cast<decl_node*>(ptr);
			 char *type = temp->type;
			 char *var_name = temp->var_name;
			 std::cout << type << "\n";
			 if (temp->size == nullptr)
			 {
					 if (strcmp(type, "NUMERIC") == 0)
					 {
						int val = parse_int(temp->child);
						std::cout << val << "\n";
						Value *store = new Int_Value(type, 1, val, true);
						if (!stab.add(var_name, store))
						{
							throw(std::runtime_error("multiple definition of variable"));
						}
					 }
					 else if(strcmp(type, "LOGIC") == 0)
					 {
						bool val = parse_bool(temp->child);
						std::cout << val << "\n";
						Value *store = new Bool_Value(type, 1, val, true);
                        if (!stab.add(var_name, store))
                        {
                                throw(std::runtime_error("multiple definition of variable"));
                        }
					 }
					 else if (strcmp(type, "STRING") == 0)
					 {
						str_node *sptr = dynamic_cast<str_node*>(temp->child);
						if (sptr->operation != LITERALN)
						{
							 throw(std::runtime_error("wrong type of variable"));
						}
						char *val = sptr->str;
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
		 char *type = temp->type;
		 char *var_name = temp->var_name;
		 std::cout << type << "\n";
		 int size;
		 if (temp->size != nullptr)
		 	size = parse_int(temp->size);
		 else
		 	size = 0;
		 if (strcmp(type, "NUMERIC") == 0)
		 {
			Value *store = new Int_Value(type, size, 0, false);
			if (!stab.add(var_name, store))
			{
				throw("multiple definition of variable");
			}
		 }
		 else if(strcmp(type, "LOGIC") == 0)
		 {
			Value *store = new Bool_Value(type, size, 0, false);
	                if (!stab.add(var_name, store))
	                {
	                        throw(std::runtime_error("multiple definition of variable"));
	                }
		 }
		 else if (strcmp(type, "STRING") == 0)
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
	}
}

bool tree_parser::parse_bool(node *ptr)
{
        if (ptr->operation == BOOLN)
        {
				std::cout << "HERE\n";
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
		if(stab.storval.contains(temp->str) && strcmp(stab.storval[temp->str]->type, "STRING") == 0 &&
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
	else if (ptr->operation >= 4 && ptr->operation <= 8)
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
		str_node *temp = dynamic_cast<str_node*>(ptr);
		if(stab.storval.contains(temp->str) && strcmp(stab.storval[temp->str]->type, "NUMERIC") == 0 &&
		 stab.storval[temp->str]->size == 1)
		{
			Int_Value *temp_2 = dynamic_cast<Int_Value*>(stab.storval[temp->str]);
			return *(temp_2->val);
		}
	}
	else
	{
		throw (std::runtime_error("wrong expression from the right side of ="));
	}
	return 0;
}
