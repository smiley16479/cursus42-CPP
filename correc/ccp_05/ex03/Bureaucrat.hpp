/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:50:47 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 16:50:47 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <stdexcept>
# include <iostream>
# include <string>
# include "Form.hpp"
# define MIN_GRADE 150
# define MAX_GRADE 1

class Form;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, unsigned int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();

	Bureaucrat & operator=(const Bureaucrat & rhs);
	std::string const & getName() const;
	unsigned int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form & toSign) const;

	void executeForm(Form const & form);

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	std::string const _name;
	unsigned int _grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);

#endif
