#ifndef HUMANB_CLASS_HPP
#define HUMANB_CLASS_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon;
public:
	HumanB(std::string _name);
	~HumanB( void );

	void attack(void);
	void setWeapon(Weapon &wp);
};

#endif