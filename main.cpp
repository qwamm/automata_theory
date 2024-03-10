#include <iostream>
#include <fstream>
#include <compare>
#include <string>
#include <chrono>
#include <ctime>
#include "recognizer.hpp"
#include "recognizer_sm.h"
#include "statemap.h"

using namespace statemap;

std::string get_line(std::ifstream &in);
bool read_line(Recognizer& rec, std::string str);

int main()
{
	float sum = 0;
	//std::time_t t;
	bool ret;
	Recognizer rec;
	std::string s;
	while (std::getline(std::cin, s))
	{
		auto start = std::chrono::system_clock::now();
		ret = read_line(rec, s);
		auto end = std::chrono::system_clock::now();
		sum += (float)(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
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
