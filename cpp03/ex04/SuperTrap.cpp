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

// SuperTrap::SuperTrap( int const n ) : ClapTrap(n)
// {
// 	std::cout << "SuperTrap Parametric Constructor called" << std::endl;
// 	return ;
// }

SuperTrap::SuperTrap( SuperTrap const & src ) : ClapTrap(src) ,NinjaTrap(src) , FragTrap(src)
{
	std::cout << "SuperTrap Copy Constructor called" << std::endl;
	// *this = src ;
	// std::cout << _name << std::endl;
	// std::cout << _hitPoints << std::endl;
	return ;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap Destructor called, withdrawal !" << std::endl;
	return ;
}

// unsigned int		SuperTrap::rangedAttack(std::string const & target) const
// {
// 	return (ClapTrap::rangedAttack(target));
// }

// unsigned int		SuperTrap::meleeAttack(std::string const & target) const
// {
// 	return (ClapTrap::meleeAttack(target));
// }