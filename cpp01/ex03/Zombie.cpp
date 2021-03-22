#include "ZombieHorde.hpp"

Zombie::Zombie( int type, std::string name ) : _type(type), _name(name) 
{
	std::cout << "Zombie constructor called" << std::endl;
	return;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie destructor called" << std::endl;
	return ;
}

void Zombie::advert( void ) const
{
	std::cout << "<" << this->_name << " (" << this->_type
	<< ")> I like Braiiiiiiinnnssss ..." << std::endl;
	return ;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << std::endl;
}