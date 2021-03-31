#include "Victim.hpp"


Victim::Victim( std::string name ) : _name( name )
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Victim::Victim( std::string const name ) 
{
	std::cout << _name << ", " << " is born!" << std::endl;
	return ;
}

Victim::Victim( Victim const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Victim::~Victim()
{
	std::cout << "The victim " << _name << " died for no apparent reasons!" << std::endl;
	return ;
}

std::string Victim::getTitle( void ) const
{
	std::cout << "I am " << _name << " and Hoouu I like IceCream!" << std::endl;
	return _name;
}

Victim & Victim::operator=( Victim const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		this->_name = rhs.getTitle();
	return *this;
}

std::ostream & operator<<( std::ostream & o, Victim const & i )
{
	o << i.getTitle();
	return o;
}