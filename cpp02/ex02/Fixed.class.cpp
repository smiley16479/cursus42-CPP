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
	return _nb;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _nb;
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

bool		operator>( Fixed const & i, Fixed const & j )
{
	return (i.getNb() > j.getNb());
}

bool		operator<( Fixed const & i, Fixed const & j )
{
	return !(i >= j);
}

bool		operator>=( Fixed const & i, Fixed const & j )
{
	return !(j > i);
}

bool		operator<=( Fixed const & i, Fixed const & j )
{
	return !(i > j);
}

bool		operator==( Fixed const & i, Fixed const & j )
{
	return (i.getNb() == j.getNb());
}

bool		operator!=( Fixed const & i, Fixed const & j )
{
	return !(i == j);
}

// Fixed	&	operator+( Fixed const & i, Fixed const & j )
// {
// 	return ();
// }
// int			operator-( Fixed const & i, Fixed const & j )
// {
// 	return ();
// }
// int			operator*( Fixed const & i, Fixed const & j )
// {
// 	return ();
// }
// int			operator/( Fixed const & i, Fixed const & j )
// {
// 	return ();
// }

// Fixed &			operator--(Fixed const & i );
// bool			operator++(Fixed const & i );


std::ostream &    operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}