#include "SuperMutant.hpp"


SuperMutant::SuperMutant( void ) : Enemy( 170, "Super Mutant" )
{
	std::cout << "Gaaah. Break everything !" << std::endl;
	return ;
}

SuperMutant::SuperMutant(std::string type , int hp ) : Enemy(hp, type)
{
	std::cout << "Gaaah. Break everything !" << std::endl;
	return ;
}


SuperMutant::SuperMutant( SuperMutant const & src ) : Enemy( src )
{
	std::cout << "Gaaah. Break everything !" << std::endl;
	*this = src ;
	return ;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

SuperMutant & SuperMutant::operator=( SuperMutant const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
	{
		_hp = rhs._hp;
		_type = rhs._type;
	}
	return *this;
}

void SuperMutant::takeDamage(int damage)
{
	static int i = 0;
	i +=3;
	if (_hp - ((damage - i) > 0 ? (damage - i) : 0 ) < 0)
		_hp = 0;
	else
		_hp -= damage;
}

std::ostream & operator<<( std::ostream & o, SuperMutant const & i )
{
	o << "The value of _nb is : " << i.getType();
	return o;
}