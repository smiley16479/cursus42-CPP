#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat( std::string name, int gd ) : _grd( gd ), _name( name )
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
	try
	{
		if (_grd < 1)
			throw GradeTooHighException();
		else if (_grd > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
		_grd = 150;
	}
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _grd(src._grd), _name( src._name )
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
	return ;
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