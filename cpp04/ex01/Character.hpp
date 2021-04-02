#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
protected:
	int _ap;
	std::string _name;
	// int _hp; // Semble inutile
	AWeapon *_wp;

public:
	Character( int _ap = 40, std::string const & _name = "Unknown", AWeapon *_wp = NULL );
	Character(std::string const & name);
	Character( Character const & src );
	virtual ~Character( void );
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string virtual getName() const;
	void* getWeapon() const;
	int getAp() const;
	std::string getWeaponName() const;


	Character&   operator=( Character const & rhs );

};

std::ostream &    operator<<( std::ostream & o, Character const & i );

#endif

/* class Character{

private:

public:
	Character(std::string const & name);
	virtual ~Character();
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string virtual getName() const;
};
 */