#ifndef TACTICALMARINE_CLASS_H
#define TACTICALMARINE_CLASS_H

#include <iostream>
#include "ISpaceMarine.hpp"


class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine( void );
	TacticalMarine( int const n );
	TacticalMarine( TacticalMarine const & src );
	virtual ~TacticalMarine( void );

	// virtual ~ISpaceMarine() {};
	int 	getNb( void ) const;
	virtual ISpaceMarine* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
	//
	TacticalMarine&   operator=( TacticalMarine const & rhs );

private:
	int _nb;
};

std::ostream &    operator<<( std::ostream & o, TacticalMarine const & i );

#endif
