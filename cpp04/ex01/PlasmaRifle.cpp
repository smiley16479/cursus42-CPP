#include "PlasmaRifle.hpp"

/*
PlasmaRifle::PlasmaRifle( void )
// : AWeapon(_name = "Plasma Rifle", _apcost = 5, _damage = 21 ),
: AWeapon("Plasma Rifle",  5, 21 ),
// _name( "Plasma Rifle" ), _damage( 21 ), _apcost( 5 ), 
_attackOutput("* piouuu piouuu piouuu *")
{
	std::cout << "PlasmaRifle Default Constructor called" << std::endl;
	return ;
}*/

PlasmaRifle::PlasmaRifle( std::string name, int apcost , int damage , std::string attackOutput )
// : AWeapon( _name = name, _apcost = apcost, _damage = damage ), // <-- pas bon 
: AWeapon( name, apcost, damage ), _attackOutput(attackOutput)
// : _name( "Plasma " ), _damage( 21 ), _apcost( 5 ) // <-- pas bon 
// (:)_attackOutput(attackOutput)
{
	// (void)name;
	// (void)apcost;
	// (void)damage;
	// (void)attackOutput;
	std::cout << "PlasmaRifle Default Constructor called" << std::endl;
	return ;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & src ) : AWeapon(src)
{
	std::cout << "PlasmaRifle Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

PlasmaRifle::~PlasmaRifle()
{
	std::cout << "PlasmaRifle Destructor called" << std::endl;
	return ;
}

int PlasmaRifle::getDamage( void ) const
{
	return _damage;
}

void PlasmaRifle::attack( void ) const
{
	std::cout << _attackOutput << std::endl;
}

std::string PlasmaRifle::getName( void ) const
{
	return _name;
}

PlasmaRifle & PlasmaRifle::operator=( PlasmaRifle const & rhs )
{
	std::cout << "PlasmaRifle Assignment operator called" << std::endl;
	if (this != &rhs )
	{
		_name = rhs._name;
		_damage = rhs._damage;
		_apcost = rhs._apcost;
		_attackOutput = rhs._attackOutput;
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, PlasmaRifle const & i )
{
	o << i.getDamage();
	return o;
}