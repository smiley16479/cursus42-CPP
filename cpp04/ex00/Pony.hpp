#ifndef PONY_CLASS_H
#define PONY_CLASS_H

#include <iostream>
#include "Victim.hpp"


class Pony : public virtual Victim
{
public:
	Pony( void );
	Pony( std::string name );
	Pony( Pony const & src );
	virtual ~Pony( void );

	Pony&   operator=( Pony const & rhs );
	virtual void	getPolymorphed( void ) const;

	std::string getName( void ) const;

private:

	int _nb;

};

std::ostream &    operator<<( std::ostream & o, Pony const & i );

#endif
