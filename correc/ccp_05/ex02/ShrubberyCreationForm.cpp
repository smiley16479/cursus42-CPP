/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:24:53 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 12:24:54 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("shrubbery creation", 145, 137), _target("noname") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form("shrubbery creation", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
		: Form("shrubbery creation", 145, 137), _target(src.getTarget()) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	(void)rhs;
	return *this;
}

std::string const & ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->checkForm(executor)) {
		std::string filename = this->_target + "_shrubbery";
		std::ofstream out(filename.c_str());
		if (out) {
			for (int i = 0; i < 4; i++) {
				out << "         .     .  .      +     .      .          .\n"
					   "     .       .      .     #       .           .\n"
					   "        .      .         ###            .      .      .\n"
					   "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
					   "          .      . \"####\"###\"####\"  .\n"
					   "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
					   "  .             \"#########\"#########\"        .        .\n"
					   "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
					   "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
					   "                .\"##\"#####\"#####\"##\"           .      .\n"
					   "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
					   "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
					   "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
					   "            .     \"      000      \"    .     .\n"
					   "       .         .   .   000     .        .       .\n"
					   ".. .. ..................O000O........................ ...... ..." << std::endl;
			}
			out.close();
		}
	}
}
