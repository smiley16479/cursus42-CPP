#ifndef SCAVTRAP_CLASS_H
#define SCAVTRAP_CLASS_H

#include <iostream>

// #define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
// 1: use of the define, 2 n 3 normal syntax
// CALL_MEMBER_FN(*this, this->_tabAttack[rand() % 5])("hey");
// ((*this).*(this->_tabAttack[rand() % 5]))( target );
// (this->*(this->_tabAttack[rand() % 5]))( target );

class ScavTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( int const n );
	ScavTrap( ScavTrap const & src );
	~ScavTrap( void );

	ScavTrap&	operator=( ScavTrap const & rhs );
	void		challengeNewcomer( void );
	unsigned int	rangedAttack(std::string const & target) const;
	unsigned int	meleeAttack(std::string const & target) const;
	unsigned int	provokeAttack(std::string const & target) const;
	unsigned int	fingerAttack(std::string const & target) const;
	unsigned int	hammerAttack(std::string const & target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		getHealth(void) const;
	std::string _name;

private:
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	unsigned int _melleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorDamageReduction;
	// https://isocpp.org/wiki/faq/pointers-to-members (cpp pointer on member function) :
	unsigned int (ScavTrap::*_tabAttack[5])(std::string const & target) const; 

};


std::ostream &    operator<<( std::ostream & o, ScavTrap const & i );

#endif
