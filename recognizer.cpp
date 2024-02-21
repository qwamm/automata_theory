#include "recognizer.hpp"
#include "statemap.h"

Recognizer::Recognizer() : recognizerContext(*this), isCorrect(false)
{
	Parameter = false;
	param_len = 0;
	setDebugFlag(true);
}

bool Recognizer::check_string (std::string str)
{
	enterStartState();
	for (auto &c : str)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			letter(c);
		}
		if (c >= '0' && c <= '9')
		{
			digit(c);
		}
		if(c == ' ' || c == ',')
		{
			s_push(c);
		}
		if (c == ')' || c == '(')
		{
			parent(c);
		}
		if (c == ';')
		{
			letter(c);
		}
	}
	EOS();
	return isCorrect;
}
