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
	std::ifstream in;
	in.open("input.txt");
	while (!(in.eof()))
	{
		std::string s =  get_line(in);
		if (in.eof())
			break;
		t = clock();
		ret = read_line(rec, s);
		t = clock() - t;
		sum += ((float)t)/CLOCKS_PER_SEC;
		std:: cout << s << "| ret = " << ret << "\n";
		rec.reset();
	}
	std::cout << "TIME: " << sum << "\n";
	in.close();
}

std::string get_line(std::ifstream &in)
{
	std::string str;
	std::getline(in, str);
	return str;
}

bool read_line(Recognizer& rec, std::string str)
{
	bool ret;
	try
	{
		if (rec.check_string(str) == false)
		{
			ret = 0;
		}
		else
		{
			//rec.save(str);
			ret = 1;
		}
	}
	catch(const SmcException &e)
	{
		std::cout << "string " << str << "incorrect - " << e.what() << "\n";
		ret = 1;
	}
	return ret;
}
