#include <iostream>
#include <fstream>
#include <regex>

std::string get_line(std::ifstream &in);
bool check_string(std::string str);

int main()
{
        bool ret;
        std::ifstream in;
        in.open("input.txt");
        while (!(in.eof()))
        {
                std::string s =  get_line(in);
                if (in.eof())
                        break;
                ret = check_string(s);
                std:: cout << s << " ret = " << ret << "\n";
        }
        in.close();
}

bool check_string(std::string str)
{
	  std::regex reg ("(\\b(?:int|long|short)\\b\\s[^0-9][A-Za-z0-9]{0,15}\\((((\\b(?:int|long|short)\\b\\s[^0-9][A-Za-z0-9]{0,16}))((\\,(?!\\)))?))*\\)\\;)",  std::regex_constants::ECMAScript);
	  std::smatch m;
	  bool r = std::regex_match(str, m, reg);
	  std::cout << m[0] << "\n";
	  return r;
}

std::string get_line(std::ifstream &in)
{
        std::string str;
        std::getline(in, str);
        return str;
}
