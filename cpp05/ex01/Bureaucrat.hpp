#ifndef BUREAUCRAT_CLASS_H
#define BUREAUCRAT_CLASS_H

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat( std::string name = "NoName", int gd = 0 );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat( void );

	Bureaucrat&   operator=( Bureaucrat const & rhs );
	
	void signForm(Form & form);
	std::string getNm( void ) const;
	int getGrd( void ) const;
	int setGrd( int grd );
	int incGrd( void );
	int decGrd( void );
	
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

	int _grd;
	std::string const _name;
};

std::ostream &    operator<<( std::ostream & o, Bureaucrat const & i );

#endif
