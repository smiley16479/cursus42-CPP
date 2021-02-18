/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:39:08 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 10:39:09 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <stdexcept>
# include <iostream>
# include <string>
# include <sstream>
# include "Bureaucrat.hpp"

enum e_type {
	SIGN,
	EXECUTE,
	CREATION
};

class Bureaucrat;

class Form {
public:
	Form();
	Form(std::string const & name, unsigned int const signMinGrade, unsigned int const executeMinGrade);
	Form(Form const & src);
	~Form();

	Form & operator=(Form const & rhs);
	std::string const & getName() const;
	bool isSigned() const;
	unsigned int getSignMinGrade() const;
	unsigned int getExecuteMinGrade() const;
	void beSigned(Bureaucrat const & human);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	std::string const _name;
	bool _signed;
	unsigned int const _signMinGrade;
	unsigned int const _executeMinGrade;
};

std::ostream & operator<<(std::ostream & o, Form const & src);

#endif
