#include "ast.h"

class str_node : public node
{
	char *str;
	public:
		str_node(char *string);
		~str_node();
};

class decl_node : public node
{
	char *type;
	node *left, *right;
	char *var_name;
	public:
		decl_node(char *type);
		~decl_node();
};

class int_node : public node
{
	int value;
	public:
		int_node(int value);
		~int_node();
};

class bool_node : public node
{
	bool value;
	public:
		bool_node(bool value);
		~bool_node();
};

class unary_node : public node
{
	node *child;
	public:
		unary_node(node *child, int operation) : node (operation)
		{
			this->child = child;
		}
};

class operation_node : public node
{
	node *left, *right;
	public:
		operation_node (node *left, node *right, int operation) : node(operation)
		{
			this->left = left;
			this->right = right;
		}
		~operation_node() {}
};

class null_node : public node
{
	public:
		null_node();
		~null_node();
};
