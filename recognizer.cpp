#include "recognizer.hpp"
#include "statemap.h"

Recognizer::Recognizer() : recognizerContext(*this), isCorrect(false)
{
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
		if(c == ' ')
		{
			s_push();
		}
	}
	EOS();
	return isCorrect;
}
