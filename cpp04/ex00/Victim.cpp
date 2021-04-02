#include "Victim.hpp"

Victim::Victim( std::string const name ) : _name( name )
{
	std::cout << "A random victim called " + _name + " just appeared!" << std::endl;
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
	return ("I am " + _name + " and Hoouu I like IceCream!\n");
}

Victim & Victim::operator=( Victim const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		this->_name = rhs.getTitle();
	return *this;
}

void Victim::getPolymorphed( void ) const
{
	std::cout << _name << " was just polymorphed in a cute little sheep!" << std::endl;
}

std::ostream & operator<<( std::ostream & o, Victim const & i )
{
	o << i.getTitle();
	return o;
}