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

void func(Recognizer &rec);

int main()
{
        std::cout << "Choose option:\n";
        int x;
        std::cin >> x;
        if (x == 1)
        {
                  SMC_Recognizer rec;
                  func(rec);      
        }
        else if (x == 2)
        {
                 Flex_Recognizer rec;
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
                ret = rec.check_string(s, &fname);
                auto end = std::chrono::system_clock::now();
                sum += (float)(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
                if (ret == 1)
                {
                        if (overloads.contains(fname))
                        {
                                overloads[fname]++;
                        }
                        else
                        {
                                overloads[fname] = 0;
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
