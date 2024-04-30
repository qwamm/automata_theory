#include <iostream>
#include "ast.h"

class str_node : public node
{
	char *str;
	public:
		str_node(char *string, int operation) : node(operation)
		{
			this->str = string;
		}
		void print_val() override
		{
			std::cout << this->str;
		}
		~str_node(){}
};

class undef_node : public node
{
	public:
		undef_node() : node(UNDEFVARN) {}
		void print_val() override
		{
			std::cout << "UNDEF\n";
		}
		~undef_node(){}
};

class decl_node : public node
{
	char *type;
	char *var_name;
	public:
		decl_node(char *type, char *var_name, node *child, int operation) : node(operation)
		{
			this->type = type;
			this->var_name = var_name;
			right = child;
		}
                void print_val() override
                {
			if (operation == VARN)
                        	std::cout << "VAR";
			else
				std::cout << "UNDEFVAR";
                }
		~decl_node() {}
};

class int_node : public node
{
	int value;
	public:
		int_node(int value, int operation) : node(operation)
		{
			this->value = value;
		}
                void print_val() override
                {
                        std::cout << value;
                }
		~int_node();
};

class bool_node : public node
{
	bool value;
	public:
		bool_node(bool value, int operation) : node(operation)
		{
			this->value = value;
		}
                void print_val() override
                {
                        std::cout << value;
                }
		~bool_node();
};

class unary_node : public node
{
	public:
		unary_node(node *child, int operation) : node (operation)
		{
			this->left = child;
		}
		void print_val() override
		{
			std::cout << "\n";
		}
};

class operation_node : public node
{
	public:
		operation_node (node *left, node *right, int operation) : node(operation)
		{
			this->left = left;
			this->right = right;
		}
                void print_val() override
                {
                       	switch(operation)
			{
				case PLUSN:
					std::cout << "+";
					break;
				case NEGN:
					std::cout << "-";
					break;
				case MULN:
					std::cout << "*";
					break;
				case DIVN:
					std::cout << "/";
					break;
				case EQUN:
					std::cout << "?";
					break;
				case NOTEQUN:
					std::cout << "!";
					break;
				case EXPN:
					std::cout << "^";
					break;
				case LESSN:
					std::cout << "<";
					break;
				case GREATERN:
					std::cout << ">";
					break;
			}
                }
		~operation_node() {}
};

class null_node : public node
{
	public:
		null_node() : node(0)
 		{

		}
		void print_val() override
		{

		}
		~null_node() {}
};
