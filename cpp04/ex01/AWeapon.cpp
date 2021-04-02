#include "AWeapon.hpp"


AWeapon::AWeapon( void ) : _name( "unknow" ), _apcost( 0 ), _damage( 0 )
{
	std::cout << "AWeapon Default Constructor called" << std::endl;
	return ;
}

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) : _name( name ), _apcost( apcost ), _damage( damage )
{
	std::cout << "AWeapon Parametric Constructor called" << std::endl;
	return ;
}

AWeapon::AWeapon( AWeapon const & src )
{
	std::cout << "AWeapon Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

AWeapon::~AWeapon()
{
	std::cout << "AWeapon Destructor called" << std::endl;
	return ;
}

std::string AWeapon::getName( void ) const
{
	return _name;
}

int AWeapon::getAPCost( void ) const
{
	return _apcost;
}

int AWeapon::getDamage( void ) const
{
	return this->_damage;
}

AWeapon & AWeapon::operator=( AWeapon const & rhs )
{
	std::cout << "AWeapon Assignment operator called" << std::endl;
	if (this != &rhs )
	{
		_name = rhs._name;
		_apcost = rhs._apcost;
		_damage = rhs._damage;
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, AWeapon const & i )
{
	o << "Ds operator << de AWeapon " + i.getName() << std::endl;
	return o;
}