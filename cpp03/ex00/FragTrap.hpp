#ifndef FRAGTRAP_CLASS_H
#define FRAGTRAP_CLASS_H

#include <iostream>


class FragTrap
{
public:
	FragTrap( void );
	FragTrap( int const n );
	FragTrap( FragTrap const & src );
	~FragTrap( void );

	FragTrap&	operator=( FragTrap const & rhs );
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		getNb(void) const;

private:
	int _hitPoints;
	int _maxHitPoints;
	int _maxHealthPoints;
	int _level;
	std::string _name;
	int _melleeAttackDamage;
	int _rangedAttackDamage;
	int _armorDamageReduction;

};


std::ostream &    operator<<( std::ostream & o, FragTrap const & i );

#endif
