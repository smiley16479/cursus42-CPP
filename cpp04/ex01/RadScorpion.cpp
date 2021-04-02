#include "RadScorpion.hpp"


RadScorpion::RadScorpion( void ) : Enemy( 80, "RadScorpion" )
{
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::RadScorpion(std::string type , int hp ) : Enemy(hp, type)
{
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::RadScorpion( RadScorpion const & src ) : Enemy( src )
{
	std::cout << "* click click click *" << std::endl;
	*this = src ;
	return ;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
	return ;
}

void RadScorpion::takeDamage(int damage)
{
	static int i = 0;
	i +=3;
	if (_hp - ((damage - i) > 0 ? (damage - i) : 0 ) < 0)
		_hp = 0;
	else
		_hp -= damage;
}

std::ostream & operator<<( std::ostream & o, RadScorpion const & i )
{
	o << i.getType();
	return o;
}