#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
		Intern coffeeMaker;
		Bureaucrat gratte("gratte", 1);
		AForm *form = coffeeMaker.makeForm("presidential pardon request", "Bender");
		std::cout << *form << std::endl;
		gratte.signForm(*form);
		gratte.executeForm(*form);
		delete form;
		form = coffeeMaker.makeForm("shrubbery creation request", "Bender");
		std::cout << *form << std::endl;
		gratte.signForm(*form);
		gratte.executeForm(*form);
		delete form;
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