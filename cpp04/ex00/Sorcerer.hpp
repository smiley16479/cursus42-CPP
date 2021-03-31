#ifndef SORCERER_CLASS_H
#define SORCERER_CLASS_H

#include <iostream>


class Sorcerer
{
public:
	Sorcerer( std::string name, int title );
	Sorcerer( int const n = 0 );
	Sorcerer( Sorcerer const & src );
	~Sorcerer( void );

	Sorcerer&   operator=( Sorcerer const & rhs );

	int getTitle( void ) const;

private:
	std::string _name;
	int _title;

};

std::ostream &    operator<<( std::ostream & o, Sorcerer const & i );

#endif
