#include "tree_parser.h"

void tree_parser::parse(node *ptr)
{
	if(ptr->operation == VARN)
	{
		 decl_node *temp = dynamic_cast<decl_node*>(ptr);
		 char *type = temp->type;
		 char *var_name = temp->var_name;
		 std::cout << type << "\n";
		 if (strcmp(type, "NUMERIC") == 0)
		 {
			int val = parse_int(temp->child);
			std::cout << val << "\n";
			Value *store = new Int_Value(type, val);
			if (!stab.add(var_name, store))
			{
				throw("multiple definition of variable");
			}
		 }
		 else if(strcmp(type, "LOGIC") == 0)
		 {
			std::cout << "LOGIC TYPE\n";
			bool val = parse_bool(temp->child);
			std::cout << val << "\n";
			 std::cout << "LOGIC TYPE\n";
			Value *store = new Bool_Value(type, val);
                        if (!stab.add(var_name, store))
                        {
				std::cout << "HERE\n";
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
			Value *store = new Char_Value(type, val);
            if (!stab.add(var_name, store))
            {
                     throw(std::runtime_error("multiple definition of variable"));
            }
		 }
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
        else if (ptr->operation >= 4 && ptr->operation <= 7)
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
	else if (ptr->operation >= 4 && ptr->operation <= 7)
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
		}
	}
	else
	{
		throw ("wrong expression from the right side of =");
	}
	return 0;
}
