/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:52:16 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 16:52:17 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <stdexcept>
# include <string>
# include <iostream>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {
public:
	Intern();
	Intern(Intern const & src);
	~Intern();

	Intern & operator=(Intern const & rhs);
	Form* makeForm(std::string const & name, std::string const & target) const;
	Form* makePresidentialForm(std::string const & target) const;
	Form* makeRobotomyForm(std::string const & target) const;
	Form* makeShrubberyForm(std::string const & target) const;

	class UnknownForm : public std::exception {
	public:
		virtual const char* what() const throw();
	};

};

#endif
