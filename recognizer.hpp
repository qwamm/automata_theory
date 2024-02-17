#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <vector>
#include <fstream>
#include "recognizer_sm.h"

class Recognizer : public recognizerContext
{
	private:
		bool isCorrect;
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
		inline bool text_len(int l) const
		{
			return l>=function.size();
		}
		void save(std::ofstream &out);
		void NPush (char l)
		{
			function.push_back(l);
		}
};

#endif
