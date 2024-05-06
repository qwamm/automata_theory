#include <iostream>
#include <cstring>

class Value
{
	protected:
		bool defined;
	public:
		int size;
		char *type;
		Value(char *type, int size, bool defined)
		{
			this->type = new char[strlen(type) + 1];
			strcpy(this->type, type);
			this->size = size;
			this->defined = defined;
		}
		virtual ~Value() {};
};

class Int_Value : public Value
{
	public:
		int *val;
		Int_Value(char *type, int size, int val, bool defined) : Value(type, size, defined)
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
		~Int_Value() override { delete type; delete[] val;}
};

class Bool_Value : public Value
{
	bool *val;
    public:
            Bool_Value(char *type, int size, bool val, bool defined) : Value(type, size, defined)
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
            ~Bool_Value() override { delete type; delete[] val;}
};

class Char_Value : public Value
{
	char **val;
    public:
            Char_Value(char *type, int size, char *val, bool defined) : Value(type, size, defined)
            {
                    this->val = new char*[size];
                    if (defined)
                    {
	                    for (int i = 0; i < size; i++)
	                    {
	                    	this->val[i] = new char[strlen(val) + 1]; 
	                    	strcpy(this->val[i], val);
	                    }
                    }
            }
            ~Char_Value() override
            {
            		delete type;
            		for (int i = 0; i < size; i++)
            		{
            			delete[] val[i];
            		}
            		delete[] val;
            }
};
