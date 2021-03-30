#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hitPoints( 100 ), _maxHitPoints( 100 ), _energyPoints( 100 ),
_maxEnergyPoints( 100 ), _level( 1 ), _melleeAttackDamage( 30 ), _rangedAttackDamage( 20 ),
_armorDamageReduction( 5 )
{
	std::cout << "ClapTrap Default Constructor called"
	" Booting sequence complete... Hello! I am your new steward bot.\nDesignation:"
	" CL4P-TP, Hyperion Robot, Class C.\nPlease adjust factory settings to meet your needs before deployment ..."
	"\nsettings acknowledged... New Designation : " << name << std::endl;
	_tabAttack[0] = &ClapTrap::rangedAttack;
	_tabAttack[1] = &ClapTrap::meleeAttack;
	_tabAttack[2] = &ClapTrap::provokeAttack;
	_tabAttack[3] = &ClapTrap::fingerAttack;
	_tabAttack[4] = &ClapTrap::hammerAttack;
	srand (time(NULL));
	return ;
}

ClapTrap::ClapTrap( int const n ) : _hitPoints( n )
{
	std::cout << "ClapTrap Parametric Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src )
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = src ;
	std::cout << _name << std::endl;
	std::cout << _hitPoints << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called, withdrawal !" << std::endl;
	return ;
}

int ClapTrap::getHealth( void ) const
{
	return _energyPoints;
}

ClapTrap &    ClapTrap::operator=( ClapTrap const & rhs )
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

unsigned int		ClapTrap::rangedAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> This is why you do your homework! -"
	<< _rangedAttackDamage << " Energy points" << target << std::endl;
	return _rangedAttackDamage;
}

unsigned int		ClapTrap::meleeAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> This is for Mathilda, "
	<< target << "!! -" << _melleeAttackDamage << " Energy points" << std::endl;
	return _melleeAttackDamage;
}

unsigned int		ClapTrap::provokeAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> Now, Get my rangeAttack in your face, "
	<< target << " ! -5 Energy_damage" << std::endl;
	return 5;
}

unsigned int		ClapTrap::fingerAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> From the tip of my finger, "
	<< target << ", Whatch this !" << " -20 Energy points" << std::endl;
	return 20;
}

unsigned int		ClapTrap::hammerAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> Here's what you need, ShakaBoom "
	<< target << " ! -50 Energy points" << std::endl;
	return 50;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	amount -= _armorDamageReduction;
	if (_energyPoints - (int)amount < 0)
		_energyPoints = 0;
	else
		_energyPoints -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints + amount > 100)
		_energyPoints = 100;
	else
		_energyPoints += amount;
	return ;
}

std::ostream &    operator<<( std::ostream & o, ClapTrap const & i )
{
	o << i.getHealth();
	return o;
}