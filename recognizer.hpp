#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <vector>
#include <fstream>
#include "recognizer_sm.h"

class Recognizer : public recognizerContext
{
	private:
		bool isCorrect;
		int param_len;
		std::vector<char> function;
	public:
		Recognizer();
		~Recognizer() {};

		bool check_string (std::string str);
		inline void Correct()
		{
			isCorrect = true;
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
			function.push_back(l);
		}
};

#endif
