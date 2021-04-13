#ifndef AFORM_CLASS_H
#define AFORM_CLASS_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm( std::string nm = "Specimen", int signRqdGrd = 150, int execRqdGrd = 150, bool isSigned = false );
	AForm( AForm const & src );
	virtual ~AForm( void );

	AForm&   operator=( AForm const & rhs );

	std::string getNm( void ) const;
	bool getSignedState( void ) const;
	bool SetSignedState( bool isSigned );
	int getExecRequiredGrd( void ) const;
	int getSignRequiredGrd( void ) const;
	virtual int beSigned( Bureaucrat const & rhs );
	virtual int execute (Bureaucrat const & executor) const = 0;


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

std::ostream &    operator<<( std::ostream & o, AForm const & i );

#endif
