#include <iostream>
#include <string>
#include <array>
#include <iomanip>

void memory_leak()
{
	std::string *panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete panthere;
}

int main()
{
	memory_leak();
	return(0);
}