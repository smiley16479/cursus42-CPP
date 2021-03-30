#ifndef FRAGTRAP_CLASS_H
#define FRAGTRAP_CLASS_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( int const n );
	FragTrap( FragTrap const & src );
	~FragTrap( void );

	FragTrap&	operator=( FragTrap const & rhs );
	unsigned int	vaulthunter_dot_exe(std::string const & target);

};


std::ostream &    operator<<( std::ostream & o, FragTrap const & i );

#endif
