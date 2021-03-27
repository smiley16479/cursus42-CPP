#include "Fixed.class.hpp"

// http://cstl-csm.semo.edu/xzhang/Class%20Folder/CS280/Workbook_HTML/FLOATING_tut.htm

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

// Fixed::Fixed( float const n )  : _nb( roundf( n * (1 << _bits)) )
Fixed::Fixed( float const n )  : _nb( n * (1 << _bits) )
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
	_nb = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_nb / (1 << _bits));
}

int		Fixed::toInt(void) const
{
	return (_nb >> _bits);
}

Fixed &    Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		_nb = rhs._nb;
	return *this;
}

Fixed &		Fixed::operator+=( Fixed const & i )
{
	_nb += i._nb;
	return *this;
}

Fixed &		Fixed::operator-=( Fixed const & i )
{
	_nb -= i._nb;
	return *this;
}

Fixed &		Fixed::operator*=( Fixed const & i )
{
	float tmp = this->toFloat();
	tmp *= i.toFloat();
	this->_nb = tmp * (1 << this->_bits);
	return *this;
}

Fixed &		Fixed::operator/=( Fixed const & i )
{
	_nb /= i._nb;
	return *this;
}

// http://casteyde.christian.free.fr/cpp/cours/online/x3244.html

// Suffixe
Fixed			Fixed::operator++( int )
{
	Fixed tmp(*this);
	++_nb;
	return tmp;
}

// Préfixe
Fixed &			Fixed::operator++( void )
{
	++_nb;
	return *this;
}

// Suffixe
Fixed			Fixed::operator--( int )
{
	Fixed tmp(*this);
	--_nb;
	return tmp;
}

// Préfixe
Fixed &			Fixed::operator--( void )
{
	--_nb;
	return *this;
}

Fixed & Fixed::min( Fixed & i, Fixed & j )
{
	return (i > j ? i : j);
}

const Fixed & Fixed::min( Fixed const & i, Fixed const & j )
{
	return (i._nb > j._nb ? i : j);
}

Fixed & Fixed::max( Fixed & i, Fixed & j )
{
	return (i > j ? i : j);
}

const Fixed & Fixed::max( Fixed const & i, Fixed const & j )
{
	return (i._nb > j._nb ? i : j);
}

bool		Fixed::operator>( Fixed const & i )
{
	return (i._nb > this->_nb);
}

bool		Fixed::operator<( Fixed const & i )
{
	return (this->_nb < i._nb);
}

bool		Fixed::operator>=( Fixed const & i )
{
	return (this->_nb >= i._nb);
}

bool		Fixed::operator<=( Fixed const & i )
{
	return (this->_nb <= i._nb);
}

bool		Fixed::operator==( Fixed const & i )
{
	return (i._nb == this->_nb);
}

bool		Fixed::operator!=( Fixed const & i )
{
	return !(i._nb == this->_nb);
}

Fixed		Fixed::operator+( Fixed const & i )
{
	Fixed copie(*this);
	copie += i;
	return (copie);
}

Fixed		Fixed::operator-( Fixed const & i )
{
	Fixed copie(*this);
	copie -= i;
	return (copie);
}

Fixed			Fixed::operator*( Fixed const & i )
{
	Fixed copie(*this);
	copie *= i;
	return (copie);
}

Fixed			Fixed::operator/( Fixed const & i )
{
	Fixed copie(*this);
	copie /= i;
	return (copie);
}

std::ostream &    operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}
