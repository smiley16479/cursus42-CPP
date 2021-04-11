#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
		Bureaucrat gratte("gratte", 1); // remettre un grade correct...
		Bureaucrat papier("papier", 12); // remettre un grade correct...
		gratte.incGrd();
		std::cout << gratte << std::endl;
		// AForm AForm("202-46B", 12, 2, false);
		// std::cout << AForm << std::endl;
		// papier.signForm(AForm);
		// std::cout << AForm << std::endl;

		std::cout << "little intermede...\n\n";
		PresidentialPardonForm pForm("Manson");
		// RobotomyRequestForm rForm("Adel");
		// ShrubberyCreationForm sForm("Adam");
		// std::cout << pForm << std::endl;
		gratte.signForm(pForm);
		// gratte.signForm(rForm);
		// gratte.signForm(sForm);
		// std::cout << pForm << std::endl;
		// pForm.execute(gratte);
		// rForm.execute(gratte);
		// sForm.execute(gratte);
		gratte.executeForm(pForm);
		// ShrubberyCreationForm shru;
		// shru.beSigned(gratte);
	}
	catch(std::exception &e)
	{
		return 1;
	}
	catch(std::string &str)
	{
		std::cout << str << std::endl;
		return 1;
	}
	return 0;
}