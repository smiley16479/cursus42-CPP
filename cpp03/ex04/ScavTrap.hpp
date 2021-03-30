#ifndef SCAVTRAP_CLASS_H
#define SCAVTRAP_CLASS_H

#include <iostream>
#include "ClapTrap.hpp"

// #define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
// 1: use of the define, 2 n 3 normal syntax
// CALL_MEMBER_FN(*this, this->_tabAttack[rand() % 5])("hey");
// ((*this).*(this->_tabAttack[rand() % 5]))( target );
// (this->*(this->_tabAttack[rand() % 5]))( target );

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( int const n );
	ScavTrap( ScavTrap const & src );
	~ScavTrap( void );

	ScavTrap&	operator=( ScavTrap const & rhs );
	void		challengeNewcomer( void );

};


std::ostream &    operator<<( std::ostream & o, ScavTrap const & i );

#endif
