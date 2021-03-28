#ifndef FRAGTRAP_CLASS_H
#define FRAGTRAP_CLASS_H

#include <iostream>


class FragTrap
{
public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( int const n );
	FragTrap( FragTrap const & src );
	~FragTrap( void );

	FragTrap&	operator=( FragTrap const & rhs );
	void	vaulthunter_dot_exe(std::string const & target);
	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	provokeAttack(std::string const & target) const;
	void	fingerAttack(std::string const & target) const;
	void	hammerAttack(std::string const & target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		getHealth(void) const;

private:
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	std::string _name;
	unsigned int _melleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorDamageReduction;
	void (FragTrap::*_tabAttack[5])(std::string const & target) const; // https://isocpp.org/wiki/faq/pointers-to-members (cpp pointer on member function) https://www.tutorialspoint.com/function-pointer-to-member-function-in-cplusplus

};


std::ostream &    operator<<( std::ostream & o, FragTrap const & i );

#endif
