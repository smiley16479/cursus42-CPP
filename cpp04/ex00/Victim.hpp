#ifndef VICTIM_CLASS_H
#define VICTIM_CLASS_H

#include <iostream>


class Victim
{
public:
	Victim( std::string const name = "anonimous" );
	Victim( Victim const & src );
	~Victim( void );

	void	getPolymorphed() const;
	Victim &   operator=( Victim const & rhs );
	std::string getTitle( void ) const;

protected:
	std::string _name;
};

std::ostream &    operator<<( std::ostream & o, Victim const & i );

#endif
