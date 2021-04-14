#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "wrong parameter number.\nUsage :convert 42\n";
		return 1;
	}
	try
	{
		char c = static_cast<char>(std::stold( av[1] ));
		if (c < 32)
			throw std::string("char: Non displayable");
		else
			std::cout << "char:\t" << "'" << c << "'" << std::endl;
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "error_char, ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		int i = static_cast<int>(std::stoi( av[1] ));
		std::cout << "int:\t" << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "int: Impossible, ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		float f = static_cast<float>(std::stold( av[1] ));
		std::cout << "float:\t" << f << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "error_float, ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		double d = static_cast<double>(std::stold( av[1] ));
		std::cout << "double:\t" << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "error_double, ";
		std::cerr << e.what() << '\n';
	}
	return 0;
}