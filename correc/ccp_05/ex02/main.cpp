/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:23:29 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 12:23:30 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
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
	std::cout << "Let's create the 3 differents types of forms : " << std::endl;
	ShrubberyCreationForm first("home");
	RobotomyRequestForm second("Bender");
	PresidentialPardonForm third("Gandhi");

	std::cout << first;
	std::cout << ". The target of this form is " << first.getTarget() << std::endl;
	std::cout << second;
	std::cout << ". The target of this form is " << second.getTarget() << std::endl;
	std::cout << third;
	std::cout << ". The target of this form is " << third.getTarget() << std::endl;

	std::cout << std::endl;
	std::cout << "Let's try to execute a form without being signed : " << std::endl;
	try {
		chief.executeForm(first);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "We'll now sign this form, and try to execute it without the grade required: " << std::endl;
	try {
		chief.signForm(first);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << first << std::endl;
	try {
		employee.executeForm(first);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Now let the chief executes it so we can see if it works (check the file) : " << std::endl;
	try {
		chief.executeForm(first);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Now we sign the 2 others forms :" << std::endl;
	try {
		chief.signForm(second);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		president.signForm(third);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "We'll try to make the chief execute both forms (he doesn't have the access) :" << std::endl;
	try {
		chief.executeForm(second);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		chief.executeForm(third);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "And we let the president executes them :" << std::endl;
	try {
		president.executeForm(second);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		president.executeForm(third);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
