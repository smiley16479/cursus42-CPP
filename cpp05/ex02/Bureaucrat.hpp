#ifndef BUREAUCRAT_CLASS_H
#define BUREAUCRAT_CLASS_H

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	Bureaucrat( std::string name = "NoName", int gd = 0 );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat( void );

	Bureaucrat&   operator=( Bureaucrat const & rhs );
	
	void signForm(AForm & AForm);
	virtual int executeForm (AForm const& form);
	virtual int executeFormTool (AForm & form);
	std::string getNm( void ) const;
	int getGrd( void ) const;
	int setGrd( int grd );
	int incGrd( void );
	int decGrd( void );

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "grade is too High\n";
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "grade is too Low\n";
		}
	};

private:

	int _grd;
	std::string const _name;
};

std::ostream &    operator<<( std::ostream & o, Bureaucrat const & i );

#endif
