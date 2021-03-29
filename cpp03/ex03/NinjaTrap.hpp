#ifndef NINJATRAP_CLASS_H
#define NINJATRAP_CLASS_H

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap( void );
	NinjaTrap( std::string name );
	NinjaTrap( int const n );
	NinjaTrap( NinjaTrap const & src );
	~NinjaTrap( void );

	NinjaTrap&	operator=( NinjaTrap const & rhs );	
	unsigned int	NinjaTrap::ninjaShoebox(ClapTrap & target);
	unsigned int	NinjaTrap::ninjaShoebox(FragTrap & target);
	unsigned int	NinjaTrap::ninjaShoebox(ScavTrap & target);
	unsigned int	NinjaTrap::ninjaShoebox(NinjaTrap & target);

};


std::ostream &    operator<<( std::ostream & o, NinjaTrap const & i );

#endif
