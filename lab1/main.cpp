#include <iostream>
#include <chrono>
#include <unordered_map>
#include <FlexLexer.h>
#ifndef REC_HPP
#define REC_HPP
#include "rec.hpp"
#endif
#include "SMC_Recognizer.hpp"
#include "flex/flex_rec.hpp"
#include "regex/regex_rec.hpp"

void func(Recognizer &rec);

int main(int argc, char *argv[])
{
        //std::cout << "Choose option:\n";
        int x;
        //std::cin >> x;
	if (argc < 2)
	{
		std::cout << "No option chose\n";
		return -1;
	}
	std::cout << argv[1][0] << "\n";
        if (argv[1][0] == '1')
        {
                  SMC_Recognizer rec;
                  func(rec);
        }
        else if (argv[1][0] == '2')
        {
                 Flex_Recognizer rec;
                 func(rec);
        }
	else if (argv[1][0] == '3')
	{
		Regex_Recognizer rec;
		func(rec);
	}
}

void func(Recognizer &rec)
{
        std::string s;
        std::unordered_map<std::string, int> overloads;
        int i,j;
        float sum = 0;
	bool ret;
        while (std::getline(std::cin, s))
        {
		if (s.size() > 0)
		{
		std::string fname;
                auto start = std::chrono::system_clock::now();
                ret = rec.check_string(s);
                auto end = std::chrono::system_clock::now();
                sum += (float)(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
                if (ret == 1)
                {
			fname = rec.get_fname();
                        if (overloads.contains(fname))
                        {
                                overloads[std::move(fname)]++;
                        }
                        else
                        {
                                overloads[std::move(fname)] = 0;
                        }
                }
                std:: cout << s << " | ret = " << ret << "\n";
		}
        }
        std::cout << "TIME: " << sum << "\n";
        std::cout << "OVERLOADS:\n";
        for (auto &pair : overloads)
        {
                std::cout << pair.first << "\t" << pair.second << "\n";
        }
}
