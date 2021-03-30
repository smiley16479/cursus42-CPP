#ifndef SUPERTRAP_CLASS_H
#define SUPERTRAP_CLASS_H

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : virtual public ClapTrap, public NinjaTrap, public FragTrap
{
public:
	SuperTrap( void );
	SuperTrap( std::string name );
	SuperTrap( int const n );
	SuperTrap( SuperTrap const & src );
	~SuperTrap( void );

	SuperTrap&	operator=( SuperTrap const & rhs );	

};


std::ostream &    operator<<( std::ostream & o, SuperTrap const & i );

#endif
