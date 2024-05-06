#include <iostream>
#include <cstring>

class Value
{
	public:
		bool defined;
		int size;
		std::string type;
		Value(std::string type, int size, bool defined)
		{
			this->type = type;
			this->size = size;
			this->defined = defined;
		}
		virtual ~Value() {};
		virtual void print() = 0;
};

class Int_Value : public Value
{
	public:
		int *val;
		Int_Value(std::string type, int size, int val, bool defined) : Value(type, size, defined)
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
            Bool_Value(std::string type, int size, bool val, bool defined) : Value(type, size, defined)
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
            Char_Value(std::string type, int size, std::string val, bool defined) : Value(type, size, defined)
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
