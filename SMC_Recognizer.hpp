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
	public:
		SMC_Recognizer() : recognizerContext(*this), isCorrect(false)
		{
			Parameter = false;
			param_len = 0;
			setDebugFlag(true);
		}

		~SMC_Recognizer() {};

		bool check_string (std::string s) override
		{
			this->reset();
			fname.clear();
			param_len = 0;
			Parameter = false;
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
			fname.push_back(l);
		}
};

#endif