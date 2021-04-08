#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter
{
public:
	Character( std::string const name = "unkown" );
	Character( Character const & src );
	virtual ~Character( void );

	virtual std::string const & getName() const;
	void getType() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	Character&   operator=( Character const & rhs );

private:

	std::string _name;
	AMateria* _tab[4];

};

std::ostream &    operator<<( std::ostream & o, Character const & i );

#endif
