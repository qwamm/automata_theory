#include <iostream>
#include <chrono>
#include <unordered_map>
#include <FlexLexer.h>
#include "rec.hpp"
int main()
{
        std::string fname, s;
        std::unordered_map<std::string, int> overloads;
        int i,j;
        Recognizer rec;
        float sum = 0;
        rec.check_strings(overloads, sum);
        std::cout << "TIME: " << sum << "\n";
        std::cout << "OVERLOADS:\n";
        for (auto &pair : overloads)
        {
                std::cout << pair.first << "\t" << pair.second << "\n";
        }
}
