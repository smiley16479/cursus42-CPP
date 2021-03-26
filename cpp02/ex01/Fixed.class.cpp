#include "Fixed.class.hpp"

Fixed::Fixed( void ) : _nb( 0 )
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int const n ) : _nb( n << _bits )
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

Fixed::Fixed( float const n )  : _nb( n * 256 )
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getNb( void ) const
{
	return this->_nb;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_nb;
}

void Fixed::setRawBits( int const raw )
{
	this->_nb = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_nb / 256);
}

int		Fixed::toInt(void) const
{
	return (_nb >> _bits);
}

Fixed &    Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		this->_nb = rhs.getNb();
	return *this;
}

std::ostream &    operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}