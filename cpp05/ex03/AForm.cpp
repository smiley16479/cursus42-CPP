#include "AForm.hpp"

AForm::AForm( std::string nm, int signRqdGrd, int execRqdGrd, bool isSigned ) :
_nm( nm ), _signRqdGrd( signRqdGrd ), _execRqdGrd( execRqdGrd ), _isSigned( isSigned )
{
	std::cout << "AForm Default Constructor called" << std::endl;
	try
	{
		if (_signRqdGrd < 1 || _execRqdGrd < 1 )
			throw (GradeTooHighException());
		else if ( _signRqdGrd > 150 || _execRqdGrd > 150)
			throw (GradeTooLowException());
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << '\n';
		throw ;
	}
	return ;
}

AForm::AForm( AForm const & src ) :
_nm( src._nm ), _signRqdGrd( src._signRqdGrd ), _execRqdGrd( src._execRqdGrd ), _isSigned( src._isSigned )
{
	std::cout << "AForm Copy Constructor called" << std::endl;
	return ;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
	return ;
}

std::string AForm::getNm( void ) const
{
	return this->_nm;
}

bool AForm::getSignedState( void ) const
{
	return _isSigned;
}

bool AForm::SetSignedState( bool isSigned )
{
	return ( _isSigned = isSigned );
}

int AForm::getSignRequiredGrd( void ) const
{
	return _signRqdGrd;
}
int AForm::getExecRequiredGrd( void ) const
{
	return _execRqdGrd;
}

int AForm::beSigned( Bureaucrat const & Brct )
{
	std::cout << "Ds le beSigned de AForm\n" << std::endl;
	try
	{
		if (Brct.getGrd() <= _signRqdGrd)
			return ( _isSigned = true );
		else 
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

AForm & AForm::operator=( AForm const & rhs )
{
	std::cout << "AForm Assignment operator called" << std::endl;
	if (this != &rhs )
		_isSigned = rhs._isSigned;
	return *this;
}

std::ostream & operator<<( std::ostream & o, AForm const & i )
{
	o << "Name AForm is : " << i.getNm() << std::endl;
	o << "Is signed : " << (i.getSignedState() ? "oui": "non") << std::endl;
	o << "Signature required state : " << i.getSignRequiredGrd() << std::endl;
	o << "Execution required state : " << i.getExecRequiredGrd() << std::endl;
	return o;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too High\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too Low\n";
}