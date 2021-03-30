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
	*this = src ;
	// std::cout << _name << std::endl;
	// std::cout << _hitPoints << std::endl;
	return ;
}

NinjaTrap &    NinjaTrap::operator=( NinjaTrap const & rhs )
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
	std::cout << "<NINJ4-TP : " << _name << "> Hey FragTrap, take that onigiriJutsu in your face  !" << std::endl;
	target.takeDamage(50);
	return 20;
}

unsigned int		NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	unsigned int dmg = 0;
	std::cout << "<NINJ4-TP : " << _name << "> Hey ScavTrap, take that naniJutsu in your face !" << std::endl;
	target.takeDamage(50);
	return 10;
}

unsigned int		NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	unsigned int dmg = 0;
	std::cout << "<NINJ4-TP : " << _name << "> Hey Brother, Here take a refull !" << std::endl;
	target.beRepaired(120);
	return 0;
}