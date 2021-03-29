#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : _hitPoints( 100 ), _maxHitPoints( 100 ), _energyPoints( 100 ),
_maxEnergyPoints( 100 ), _level( 1 ), _name( name ), _melleeAttackDamage( 30 ), _rangedAttackDamage( 20 ),
_armorDamageReduction( 5 )
{
	std::cout << "Default Constructor called"
	" Booting sequence complete... Hello! I am your new steward bot.\nDesignation:"
	" CL4P-TP, Hyperion Robot, Class C.\nPlease adjust factory settings to meet your needs before deployment ..."
	"\nsettings acknowledged... New Designation : " << name << std::endl;
	_tabAttack[0] = &FragTrap::rangedAttack;
	_tabAttack[1] = &FragTrap::meleeAttack;
	_tabAttack[2] = &FragTrap::provokeAttack;
	_tabAttack[3] = &FragTrap::fingerAttack;
	_tabAttack[4] = &FragTrap::hammerAttack;
	srand (time(NULL));
	return ;
}

FragTrap::FragTrap( int const n ) : _hitPoints( n )
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( FragTrap const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	std::cout << _name << std::endl;
	std::cout << _hitPoints << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called, withdrawal !" << std::endl;
	return ;
}

int FragTrap::getHealth( void ) const
{
	return _energyPoints;
}

FragTrap &    FragTrap::operator=( FragTrap const & rhs )
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

unsigned int		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	unsigned int dmg = 0;
	if (_energyPoints >= 25) {
		std::cout << "<FR4G-TP : " << _name << "> Place your bets!" << std::endl;
		dmg = (this->*(this->_tabAttack[rand() % 5]))( target );
		_energyPoints -= 25;
	}
	else
		std::cout << "I lack ENERGY ! where is the plug..." << std::endl;
	return dmg;
}

unsigned int		FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> This is why you do your homework! "
	<< "-20 Energy points" << target << std::endl;
	return _rangedAttackDamage;
}

unsigned int		FragTrap::meleeAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> This is for Mathilda, "
	<< target << "!" << "! -30 Energy points" << std::endl;
	return _melleeAttackDamage;
}

unsigned int		FragTrap::provokeAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> Now, Get my rangeAttack in your face, "
	<< target << " ! -5 Energy_damage" << std::endl;
	return 5;
}

unsigned int		FragTrap::fingerAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> From the tip of my finger, "
	<< target << ", Whatch this !" << " -20 Energy points" << std::endl;
	return 20;
}

unsigned int		FragTrap::hammerAttack(std::string const & target) const
{
	std::cout << "<FR4G-TP : " << _name << "> Here's what you need, ShakaBoom "
	<< target << " ! -50 Energy points" << std::endl;
	return 50;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	amount -= _armorDamageReduction;
	if (_energyPoints - amount < 0)
		_energyPoints = 0;
	else
		_energyPoints -= amount;
	return ;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints + amount > 100)
		_energyPoints = 100;
	else
		_energyPoints += amount;
	return ;
}

std::ostream &    operator<<( std::ostream & o, FragTrap const & i )
{
	o << i.getHealth();
	return o;
}