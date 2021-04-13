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
	std::cout << "Ds le Besigned de PresidentialPardonForm\n" << std::endl;
	AForm::beSigned(Brct);
	return 0;
}


/* int AForm::execute (Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrd() <= _execRqdGrd && _isSigned) {
			// beSigned(executor);
			return 1;
		}
		else if (!_isSigned)
			throw std::string ("AForm unsigned, cannot execute");
		else 
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
// Do not display exception msg as the besigned method already does
		// std::cerr << e.what() << '\n';
		throw ;
	}
	return 0;
} */

int PresidentialPardonForm::execute (Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrd() <= getExecRequiredGrd() && getSignedState()) {
			std::cout << "<" + _target + "> a été pardonné(e) par Zafod Beeblebrox\n";
		return 1;
		}
		else if (!getSignedState())
			throw std::string ("AForm unsigned, cannot execute");
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