#ifndef PRESIDENTIALPARDONFORM_CLASS_H
#define PRESIDENTIALPARDONFORM_CLASS_H

#include <iostream>
#include "AForm.hpp"


class PresidentialPardonForm : public virtual AForm
{
public:
	// PresidentialPardonForm( void );
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	// PresidentialPardonForm( std::string target, std::string nm = "Presidential Pardon", int signRqdGrd = 25, int execRqdGrd = 5, bool isSigned = false );
	PresidentialPardonForm( PresidentialPardonForm const & src );
	virtual ~PresidentialPardonForm( void );
	int beSigned( Bureaucrat const & Brct );
	virtual int execute (Bureaucrat const & executor);

	PresidentialPardonForm&   operator=( PresidentialPardonForm const & rhs );

private:
	std::string _target;

};

std::ostream &    operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif
