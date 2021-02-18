/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:50:55 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 16:50:56 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("noname"), _signed(false), _signMinGrade(MIN_GRADE), _executeMinGrade(MIN_GRADE) {
}

Form::Form(const std::string &name, unsigned int const signMinGrade, unsigned int const executeMinGrade)
	: _name(name), _signed(false), _signMinGrade(signMinGrade), _executeMinGrade(executeMinGrade) {
	if (signMinGrade > MIN_GRADE) {
		throw Form::GradeTooLowException();
	}
	else if (signMinGrade < MAX_GRADE) {
		throw Form::GradeTooHighException();
	}
	if (executeMinGrade > MIN_GRADE) {
		throw Form::GradeTooLowException();
	}
	else if (executeMinGrade  < MAX_GRADE) {
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form &src)
	: _name(src.getName()), _signed(false), _signMinGrade(src.getSignMinGrade()),
	_executeMinGrade(src.getExecuteMinGrade()) {
	*this = src;
}

Form::~Form() {
}

Form & Form::operator=(const Form &rhs) {
	if (this != &rhs)
		this->_signed = rhs.isSigned();
	return *this;
}

std::string const & Form::getName() const {
	return this->_name;
}

bool Form::isSigned() const {
	return this->_signed;
}

unsigned int Form::getSignMinGrade() const {
	return this->_signMinGrade;
}

unsigned int Form::getExecuteMinGrade() const {
	return this->_executeMinGrade;
}

void Form::beSigned(const Bureaucrat &human) {
	if (this->_signMinGrade < human.getGrade()) {
		throw Form::GradeTooLowException();
	}
	else {
		this->_signed = true;
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "this form requires an lowest grade";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "this form requires an highest grade";
}

const char* Form::FormNotSigned::what() const throw() {
	return "this form needs to be signed before being executed";
}

int Form::checkForm(const Bureaucrat &executor) const {
	if (!this->_signed)
		throw Form::FormNotSigned();
	if (executor.getGrade() > this->_executeMinGrade)
		throw Form::GradeTooLowException();
	return (1);
}

std::ostream & operator<<(std::ostream & o, Form const & src) {
	std::string status = src.isSigned() ? "signed" : "not signed";

	o << "The form `" << src.getName() << "' is " << status ;
	o << " and needs at least grade " << src.getSignMinGrade() << " to be signed and grade ";
	o << src.getExecuteMinGrade() << " to be executed";
	return o;
}
