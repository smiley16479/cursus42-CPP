#ifndef ICE_CLASS_H
#define ICE_CLASS_H

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( std::string const & type = "ice" );
	Ice( Ice const & src );
	virtual ~Ice( void );

	void use(ICharacter& target);
	Ice&   operator=( Ice const & rhs );

	virtual AMateria* clone() const;

private:

	int _nb;

};

std::ostream &    operator<<( std::ostream & o, Ice const & i );

#endif
