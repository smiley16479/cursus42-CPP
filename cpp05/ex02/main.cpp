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
		Bureaucrat gratte("gratte", 1);
		Bureaucrat papier("papier", 26);
		gratte.incGrd();
		std::cout << gratte << std::endl;
		std::cout << papier << std::endl;

		// TEST WITH MORE FORM
		// AForm AForm("202-46B", 12, 2, false);
		// std::cout << AForm << std::endl;
		// papier.signForm(AForm);
		// std::cout << AForm << std::endl;

		std::cout << "\nForm Creation...\n\n";
		PresidentialPardonForm pForm("Manson");
		RobotomyRequestForm rForm("Adel");
		ShrubberyCreationForm sForm("Adam");
		// std::cout << pForm << std::endl;

		// std::cout << "\nError Checking...\n\n";
		// papier.signForm(pForm); // Throw GradeTooLowException()
		
		std::cout << "\nForm signature...\n\n";
		gratte.signForm(pForm);
		gratte.signForm(rForm);
		gratte.signForm(sForm);
		// std::cout << pForm << std::endl;

		std::cout << "\nForm excecution...\n\n";
		pForm.execute(gratte);
		rForm.execute(gratte);
		// sForm.execute(gratte);

		std::cout << "\nBureaucrat excecution Form...\n\n";
		gratte.executeForm(pForm);
		gratte.executeForm(rForm);
		// gratte.executeForm(sForm);

		std::cout << "\nBureaucrat excecution Form...\n\n";
		ShrubberyCreationForm shru;
		// shru.beSigned(gratte);
		shru.execute(gratte);
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