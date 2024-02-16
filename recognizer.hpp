#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <vector>
#include <fstream>
#include "recognizer_sm.h"

class Recognizer
{
	private:
		bool isCorrect;
		std::vector<char> function;
	public:
		Recognizer() {}
		~Recognizer() {}
		bool check_string (std::string str);
		inline void Correct()
		{
			isCorrect = true;
		}
		inline void Uncorrect()
		{
			isCorrect = false;
		}
		void save(std::ofstream &out);
};

#endif
