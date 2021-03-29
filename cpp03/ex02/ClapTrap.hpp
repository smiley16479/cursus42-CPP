#ifndef CLAPTRAP_CLASS_H
#define CLAPTRAP_CLASS_H

#include <iostream>

class ClapTrap
{
public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( int const n );
	ClapTrap( ClapTrap const & src );
	~ClapTrap( void );

	ClapTrap&	operator=( ClapTrap const & rhs );
	unsigned int	rangedAttack(std::string const & target) const;
	unsigned int	meleeAttack(std::string const & target) const;
	unsigned int	provokeAttack(std::string const & target) const;
	unsigned int	fingerAttack(std::string const & target) const;
	unsigned int	hammerAttack(std::string const & target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		getHealth(void) const;
	std::string _name;

protected:
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	unsigned int _melleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorDamageReduction;
	// https://isocpp.org/wiki/faq/pointers-to-members (cpp pointer on member function) :
	unsigned int (ClapTrap::*_tabAttack[5])(std::string const & target) const; 

};

std::ostream &    operator<<( std::ostream & o, ClapTrap const & i );

#endif
