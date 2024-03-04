#include <iostream>
#include <fstream>
#include <compare>
#include <string>
#include "time.h"
#include "recognizer.hpp"
#include "recognizer_sm.h"
#include "statemap.h"

using namespace statemap;

std::string get_line(std::ifstream &in);
bool read_line(Recognizer& rec, std::string str);

int main()
{
	float sum = 0;
	clock_t t;
	bool ret;
	Recognizer rec;
	std::string s;
	while (std::getline(std::cin, s))
	{
		//std::string s;
		//std::cin >> s;
		t = clock();
		ret = read_line(rec, s);
		t = clock() - t;
		sum += ((float)t)/CLOCKS_PER_SEC;
		std:: cout << s << " | ret = " << ret << "\n";
		rec.reset();
		rec.setParameterFalse();
	}
	std::cout << "TIME: " << sum << "\n";
}

std::string get_line(std::ifstream &in)
{
	std::string str;
	std::getline(in, str);
	return str;
}

bool read_line(Recognizer& rec, std::string str)
{
	try
	{
		return rec.check_string(str);
	}
	catch(const SmcException &e)
	{
		std::cout << "string " << str << "incorrect - " << e.what() << "\n";
		return 0;
	}
}
