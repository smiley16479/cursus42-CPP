#include "Form.hpp"

Form::Form( std::string nm, int signRqdGrd, int execRqdGrd, bool isSigned ) :
_nm( nm ), _signRqdGrd( signRqdGrd ), _execRqdGrd( execRqdGrd ), _isSigned( isSigned )
{
	std::cout << "Form Default Constructor called" << std::endl;
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

Form::Form( Form const & src ) :
_nm( src._nm ), _signRqdGrd( src._signRqdGrd ), _execRqdGrd( src._execRqdGrd ), _isSigned( src._isSigned )
{
	std::cout << "Form Copy Constructor called" << std::endl;
	return ;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
	return ;
}

std::string Form::getNm( void ) const
{
	return this->_nm;
}

bool Form::getSignedState( void ) const
{
	return _isSigned;
}
int Form::getSignRequiredGrd( void ) const
{
	return _signRqdGrd;
}
int Form::getExecRequiredGrd( void ) const
{
	return _execRqdGrd;
}

int Form::beSigned( Bureaucrat const & Brct )
{
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
	return false;
}


Form & Form::operator=( Form const & rhs )
{
	std::cout << "Form Assignment operator called" << std::endl;
	if (this != &rhs )
		_isSigned = rhs._isSigned;
	return *this;
}

std::ostream & operator<<( std::ostream & o, Form const & i )
{
	o << "Name form is : " << i.getNm() << std::endl;
	o << "Is signed : " << (i.getSignedState() ? "oui": "non") << std::endl;
	o << "Signature required state : " << i.getSignRequiredGrd() << std::endl;
	o << "Execution required state : " << i.getExecRequiredGrd() << std::endl;
	return o;
}