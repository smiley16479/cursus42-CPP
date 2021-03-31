#ifndef PEON_CLASS_H
#define PEON_CLASS_H

#include <iostream>
#include "Victim.hpp"


class Peon : public virtual Victim
{
public:
	Peon( void );
	Peon( std::string name );
	Peon( Peon const & src );
	~Peon( void );

	Peon&   operator=( Peon const & rhs );
	void	getPolymorphed( void ) const;

	std::string getName( void ) const;

private:

	int _nb;

};

std::ostream &    operator<<( std::ostream & o, Peon const & i );

#endif
