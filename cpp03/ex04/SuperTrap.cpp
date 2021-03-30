#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) :  ClapTrap(name) ,  NinjaTrap(name) , FragTrap(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_melleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	std::cout << "SuperTrap Default Constructor called" << std::endl;
	std::cout << "settings acknowledged... New system configuration : SuperTrap" << std::endl;
	
	return ;
}

SuperTrap::SuperTrap( int const n ) : ClapTrap(n) ,NinjaTrap(n) , FragTrap(n)
{
	std::cout << "SuperTrap Parametric Constructor called" << std::endl;
	return ;
}

SuperTrap::SuperTrap( SuperTrap const & src ) : ClapTrap(src) ,NinjaTrap(src) , FragTrap(src)
{
	std::cout << "SuperTrap Copy Constructor called" << std::endl;
	*this = src ;
	// std::cout << _name << std::endl;
	// std::cout << _hitPoints << std::endl;
	return ;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap Destructor called, withdrawal !" << std::endl;
	return ;
}

SuperTrap &    SuperTrap::operator=( SuperTrap const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if ( this != &rhs ) {
		_hitPoints = rhs._hitPoints;
		_maxHitPoints = rhs._maxHitPoints;
		_energyPoints = rhs._energyPoints;
		_maxEnergyPoints = rhs._maxEnergyPoints;
		_level = rhs._level;
		_name = rhs._name;
		_melleeAttackDamage = rhs._melleeAttackDamage;
		_rangedAttackDamage = rhs._rangedAttackDamage;
		_armorDamageReduction = rhs._armorDamageReduction;
		for (int i = 0; i < 5; ++i)
			_tabAttack[i] = rhs._tabAttack[i];
	}
	return *this;
}

std::ostream &    operator<<( std::ostream & o, SuperTrap const & i )
{
	o << i.getHealth();
	return o;
}