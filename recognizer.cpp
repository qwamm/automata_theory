#include "recognizer.hpp"

bool Recognizer::check_string (std::string str)
{
	for (auto &c : str)
	{
		if (c >= 'A' && c <= 'Z')
		{
			letter(c);
		}
		if (c >= '0' && c <= '9')
		{
			digit(c);
		}
		if(c == ' ')
		{
			WhiteSpace();
		}
	}
}
