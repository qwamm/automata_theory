#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <unordered_map>

std::string get_line(std::ifstream &in);
bool check_string(std::string str, std::string *fname);
//std::string get_fname(std::string s);

int main()
{
	float sum = 0;
        bool ret;
	std::unordered_map<std::string, int> overloads;
	std::string s;
        while (std::getline(std::cin, s))
        {
		std::string fname;
		auto start = std::chrono::system_clock::now();
                ret = check_string(s, &fname);
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
                std:: cout << s << " ret = " << ret << "\n";
        }
	std::cout << "TIME: " << sum << "\n";
	std::cout << "OVERLOADS:\n";
	for (auto &pair : overloads)
	{
		std::cout << pair.first << "\t" << pair.second << "\n";
	}
}

/*std::string get_fname(std::string s)
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
}*/

bool check_string(std::string str, std::string *fname)
{
	  std::regex reg ("(?:int|long|short)(\\s{1,})(([^0-9 ])([A-Za-z0-9]{0,15}))\\(((((?:int|long|short)(\\s){1,}[^0-9 ][A-Za-z0-9]{0,16}))((\\,(?!\\))(\\s){0,})?))*\\)\\;",  std::regex_constants::ECMAScript | std::regex::optimize);
	  std::smatch m;
	  bool r = std::regex_match(str, m, reg);
	  std::cout << m[0] << "\n";
	  std::cout << m[2] << "\n";
	  *fname = m[2];
	  return r;
}

std::string get_line(std::ifstream &in)
{
        std::string str;
        std::getline(in, str);
        return str;
}
