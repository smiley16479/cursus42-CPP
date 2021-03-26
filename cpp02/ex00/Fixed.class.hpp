#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

#include <iostream>


class Fixed
{
public:
	Fixed( void );
	Fixed( int const n );
	Fixed( Fixed const & src );
	~Fixed( void );

	Fixed&	operator=( Fixed const & rhs );
	int		getNb(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	static const int _bits = 8;
	int _nb;

};


std::ostream &    operator<<( std::ostream & o, Fixed const & i );

#endif
