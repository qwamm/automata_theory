#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <vector>
#include <fstream>
#include "recognizer_sm.h"
#ifndef REC_HPP
#define REC_HPP
#include "rec.hpp"
#endif

class SMC_Recognizer : public recognizerContext, public Recognizer
{
	private:
		bool isCorrect;
		bool Parameter;
		int param_len;
		std::string function;
	public:
		SMC_Recognizer() : recognizerContext(*this), isCorrect(false)
		{
			Parameter = false;
			param_len = 0;
			setDebugFlag(true);
		}

		~SMC_Recognizer() {};

		bool check_string (std::string s, std::string *fname) override
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
			this->reset();
			param_len = 0;
			function.clear();
			return isCorrect;
		}

		inline void Correct()
		{
			isCorrect = true;
		}
		inline void setParameterTrue()
		{
			Parameter = true;
		}
                inline void setParameterFalse()
                {
                        Parameter = false;
                }
		inline bool isParameter()
		{
			return Parameter;
		}
		inline void Incorrect()
		{
			isCorrect = false;
		}
		inline void inc_len()
		{
			param_len++;
		}
		inline void reset_len()
		{
			param_len = 0;
		}
		inline bool text_len(int l) const
		{
			return l>=param_len;
		}
		void save(std::ofstream &out);
		void NPush (char l)
		{
			if (param_len == 0)
				function.clear();
                        for (auto &c : this->function)
                                std::cout << c << "\n";
			function.push_back(l);
		}
};

#endif
