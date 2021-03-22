#include "Zombie.hpp"

Zombie::Zombie( int type, std::string name ) : type(type), name(name) 
{
	std::cout << "constructor called" << std::endl;
	return;
}

Zombie::~Zombie( void )
{
	std::cout << "destructor called" << std::endl;
	return ;
}

int Zombie::advert( void ) const {
	std::cout << "<" << this->name << " (" << this->type << ")> I like Braiiiiiiinnnssss ..." << std::endl;
	return(0);
}