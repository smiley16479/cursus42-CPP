#include "Sorcerer.hpp"


Sorcerer::Sorcerer( std::string name, int title ) : _name( name ), _title( title )
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Sorcerer::Sorcerer( int const n ) : _name( "nobody" ), _title( n )
{
	std::cout << _name << ", " << _title << " is born!" << std::endl;
	return ;
}

Sorcerer::Sorcerer( Sorcerer const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << " is dead. Consequences will never be the same!" << std::endl;
	return ;
}

int Sorcerer::getTitle( void ) const
{
	std::cout << "I am " << _name << ", " << _title << ", and I love the smell of napalm in the morning!" << std::endl;
	return this->_title;
}

Sorcerer & Sorcerer::operator=( Sorcerer const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		this->_title = rhs.getTitle();
	return *this;
}

std::ostream & operator<<( std::ostream & o, Sorcerer const & i )
{
	o << i.getTitle();
	return o;
}