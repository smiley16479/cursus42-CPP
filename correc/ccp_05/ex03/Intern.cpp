/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:52:22 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 16:52:23 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {
}

Intern & Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return *this;
}

Form* Intern::makePresidentialForm(const std::string &target) const {
	return new PresidentialPardonForm(target);
}

Form* Intern::makeRobotomyForm(const std::string &target) const {
	return new RobotomyRequestForm(target);
}

Form* Intern::makeShrubberyForm(const std::string &target) const {
	return new ShrubberyCreationForm(target);
}

Form* Intern::makeForm(const std::string &name, const std::string &target) const {
	std::string available_forms_names[3] = {PresidentialPardonForm().getName(),
		RobotomyRequestForm().getName(), ShrubberyCreationForm().getName()};
	Form* (Intern::*makeFct[3])(std::string const &) const = {&Intern::makePresidentialForm,
		&Intern::makeRobotomyForm, &Intern::makeShrubberyForm};

	for(int i = 0; i < 3; i ++)
		if (available_forms_names[i] == name)
			return (this->*makeFct[i])(target);
	throw Intern::UnknownForm();
}

const char* Intern::UnknownForm::what() const throw() {
	return "this form doesn't exist";
}
