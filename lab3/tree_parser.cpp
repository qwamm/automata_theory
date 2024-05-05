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
			std::cout << parse_int(temp->child) << "\n";
		 }
		 //Value *val = new Value(type, );
	}
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
		if (ptr->operation == 5)
		{
			std::cout << "OPERATION MARKER\n";
			return parse_int(ptr->left) +  parse_int(ptr->right);
		}
	}
	return 0;
}
