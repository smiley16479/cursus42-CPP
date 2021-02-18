/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:51:21 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 16:51:22 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
		: Form("robotomy request", 72, 45), _target("noname") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
		: Form("robotomy request", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
		: Form("robotomy request", 72, 45), _target(src.getTarget()) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()  {
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	(void)rhs;
	return *this;
}

std::string const & RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->checkForm(executor)) {
		std::cout << "*  rizzz, bzzzzzz *" << std::endl;
		std::cout << this->_target;
		if ((std::time(NULL) % 2) == 0)
			std::cout << " has been robotomized successfully" << std::endl;
		else
			std::cout << " has failed to be robotomized" << std::endl;
	}
}
