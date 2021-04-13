#ifndef SHRUBBERYCREATIONFORM_CLASS_H
#define SHRUBBERYCREATIONFORM_CLASS_H

#include <iostream>
#include <fstream>
#include "AForm.hpp"


class ShrubberyCreationForm : public virtual AForm
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	virtual ~ShrubberyCreationForm( void );
	int beSigned( Bureaucrat const & Brct );
	virtual int execute (Bureaucrat const & executor) const;
	
	ShrubberyCreationForm&   operator=( ShrubberyCreationForm const & rhs );

private:
	std::string _target;

};

std::ostream &    operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif
