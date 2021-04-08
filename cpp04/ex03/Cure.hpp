#ifndef CURE_CLASS_H
#define CURE_CLASS_H

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure( std::string const & type = "cure" );
	Cure( Cure const & src );
	virtual ~Cure( void );

	void use(ICharacter& target);
	Cure&   operator=( Cure const & rhs );

	virtual AMateria* clone() const;

private:

	int _nb;

};

std::ostream &    operator<<( std::ostream & o, Cure const & i );

#endif
