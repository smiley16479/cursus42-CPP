#ifndef AMATERIA_CLASS_H
#define AMATERIA_CLASS_H

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:
/* [...] */
	std::string _type;
	unsigned int _xp;
public:
	AMateria( std::string const & type = "unkown", unsigned int xp = 0 );
	AMateria( AMateria const & src );
/* [...] */
	virtual /* [...] */ ~AMateria();
	virtual AMateria* clone() const = 0;
	std::string const & getType() const; //Returns the materia type
	unsigned int getXP() const;  //Returns the Materia's XP
	unsigned int setXP( unsigned int x );  //Sets the Materia's XP
	virtual void use(ICharacter& target);
};

std::ostream &    operator<<( std::ostream & o, AMateria const & i );

#endif
