#ifndef INTERN_CLASS_H
#define INTERN_CLASS_H

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern;

typedef struct s_intern
{
	std::string forms[3];
	AForm* (Intern::*funcTab[3])(std::string target);
} t_intern;

class Intern
{
public:
	Intern( void );
	Intern( Intern const & src );
	~Intern( void );
	AForm *PresidentialPardonFormFunc(std::string target);
	AForm *RobotomyRequestFormFunc(std::string target);
	AForm* ShrubberyCreationFormFunc(std::string target);

	Intern&   operator=( Intern const & rhs );
	AForm* makeForm(std::string form, std::string target);

private:
	t_intern _data;
	
};

std::ostream &    operator<<( std::ostream & o, Intern const & i );

#endif
