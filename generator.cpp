#include <iostream>
#include <fstream>
#include <vector>

std::string gen_str();
std::string gen_spaces();
std::string gen_type();
std::string gen_parameter();

int main()
{
	srand(time(NULL));
	std::ofstream of;
	of.open("input.txt");
	for (int i = 0; i < 10; i++)
	{
		of << gen_type() + gen_spaces() + gen_str() + "(" + gen_parameter() + ")" + ";" << "\n";
	}
	of.close();
}

std::string gen_parameter()
{
	std::string res = "";
	int q = rand()%11;
	for (int i = 0; i < q; i++)
	{
		if (i < q-1)
			res += (gen_type() + gen_spaces() + gen_str() + "," + " ");
		else
			res += (gen_type() + gen_spaces() + gen_str());
	}
	return res;
}

std::string gen_type()
{
	std::vector<std::string> v;
	//v.push_back("float");
	v.push_back("int");
	v.push_back("short");
	//v.push_back("double");
	v.push_back("long");
	int ind = rand()%3;
	return v[ind];
}

std::string gen_spaces()
{
	std::string res;
	int len = rand()%4 + 1;
	for (int i = 0; i < len; i++)
		res.push_back(' ');
	return res;
}

std::string gen_str()
{
	const char alphanum[] =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string str;
	int len = rand()%25 + 1;
	for (int i = 0; i < len; i++)
	{
		str += alphanum[rand() % (sizeof(alphanum) -1)];
	}
	return str;
}
