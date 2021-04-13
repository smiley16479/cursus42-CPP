#include "Intern.hpp"


Intern::Intern( void )
{
	std::cout << "Intern Default Constructor called" << std::endl;
	_data.forms[0] = "presidential pardon request";
	_data.forms[1] = "robotomy request";
	_data.forms[2] = "shrubbery creation request";

	_data.funcTab[0] = &Intern::PresidentialPardonFormFunc;
	_data.funcTab[1] = &Intern::RobotomyRequestFormFunc;
	_data.funcTab[2] = &Intern::ShrubberyCreationFormFunc;
	return ;
}

Intern::Intern( Intern const & src )
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
	return ;
}

AForm *Intern::PresidentialPardonFormFunc(std::string target)
{
	return (new PresidentialPardonForm(target));
}
AForm *Intern::RobotomyRequestFormFunc(std::string target)
{
	return (new RobotomyRequestForm(target));
}
AForm *Intern::ShrubberyCreationFormFunc(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	for (size_t i = 0; i < 3; i++)
	{
		if (_data.forms[i] == form)
			return (this->*(_data.funcTab[i]))(target);
	}
	return NULL;
}


Intern & Intern::operator=( Intern const & rhs )
{
	std::cout << "Intern Assignment operator called" << std::endl;
	if (this != &rhs ){
		;}
	return *this;
}

std::ostream & operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "En retard en retard !! Je n'ai pas le temps de dire aurevoir !!"
	"\n Je suis en retard ! en retard !!\n";
	return o;
}