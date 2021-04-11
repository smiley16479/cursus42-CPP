#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
: AForm( "Robotomy Request AForm", 72, 45, false),  _target( "Anonimous" )
// RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Presidential Pardon", 145, 137)
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
	srand (time(NULL));
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(  std::string target )
: AForm( "Robotomy Request AForm", 72, 45, false), _target( target )
// RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Presidential Pardon", 145, 137)
{
	std::cout << "RobotomyRequestForm Parameter Constructor called" << std::endl;
	srand (time(NULL));
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm(src)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
	return ;
}

int RobotomyRequestForm::beSigned( Bureaucrat const & Brct )
{
	AForm::beSigned(Brct);
	if (rand() % 2)
		std::cout << "Ziiiiit ziiit zziiiiiiiiiiitt <" + _target + "> a bien été robotomizé(e)\n";
	else
		std::cout << "<" + _target + "> n'a pas pu être robotomizé(e) correctement\n";
	return 0;
}

int RobotomyRequestForm::execute (Bureaucrat const & executor)
{
	try
	{
		AForm::execute(executor);
		beSigned(executor);
		return 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	std::cout << "RobotomyRequestForm Assignment operator called" << std::endl;
	if (this != &rhs )
		SetSignedState(rhs.getSignedState());
		// AForm::operator=((AForm)rhs);
	return *this;
}

std::ostream & operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "Name AForm is : " << i.getNm() << std::endl;
	o << "Is signed : " << (i.getSignedState() ? "oui": "non") << std::endl;
	o << "Signature required state : " << i.getSignRequiredGrd() << std::endl;
	o << "Execution required state : " << i.getExecRequiredGrd() << std::endl;
	return o;
}