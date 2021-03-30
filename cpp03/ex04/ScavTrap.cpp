#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) :  ClapTrap(name)
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_melleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	std::cout << "settings acknowledged... New system configuration : ScavTrap" << std::endl;
	return ;
}

ScavTrap::ScavTrap( int const n ) : ClapTrap(n)
{
	std::cout << "ScavTrap Parametric Constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = src ;
	// std::cout << _name << std::endl;
	// std::cout << _hitPoints << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called, withdrawal !" << std::endl;
	return ;
}

ScavTrap &    ScavTrap::operator=( ScavTrap const & rhs )
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

std::ostream &    operator<<( std::ostream & o, ScavTrap const & i )
{
	o << i.getHealth();
	return o;
}

void				ScavTrap::challengeNewcomer( void )
{
	std::string tab[] = {"Now, your choice : wheither you stand up on the finger for half an hour or I make a colander of you !!\n",
		"I'll cut your head off...Unless you can name four US's presidents\n", "I'll rip your arms Unless you can hit this target\n",
		"I kill you, unless... you kill me\n", "I let you pass if you brought chocolate...Hoooo Love it\n"};
		std::cout << "<SC4V-TP : " << _name << "> I am a tornado of death and bullets!" << std::endl;
		std::cout << tab[rand() % 5];
	return ;
}


//AVANT MODIFICATIONS
/*
ScavTrap::ScavTrap( std::string name ) : _hitPoints( 100 ), _maxHitPoints( 100 ), _energyPoints( 50 ),
_maxEnergyPoints( 50 ), _level( 1 ), _name( name ), _melleeAttackDamage( 20 ), _rangedAttackDamage( 15 ),
_armorDamageReduction( 3 )
{
	std::cout << "Default Constructor called"
	" Booting sequence complete... Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!"
	"\nsettings acknowledged... Designation : " << name << std::endl;
	_tabAttack[0] = &ScavTrap::rangedAttack;
	_tabAttack[1] = &ScavTrap::meleeAttack;
	_tabAttack[2] = &ScavTrap::provokeAttack;
	_tabAttack[3] = &ScavTrap::fingerAttack;
	_tabAttack[4] = &ScavTrap::hammerAttack;
	srand (time(NULL));
	return ;
}

ScavTrap::ScavTrap( int const n ) : _hitPoints( n )
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	std::cout << _name << std::endl;
	std::cout << _hitPoints << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called, Don't forget me!!" << std::endl;
	return ;
}

int ScavTrap::getHealth( void ) const
{
	return _energyPoints;
}

ScavTrap &    ScavTrap::operator=( ScavTrap const & rhs )
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

void				ScavTrap::challengeNewcomer( void )
{
	std::string tab[] = {"Now, your choice : wheither you stand up on the finger for half an hour or I make a colander of you !!\n",
		"I'll cut your head off...Unless you can name four US's presidents\n", "I'll rip your arms Unless you can hit this target\n",
		"I kill you, unless... you kill me\n", "I let you pass if you brought chocolate...Hoooo Love it\n"};
		std::cout << "<SC4V-TP : " << _name << "> I am a tornado of death and bullets!" << std::endl;
		std::cout << tab[rand() % 5];
	return ;
}

unsigned int		ScavTrap::rangedAttack(std::string const & target) const
{
	std::cout << "<SC4V-TP : " << _name << "> Love bullets! "
	<< "-20 Energy points" << target << std::endl;
	return _rangedAttackDamage;
}

unsigned int		ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << "<SC4V-TP : " << _name << "> Nurse Trap is here! "
	<< target << "!" << "! -30 Energy points" << std::endl;
	return _melleeAttackDamage;
}

unsigned int		ScavTrap::provokeAttack(std::string const & target) const
{
	std::cout << "<SC4V-TP : " << _name << "> I'm made of magic "
	<< target << " ! -5 Energy_damage" << std::endl;
	return 5;
}

unsigned int		ScavTrap::fingerAttack(std::string const & target) const
{
	std::cout << "<SC4V-TP : " << _name << "> Kill, reload! Kill, reload! KILL! RELOAD! "
	<< target << ", Whatch this !" << " -20 Energy points" << std::endl;
	return 20;
}

unsigned int		ScavTrap::hammerAttack(std::string const & target) const
{
	std::cout << "<SC4V-TP : " << _name << "> Uh, how do I cast magic missile, "
	<< target << ", do you know ?! -50 Energy points" << std::endl;
	return 50;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	amount -= _armorDamageReduction;
	if (_energyPoints - amount < 0)
		_energyPoints = 0;
	else
		_energyPoints -= amount;
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints + amount > 100)
		_energyPoints = 100;
	else
		_energyPoints += amount;
	return ;
}*/