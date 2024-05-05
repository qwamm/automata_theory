#include <iostream>
#include <cstring>

class Value
{
	char *type;
	public:
		Value(char *type)
		{
			this->type = new char[strlen(type) + 1];
			strcpy(this->type, type);
		}
		~Value()
		{
			delete type;
		}
};

class Int_Value : public Value
{
	int val;
	public:
		Int_Value(char *type, int val) : Value(type)
		{
			this->val = val;
		}
		~Int_Value() {}
};

class Bool_Value : public Value
{
	bool val;
        public:
                Bool_Value(char *type, bool val) : Value(type)
                {
                        this->val = val;
                }
                ~Bool_Value() {}
};

class Char_Value : public Value
{
	char *val;
        public:
                Char_Value(char *type, char *val) : Value(type)
                {
                        this->val = new char[strlen(val) + 1];
			strcpy(this->val, val);
                }
                ~Char_Value() {}
};
