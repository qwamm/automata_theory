#include "SMC_Recognizer.hpp"
#include "statemap.h"
//#include "rec.hpp"

SMC_Recognizer::SMC_Recognizer() : recognizerContext(*this), isCorrect(false)
{
	Parameter = false;
	param_len = 0;
	setDebugFlag(true);
}

bool SMC_Recognizer::check_string (std::string s, std::string *fname) override
{
	enterStartState();
	for (auto &c : s)
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
	for (auto &c : this->function)
		(*fname).push_back(c);
	return isCorrect;
}
