/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:51:43 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 16:51:45 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

int main() {
	Bureaucrat employee("Philippe", 150);
	Bureaucrat chief("Daniel", 57);
	Bureaucrat president("John", 1);

	std::cout << "Three bureaucrats have been created : " << std::endl;
	std::cout << employee << std::endl;
	std::cout << chief << std::endl;
	std::cout << president << std::endl;

	std::cout << std::endl;
	std::cout << "Let's create a new intern, 'named' Meredith Gray, and try to make her create a robotomy form :" << std::endl;
	Intern meredithGray;
	Form* robotomy = NULL;

	try {
		robotomy = meredithGray.makeForm("robotomy request", "Bender");
		std::cout << *robotomy << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "What about an unknown form named `erase human' ?" << std::endl;
	Form* unknown = NULL;

	try {
		unknown = meredithGray.makeForm("erase human", "Earth");
		std::cout << *unknown << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Can we use robotomy form correctly ?" << std::endl;

	try {
		chief.signForm(*robotomy);
		std::cout << *robotomy << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		president.executeForm(*robotomy);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	if (robotomy)
		delete robotomy;

	return (0);
}
