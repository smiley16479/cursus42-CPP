#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat( std::string name, int gd ) :
_grd( gd ), _name(name)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
	try
	{
		if (_grd < 1)
			throw (GradeTooHighException());
		else if (_grd > 150)
			throw (GradeTooLowException());
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
		throw ;
	}
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) :
_grd(src._grd), _name( src._name )
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
	return ;
}

void Bureaucrat::signForm(AForm & form) const throw (GradeTooLowException)
{
	if (_grd <= form.getSignRequiredGrd()) {
		form.beSigned((const Bureaucrat)*this);
		std::cout << "<" + _name + "> signs form <" + form.getNm() + ">\n";
	}
	else {
		std::cout << "<" + _name + "> can't sign form <" +
		form.getNm() + "> because <Grd_is_too_low>\n";
		throw (GradeTooLowException());
	}
	return ;
}

int Bureaucrat::executeForm(AForm const& form)
{
	if (form.execute(*this)) {
		std::cout <<  "<" + _name + "> executs AForm <" + form.getNm() + ">\n";
		// (/* (AForm) */form).beSigned(*this);
		return 1;
	}
	else {
		std::cout <<  "ERROR : <" + _name + "> can't execut AForm <" + form.getNm() + ">\n";
		return 0;
	}
	return 0;
}

std::string Bureaucrat::getNm( void ) const
{
	return this->_name;
}

int Bureaucrat::getGrd( void ) const
{
	return this->_grd;
}

int Bureaucrat::setGrd( int grd )
{
	return (_grd = grd);
}

int Bureaucrat::incGrd( void )
{
	try
	{
		if (_grd - 1 < 1)
			throw (GradeTooHighException());
		else
			--_grd;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	return (_grd);
}

int Bureaucrat::decGrd( void )
{
	try
	{
		if (_grd + 1 > 150)
			throw (GradeTooLowException());
		else
			++_grd;		
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	return (_grd);
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
	std::cout << "Bureaucrat Assignment operator called" << std::endl;
	if (this != &rhs )
		_grd = rhs._grd;
	return *this;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << "The <" << i.getNm() << "> Bureaucrat's grade is : " << i.getGrd();
	return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too High\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too Low\n";
}