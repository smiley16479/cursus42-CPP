#ifndef CLAPTRAP_CLASS_H
#define CLAPTRAP_CLASS_H

#include <iostream>
#include <stdlib.h>

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
	int _hitPoints;
	int _maxHitPoints;
	int _energyPoints;
	int _maxEnergyPoints;
	int _level;
	int _melleeAttackDamage;
	int _rangedAttackDamage;
	int _armorDamageReduction;
	// https://isocpp.org/wiki/faq/pointers-to-members (cpp pointer on member function) :
	unsigned int (ClapTrap::*_tabAttack[5])(std::string const & target) const; 

};

std::ostream &    operator<<( std::ostream & o, ClapTrap const & i );

#endif
