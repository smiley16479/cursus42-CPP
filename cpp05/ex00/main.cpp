#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat gratte("gratte", 15);
	Bureaucrat papier("papier", 5);
	Bureaucrat stylo("stylo", 	8);
	Bureaucrat copy_stylo(stylo);
	std::cout << copy_stylo << std::endl;
	// gratte = copy_stylo;
	std::cout << gratte << std::endl;
	gratte.incGrd();
	std::cout << gratte << std::endl;
	return 0;
}