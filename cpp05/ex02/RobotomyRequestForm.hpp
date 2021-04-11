#ifndef ROBOTOMYREQUESTFORM_CLASS_H
#define ROBOTOMYREQUESTFORM_CLASS_H

#include <iostream>
#include "AForm.hpp"
#include <time.h>
#include <stdlib.h>

class RobotomyRequestForm : public virtual AForm
{
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm const & src );
	virtual ~RobotomyRequestForm( void );
	int beSigned( Bureaucrat const & Brct );
	virtual int execute (Bureaucrat const & executor);
	
	RobotomyRequestForm&   operator=( RobotomyRequestForm const & rhs );

private:
	std::string _target;

};

std::ostream &    operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif
