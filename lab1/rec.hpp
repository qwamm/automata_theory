#include <iostream>

class Recognizer
{
	protected:
		std::string fname;
	public:
		virtual bool check_string(const std::string& s) = 0;
		virtual ~Recognizer() = default;
		std::string get_fname()
		{
			return fname;
		}
};
