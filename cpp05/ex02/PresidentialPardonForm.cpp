#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
: AForm("Presidential Pardon", 25, 5, false),  _target( "Anonimous" )
// PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Presidential Pardon", 145, 137)
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
: AForm("Presidential Pardon", 25, 5, false), _target( target )
// PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Presidential Pardon", 145, 137)
{
	std::cout << "PresidentialPardonForm Parameter Constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : AForm(src)
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
	return ;
}

int PresidentialPardonForm::beSigned( Bureaucrat const & Brct )
{
	AForm::beSigned(Brct);
	std::cout << "<" + _target + "> a été pardonné(e) par Zafod Beeblebrox\n";
	return 0;
}

int PresidentialPardonForm::execute (Bureaucrat const & executor)
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

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	std::cout << "PresidentialPardonForm Assignment operator called" << std::endl;
	if (this != &rhs )
		SetSignedState(rhs.getSignedState()); //both are correct (except since i chance Form in AForm)
		// AForm::operator=((AForm)rhs);
	return *this;
}

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "Name AForm is : " << i.getNm() << std::endl;
	o << "Is signed : " << (i.getSignedState() ? "oui": "non") << std::endl;
	o << "Signature required state : " << i.getSignRequiredGrd() << std::endl;
	o << "Execution required state : " << i.getExecRequiredGrd() << std::endl;
	return o;
}