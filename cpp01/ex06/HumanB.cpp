#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	// std::cout << "HumanB constructor called" << std::endl;
	return;
}

HumanB::~HumanB( void )
{
	// std::cout << "HumanB destructor called" << std::endl;
	return ;
}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl; 
}

void HumanB::setWeapon(Weapon &wp)
{
	this->_weapon = &wp;
	return;
}