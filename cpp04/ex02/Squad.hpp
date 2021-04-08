#ifndef SQUAD_CLASS_H
#define SQUAD_CLASS_H

#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
// #include "TacticalMarine.hpp"
// #include "AssaultTerminator.hpp"

class Squad : public ISquad
{
public:
	Squad( int const unitNb = 0 /* , ISpaceMarine** = NULL */);
	Squad( Squad const & src );
	virtual ~Squad( void );

	Squad&	operator=( Squad const & rhs );
	virtual int getCount( void ) const;
	virtual ISpaceMarine* getUnit(int) const;
	virtual int push(ISpaceMarine*);

private:
	int _unitNb;
	ISpaceMarine** _ISmTab;
};

std::ostream &    operator<<( std::ostream & o, Squad const & i );

#endif