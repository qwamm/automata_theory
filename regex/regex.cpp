#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_map>

std::string get_line(std::ifstream &in);
bool check_string(std::string str);
std::string get_fname(std::string s);

int main()
{
        bool ret;
        std::ifstream in;
        in.open("input.txt");
	std::unordered_map<std::string, int> overloads;
        while (!(in.eof()))
        {
                std::string s =  get_line(in);
                if (in.eof())
                        break;
                ret = check_string(s);
		if (ret == 1)
		{
			std::string fname = get_fname(s);
			if (overloads.contains(fname))
			{
				overloads[fname]++;
			}
			else
			{
				overloads[fname] = 0;
			}
		}
                std:: cout << s << " ret = " << ret << "\n";
        }
	std::cout << "OVERLOADS:\n";
	for (auto &pair : overloads)
	{
		std::cout << pair.first << "\t" << pair.second << "\n";
	}
        in.close();
}

std::string get_fname (std::string s)
{
	std::string fname;
	int i;
	for (i = 0; ;)
	{
		if (s[i] != ' ')
			i++;
		else
			break;
	}
	while (s[i] == ' ')
		i++;
	for (int j = i; s[j] != ' ' && s[j] != '('; j++)
	{
		fname.push_back(s[j]);
	}
	return fname;
}

bool check_string(std::string str)
{
	  std::regex reg ("(?:int|long|short)(\\s{1,})([^0-9 ])([A-Za-z0-9]{0,15})\\(((((?:int|long|short)(\\s){1,}[^0-9 ][A-Za-z0-9]{0,16}))((\\,(?!\\))(\\s){1,})?))*\\)\\;",  std::regex_constants::ECMAScript);
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
