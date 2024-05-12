#include <iostream>
#include <cstring>
#include <cstdlib>
#include "ast.h"

class struct_ref_node : public node
{
	public:
		std::string struct_name, struct_field;
		struct_ref_node(std::string struct_name, std::string struct_field, int operation) : node(operation)
		{
			this->struct_name = struct_name;
			this->struct_field = struct_field;
		}
		void print_val() override
		{
			std::cout << "STRUCT_REF";
		}
		~struct_ref_node() {}
};

class conv_node : public node
{
	public:
		std::string type;
		node *body;
		conv_node(std::string type, node *body, int operation) : node(operation)
		{
			this->type = type;
			this->body = body;
		}
		void print_val() override 
		{
			std::cout << "CONV " << type;
		}
		~conv_node() {}
};

class record_node : public node
{
	public:
		std::string type_name;
		node *сhild, *conv_from, *conv_to;
        record_node(std::string type_name, node *child, node *conv_from, node *conv_to, int operation) : node(operation)
        {
                this->type_name = type_name;
				this->сhild = child;
				this->conv_from = conv_from;
				this->conv_to = conv_to;
        }
        void print_val() override
        {
                std::cout << "RECORD";
        }
        ~record_node() {}
};

class arr_node : public node
{
        public:
			node *name, *index;
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
        public:
 				node *child;
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
        public:
        		node *child;
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
        public:
 				node *child;
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
	public:
		node *child;
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
	public:
		std::string name;
		node *parameters, *body;
		proc_node(std::string name, node *parameters, node *body, int operation) : node (operation)
		{
			this->name = name;
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
	public:
		node *block, *condition;
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
	public:
		node *child;
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
	public:
		std::string str;
		str_node(std::string str, int operation) : node(operation)
		{
			this->str = str;
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
	public:
		node *left_op;
		node *child;
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
		std::string type;
		std::string var_name;
		node *size;
		node *child;
		decl_node(std::string type, std::string var_name, node *size, node *child, int operation) : node(operation)
		{
			this->size = size;
			this->type = type;
			this->var_name = var_name;
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
				std::cout << "UNDEFVAR ";
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
	public:
		bool value;
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
