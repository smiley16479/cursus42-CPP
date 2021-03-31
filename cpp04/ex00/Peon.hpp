#ifndef PEON_CLASS_H
#define PEON_CLASS_H

#include <iostream>


class Peon
{
public:
	Peon( void );
	Peon( int const n = 0 );
	Peon( Peon const & src );
	~Peon( void );

	Peon&   operator=( Peon const & rhs );

	int getNb( void ) const;

private:

	int _nb;

};

std::ostream &    operator<<( std::ostream & o, Peon const & i );

#endif
