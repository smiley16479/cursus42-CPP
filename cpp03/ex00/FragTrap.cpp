#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : _hitPoints( 0 )
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( int const n ) : _hitPoints( n )
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( FragTrap const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int FragTrap::getNb( void ) const
{
	return this->_hitPoints;
}

FragTrap &    FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		this->_hitPoints = rhs.getNb();
	return *this;
}

std::ostream &    operator<<( std::ostream & o, FragTrap const & i )
{
	o << "The value of _nb is : " << i.getNb();
	return o;
}