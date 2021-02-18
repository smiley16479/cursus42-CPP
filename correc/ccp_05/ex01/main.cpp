/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:34:52 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 10:34:55 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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
	std::cout << "Now let's create forms : " << std::endl;
	Form menuCantine("Menu Cantine", 150, 150);
	Form eraseHuman("Erase Human", 1, 1);
	Form movePlant("Move Plant", 60, 56);
	std::cout << menuCantine << std::endl;
	std::cout << eraseHuman << std::endl;
	std::cout << movePlant << std::endl;

	std::cout << std::endl;
	std::cout << "Now let's try to create invalid form with a minimun sign grade 666 : " << std::endl;
	try {
		Form random("Random", 666, 45);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Now let's try to create invalid form with a minimun execute grade 0 : " << std::endl;
	try {
		Form random2("Random2", 45, 0);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Let's try to make Philippe, the employee grade " ;
	std::cout << employee.getGrade() << " sign " << menuCantine.getName() << " :" << std::endl;
	try {
		employee.signForm(menuCantine);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << menuCantine << std::endl;

	std::cout << std::endl;
	std::cout << "And now Philippe will try to sign the " << eraseHuman.getName() << " :" << std::endl;
	try {
		employee.signForm(eraseHuman);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << eraseHuman << std::endl;

	std::cout << std::endl;
	std::cout << "What happens if the President tries to sign it :" << std::endl;
	try {
		president.signForm(eraseHuman);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << eraseHuman << std::endl;

	return (0);
}
