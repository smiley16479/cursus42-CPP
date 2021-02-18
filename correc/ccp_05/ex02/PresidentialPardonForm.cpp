/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:25:32 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 12:25:33 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("presidential pardon", 25, 5), _target("noname") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: Form("presidential pardon", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
		: Form("presidential pardon", 25, 5), _target(src.getTarget()) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	(void)rhs;
	return *this;
}

std::string const & PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->checkForm(executor))
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
