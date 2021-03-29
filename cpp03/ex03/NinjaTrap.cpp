#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) :  ClapTrap(name)
{
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_melleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	std::cout << "NinjaTrap Default Constructor called" << std::endl;
	std::cout << "settings acknowledged... New system configuration : NinjaTrap" << std::endl;
	
	return ;
}

NinjaTrap::NinjaTrap( int const n ) : ClapTrap(n)
{
	std::cout << "NinjaTrap Parametric Constructor called" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap( NinjaTrap const & src ) : ClapTrap(src)
{
	std::cout << "NinjaTrap Copy Constructor called" << std::endl;
	// *this = src ;
	// std::cout << _name << std::endl;
	// std::cout << _hitPoints << std::endl;
	return ;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap Destructor called, withdrawal !" << std::endl;
	return ;
}

unsigned int		NinjaTrap::ninjaShoebox(ClapTrap & target)
{
	unsigned int dmg = 0;
	std::cout << "<NINJ4-TP : " << _name << "> Hey Mother ClapTrap, can I help You ?" << std::endl;
	target.beRepaired(50);
	return 0;
}

unsigned int		NinjaTrap::ninjaShoebox(FragTrap & target)
{
	unsigned int dmg = 0;
	std::cout << "<NINJ4-TP : " << _name << "> Hey Brother FragTrap, Here take a refull !" << std::endl;
	target.beRepaired(120);
	return 20;
}

unsigned int		NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	unsigned int dmg = 0;
	std::cout << "<NINJ4-TP : " << _name << "> Hey Brother ScavTrap, Here take a refull !" << std::endl;
	target.beRepaired(120);
	return 10;
}

unsigned int		NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	unsigned int dmg = 0;
	std::cout << "<NINJ4-TP : " << _name << "> Hey Friend, Here take a refull !" << std::endl;
	target.beRepaired(120);
	return 0;
}