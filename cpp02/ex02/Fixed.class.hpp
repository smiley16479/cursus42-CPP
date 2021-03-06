#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

#include <iostream>
#include <cmath>


class Fixed
{
public:
	Fixed( void );
	Fixed( int const n );
	Fixed( float const n );
	Fixed( Fixed const & src );
	~Fixed( void );

	Fixed &	operator=( Fixed const & rhs );
	int		getNb(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	Fixed &	operator+=( Fixed const & i );
	Fixed &	operator-=( Fixed const & i );
	Fixed &	operator*=( Fixed const & i );
	Fixed &	operator/=( Fixed const & i );
	Fixed	operator++( int );
	Fixed &	operator++( void );
	Fixed	operator--( int );
	Fixed &	operator--( void );
	bool	operator>( Fixed const & i )const;
	bool	operator<( Fixed const & i )const;
	bool	operator>=( Fixed const & i );
	bool	operator<=( Fixed const & i );
	bool	operator==( Fixed const & i );
	bool	operator!=( Fixed const & i );
	Fixed	operator+( Fixed const & i );
	Fixed	operator-( Fixed const & i );
	Fixed	operator*( Fixed const & i );
	Fixed	operator/( Fixed const & i );
	static	Fixed & min( Fixed & i, Fixed & j );
	static const	Fixed & min( Fixed const & i, Fixed const & j );
	static	Fixed & max( Fixed & i, Fixed & j );
	static const	Fixed & max( Fixed const & i, Fixed const & j );

private:
	static const int _bits = 8;
	int _nb;

};

std::ostream & 	operator<<( std::ostream & o, Fixed const & i );

#endif
