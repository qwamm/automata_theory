#include <iostream>
#include <fstream>
#include <chrono>
#include <FlexLexer.h>
int main()
{
        float sum = 0;
        yyFlexLexer flp;
        flp.switch_streams(std::cin, std::cout);
        while (1)
        {
                auto start = std::chrono::system_clock::now();
                if (flp.yylex() == 2)
                        break;
                auto end = std::chrono::system_clock::now();
                sum += (float)(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
        }
	if (rec.getState() == State::SEMICOLON)
        	std::cout << "OK" << "\n";
	else if (rec.getState() == State::ERROR)
		std::cout << "ERROR" << "\n";
	else
		std::cout << "MACHINE ERROR" << "\n";
        std::cout << "TIME: " << sum << "\n";
        std::cout << "OVERLOADS:\n";
        for (auto &pair : overloads)
        {
                std::cout << pair.first << "\t" << pair.second << "\n";
        }
}
