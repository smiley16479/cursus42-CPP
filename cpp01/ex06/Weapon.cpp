#include "Weapon.hpp"

Weapon::Weapon( std::string name ) : _type(name)
{
	// std::cout << "Weapon constructor called" << std::endl;
	return;
}

Weapon::~Weapon( void )
{
	// std::cout << "Weapon destructor called" << std::endl;
	return ;
}


std::string const& Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string str)
{
	this->_type = str;
}