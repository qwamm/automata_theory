#include <iostream>
#include <cstring>
#include <cstdlib>
#include "ast.h"

class arr_node : public node
{
	node *name, *index;
        public:
                arr_node(node *name, node *index, int operation) : node(operation)
                {
                        this->name = name;
			this->index = index;
                }
                void print_val() override
                {
                        std::cout << "ARR";
                }
                ~arr_node() {}
};

class voice_node : public node
{
        node *child;
        public:
                voice_node(node *child, int operation) : node(operation)
                {
                        this->child = child;
                }
                void print_val() override
                {
                        std::cout << "VOICE";
                }
                ~voice_node() {}
};

class vision_node : public node
{
        node *child;
        public:
                vision_node(node *child, int operation) : node(operation)
                {
                        this->child = child;
                }
                void print_val() override
                {
                        std::cout << "VISION";
                }
                ~vision_node() {}
};

class ping_node : public node
{
        node *child;
        public:
                ping_node(node *child, int operation) : node(operation)
                {
                        this->child = child;
                }
                void print_val() override
                {
                        std::cout << "PING";
                }
                ~ping_node() {}
};

class move_node : public node
{
	node *child;
	public:
		move_node(node *child, int operation) : node(operation)
		{
			this->child = child;
		}
                void print_val() override
                {
                        std::cout << "MOVE";
                }
                ~move_node() {}
};

class proc_node : public node //procedures declaration and calling
{
	char *name;
	node *parameters, *body;
	public:
		proc_node(char *name, node *parameters, node *body, int operation) : node (operation)
		{
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
			this->body = body;
			this->parameters = parameters;
		}
                void print_val() override
                {
			if (operation == PROCN)
                        	std::cout << "PROC";
			else if (operation == CALLN)
				std::cout << "CALL";
                }
                ~proc_node() {}
};

class cond_node : public node
{
	node *block, *condition;
	public:
		cond_node(node *condition, node *block, int operation) : node(operation)
		{
			this->block = block;
			this->condition = condition;
		}
                void print_val() override
                {
                        std::cout << "COND";
                }
                ~cond_node() {}
};

class block_node : public node
{
	node *child;
	public:
		block_node(node *child, int operation) : node(operation)
		{
			this->child = child;
		}
		void print_val() override
		{
			std::cout << "BLOCK";
		}
		~block_node() {}
};

class str_node : public node
{
	char *str;
	public:
		str_node(char *string, int operation) : node(operation)
		{
			this->str = copy_str(string);
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

class assign_node : public node
{
	node *left_op;
	node *child;
	public:
		assign_node(node *left_op, node *child, int operation) : node(operation)
		{
			this->left_op = left_op;
			this->child = child;
		}
		~assign_node() {}
		void print_val() override
		{
			std::cout << "ASSIGN ";
			child->print_val();
		}
};

class decl_node : public node
{
	public:
	char *type;
	char *var_name;
	int size;
	node *child;
		decl_node(char *type, char *var_name, int size, node *child, int operation) : node(operation)
		{
			this->size = size;
			this->type = copy_str(type);
			this->var_name = copy_str(var_name);
			this->child = child;
		}
                void print_val() override
                {
			if (operation == VARN)
			{
                        	std::cout << "VAR ";
				child->print_val();
			}
			else
			{
				std::cout << "UNDEFVAR " << this->size;
			}
                }
		~decl_node() {}
};

class int_node : public node
{
	public:
		int value;
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
