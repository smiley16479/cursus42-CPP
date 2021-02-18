/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:23:35 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 12:23:36 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noname"), _grade(MIN_GRADE) {
}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int grade) : _name(name) {
	if (grade < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > MIN_GRADE)	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

std::string const & Bureaucrat::getName() const {
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade > MAX_GRADE)
		this->_grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	if (this->_grade < MIN_GRADE)
		this->_grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &toSign) const {
	try {
		toSign.beSigned(*this);
		std::cout << this->_name << " signs " << toSign.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << this->_name << " cannot sign " << toSign.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form &form) {
	try {
		form.execute(*this);
		std::cout << this->_name << " has executed " << form.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "the grade of this bureaucrat is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "the grade of this bureaucrat is too high";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src) {
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return o;
}
