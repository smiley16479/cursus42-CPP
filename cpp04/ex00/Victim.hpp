#ifndef VICTIM_CLASS_H
#define VICTIM_CLASS_H

#include <iostream>


class Victim
{
public:
	Victim( std::string name );
	Victim( std::string const name = "anonimous" );
	Victim( Victim const & src );
	~Victim( void );

	Victim&   operator=( Victim const & rhs );
	std::string getTitle( void ) const;

private:
	std::string _name;
};

std::ostream &    operator<<( std::ostream & o, Victim const & i );

#endif
