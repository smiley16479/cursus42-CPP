/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:09:46 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/07 22:09:47 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
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
	std::cout << "Let's try to create a bureaucrat with the grade 666 :" << std::endl;
	try {
		Bureaucrat random("Random", 666);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Let's try to create a bureaucrat with the grade 0 :" << std::endl;
	try {
		Bureaucrat random2("Random2", 0);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Let's try to increment Daniel's grade : " << std::endl;
	try {
		chief.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << chief << std::endl;

	std::cout << "Let's try to decrement Daniel's grade : " << std::endl;
	try {
		chief.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << chief << std::endl;

	std::cout << std::endl;
	std::cout << "Let's try the exception on Philippe the employee : " << std::endl;
	try {
		employee.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << employee << std::endl;

	std::cout << std::endl;
	std::cout << "Let's try the exception on John the President : " << std::endl;
	try {
		president.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << president << std::endl;

	return (0);
}
