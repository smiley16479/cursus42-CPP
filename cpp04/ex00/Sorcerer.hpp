#ifndef SORCERER_CLASS_H
#define SORCERER_CLASS_H

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer( void );
	Sorcerer( std::string name, std::string title );
	Sorcerer( std::string const n );
	Sorcerer( Sorcerer const & src );
	~Sorcerer( void );

	Sorcerer&   operator=( Sorcerer const & rhs );
	virtual void polymorph(Victim const & i) const;
	std::string getTitle( void ) const;

protected:
	std::string _name;
	std::string _title;

};

std::ostream &    operator<<( std::ostream & o, Sorcerer const & i );

#endif
