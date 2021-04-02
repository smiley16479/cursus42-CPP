#include "PowerFist.hpp"

PowerFist::PowerFist( std::string _name, int _damage , int _apcost , std::string _attackOutput )
{
	(void)_name;
	(void)_damage;
	(void)_apcost;
	(void)_attackOutput;
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

PowerFist::PowerFist( PowerFist const & src ) : AWeapon(src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

PowerFist::~PowerFist()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int PowerFist::getDamage( void ) const
{
	return _damage;
}

void PowerFist::attack( void ) const
{
	std::cout << _attackOutput << std::endl;
}


PowerFist & PowerFist::operator=( PowerFist const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
	{
		_name = rhs._name;
		_damage = rhs._damage;
		_apcost = rhs._apcost;
		_attackOutput = rhs._attackOutput;
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, PowerFist const & i )
{
	o << i.getDamage();
	return o;
}