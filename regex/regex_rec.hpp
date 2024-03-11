#include <iostream>
#include <regex>
#ifndef REC_HPP
#define REC_HPP
#include "../rec.hpp"
#endif
class Regex_Recognizer : public Recognizer
{
	public:
		bool check_string(std::string s) override
		{
          		std::regex reg ("(?:int|long|short)(\\s{1,})(([^0-9 ])([A-Za-z0-9]{0,15}))\\(((((?:int|long|short)(\\s){1,}[^0-9 ][A-Za-z0-9]{0,16}))((\\,(?!\\))(\\s){0,})?))*\\)\\;",  std::regex_constants::ECMAScript | std::regex::optimize);
			std::smatch m;
          		bool r = std::regex_match(s, m, reg);
          		fname = m[2];
          		return r;
		}
};
