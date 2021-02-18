/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:51:37 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 16:51:39 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
	void execute(Bureaucrat const & executor) const;
	std::string const & getTarget() const;

private:
	std::string const _target;
};

#endif
