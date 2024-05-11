#include <iostream>
#include <cstring>
#ifndef AST
#define AST	
#include "nodes.h"
#endif
#define VAR 1
#define PROCV 2

class Value
{
	public:
		bool defined;
		int size;
		std::string type;
		int operation;
		Value(std::string type, int size, bool defined, int operation)
		{
			this->type = type;
			this->size = size;
			this->defined = defined;
			this->operation = operation;
		}
		virtual ~Value() {};
		virtual void print() = 0;
};

class Proc_Value : public Value
{
	public:
		node *parameters, *body;
		Proc_Value(node *parameters, node *body, bool defined, int operation) : Value("", 1, defined, operation)
		{
			this->parameters = parameters;
			this->body = body;
		}
		void print() override
		{
			std::cout << "func\n";
		}
		~Proc_Value() {}
};

class Int_Value : public Value
{
	public:
		int *val;
		Int_Value(std::string type, int size, int val, bool defined, int operation) : Value(type, size, defined, operation)
		{
			this->val = new int[size];
			if (defined)
			{
	            for (int i = 0; i < size; i++)
	            {
	            	this->val[i] = val;
	            }
        	}
		}
		void print() override
		{
			for (int i = 0; i < size; i++)
			{
				std::cout << "ind: " <<  i << " val: " << val[i] << "\n";
			}
		}
		~Int_Value() override {  delete[] val;}
};

class Bool_Value : public Value
{
    public:
 			bool *val;
            Bool_Value(std::string type, int size, bool val, bool defined, int operation) : Value(type, size, defined, operation)
            {
                    this->val = new bool [size];
                    if (defined)
                    {
	                    for (int i = 0; i < size; i++)
	                    {
	                    	this->val[i] = val;
	                    }
                	}
            }
			void print() override
			{
				for (int i = 0; i < size; i++)
				{
					std::cout << "ind: " <<  i << " val: " << val[i] << "\n";
				}
			}
            ~Bool_Value() override {  delete[] val;}
};

class Char_Value : public Value
{
    public:
 			std::string *val;
            Char_Value(std::string type, int size, std::string val, bool defined, int operation) : Value(type, size, defined, operation)
            {
                    this->val = new std::string[size];
                    if (defined)
                    {
	                    this->val[0] = val;
                    }
            }
			void print() override
			{
				for (int i = 0; i < size; i++)
				{
					std::cout << "ind: " <<  i << " val: " << val[i] << "\n";
				}
			}
            ~Char_Value() override
            {
            		delete[] val;
            }
};
