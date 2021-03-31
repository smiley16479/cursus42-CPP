#include "Peon.hpp"


Peon::Peon( void ) : _nb( 0 )
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Peon::Peon( int const n ) : _nb( n )
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

Peon::Peon( Peon const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Peon::~Peon()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Peon::getNb( void ) const
{
	return this->_nb;
}

Peon & Peon::operator=( Peon const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		this->_nb = rhs.getNb();
	return *this;
}

std::ostream & operator<<( std::ostream & o, Peon const & i )
{
	o << "The value of _nb is : " << i.getNb();
	return o;
}