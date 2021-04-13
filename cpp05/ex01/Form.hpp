#ifndef FORM_CLASS_H
#define FORM_CLASS_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form( std::string nm = "Specimen", int signRqdGrd = 150, int execRqdGrd = 150, bool isSigned = false );
	Form( Form const & src );
	~Form( void );

	Form&   operator=( Form const & rhs );

	std::string getNm( void ) const;
	bool getSignedState( void ) const;
	int getExecRequiredGrd( void ) const;
	int getSignRequiredGrd( void ) const;
	int beSigned( Bureaucrat const & rhs );

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

private:

	std::string const _nm;
	int const _signRqdGrd;
	int const _execRqdGrd;
	bool _isSigned;

};

std::ostream &    operator<<( std::ostream & o, Form const & i );

#endif
