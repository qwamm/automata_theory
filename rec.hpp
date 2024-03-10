#include <iostream>

class Recognizer
{
	public:
		virtual bool check_string(std::string s, std::string *fname) = 0;
};
