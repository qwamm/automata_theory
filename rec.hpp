#include <iostream>

class Recognizer
{
	protected:
		std::string fname;
	public:
		virtual bool check_string(std::string s) = 0;
		std::string get_fname()
		{
			return fname;
		}
};
