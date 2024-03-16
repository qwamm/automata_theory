#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <functional>

std::string gen_str(std::default_random_engine &generator, std::uniform_int_distribution<int> &distribution);
std::string gen_spaces(std::default_random_engine &generator, std::uniform_int_distribution<int> &distribution);
std::string gen_type(std::default_random_engine &generator, std::uniform_int_distribution<int> &distribution);
std::string gen_parameter(std::default_random_engine &generator, std::uniform_int_distribution<int> &distribution);

int main()
{
	//std::seed_seq seed1 (str.begin(),str.end());
	std::default_random_engine generator(time(0));
	std::uniform_int_distribution<int> distribution (1,1000000);
	//srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		std::cout << gen_type(generator, distribution) + gen_spaces(generator, distribution) +
		 gen_str(generator, distribution) + "(" + gen_parameter(generator, distribution) + ")" + ";" << "\n";
	}
}

std::string gen_parameter(std::default_random_engine &generator, std::uniform_int_distribution<int> &distribution)
{
	//std::default_random_engine generator(seed1);
	//std::uniform_int_distribution<int> distribution (1,1000);
	std::string res = "";
	//auto dice = std::bind( distribution, generator );
	int q = distribution(generator)%5;
	for (int i = 0; i < q; i++)
	{
		if (i < q-1)
			res += (gen_type(generator, distribution) + gen_spaces(generator, distribution) + gen_str(generator, distribution) + ",");
		else
			res += (gen_type(generator, distribution) + gen_spaces(generator, distribution) + gen_str(generator, distribution));
	}
	return res;
}

std::string gen_type(std::default_random_engine &generator, std::uniform_int_distribution<int> &distribution)
{
	std::vector<std::string> v;
	//v.push_back("float");
	v.push_back("int");
	v.push_back("short");
	//v.push_back("double");
	v.push_back("long");
	int ind = distribution(generator)%2;
	return v[ind];
}

std::string gen_spaces(std::default_random_engine &generator, std::uniform_int_distribution<int> &distribution)
{
	std::string res;
	int len = distribution(generator)%4 + 1;
	for (int i = 0; i < len; i++)
		res.push_back(' ');
	return res;
}

std::string gen_str(std::default_random_engine &generator, std::uniform_int_distribution<int> &distribution)
{
	const char alphanum[] =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string str;
	int len = distribution(generator)%15 + 1;
	for (int i = 0; i < len; i++)
	{
		str += alphanum[rand() % (sizeof(alphanum) -1)];
	}
	return str;
}
