#include <iostream>
#include <fstream>
#include <compare>
#include <string>
#include "recognizer.hpp"
#include "recognizer_sm.h"
#include "statemap.h"

using namespace statemap;

std::string get_line(std::ifstream &in);
bool read_line(Recognizer& rec, std::string str);

int main()
{
	bool ret;
	Recognizer rec;
	std::ifstream in;
	in.open("input.txt");
	while (!(in.eof()))
	{
		std::string s =  get_line(in);
		if (in.eof())
			break;
		ret = read_line(rec, s);
		std:: cout << s << " ret = " << ret << "\n";
		rec.reset();
	}
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
			ret = 1;
		}
		else
		{
			//rec.save(str);
			ret = 0;
		}
	}
	catch(const SmcException &e)
	{
		std::cout << "string " << str << "incorrect - " << e.what() << "\n";
		ret = 1;
	}
	return ret;
}
