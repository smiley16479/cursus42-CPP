#ifndef ASSAULTTERMINATOR_CLASS_H
#define ASSAULTTERMINATOR_CLASS_H

#include <iostream>
#include "ISpaceMarine.hpp"


class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator( void );
	AssaultTerminator( int const n );
	AssaultTerminator( AssaultTerminator const & src );
	virtual ~AssaultTerminator( void );

	// virtual ~ISpaceMarine() {};
	int 	getNb( void ) const;
	virtual ISpaceMarine* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
	//
	AssaultTerminator&   operator=( AssaultTerminator const & rhs );

private:

	int _nb;

};

std::ostream &    operator<<( std::ostream & o, AssaultTerminator const & i );

#endif
