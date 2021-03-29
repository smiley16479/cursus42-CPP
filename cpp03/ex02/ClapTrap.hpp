#ifndef CLAPTRAP_CLASS_H
#define CLAPTRAP_CLASS_H

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class ClapTrap : public FragTrap, public ScavTrap
{
public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( int const n );
	ClapTrap( ClapTrap const & src );
	~ClapTrap( void );

private:

};

std::ostream &    operator<<( std::ostream & o, ClapTrap const & i );

#endif
