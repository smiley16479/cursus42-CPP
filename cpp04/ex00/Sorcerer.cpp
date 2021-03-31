#include "Sorcerer.hpp"


Sorcerer::Sorcerer( std::string name, std::string title ) : _name( name ), _title( title )
{
	std::cout << _name << ", " << _title << " is born!" << std::endl;
	return ;
}

Sorcerer::Sorcerer( std::string const title ) : _name( "nobody" ), _title( title )
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

std::string Sorcerer::getTitle( void ) const
{
	std::string str = "I am ";
	str += _name;
	str += ", ";
	str += _title;
	str += ", and I love the smell of napalm in the morning!\n";
	return str;
}

Sorcerer & Sorcerer::operator=( Sorcerer const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		_title = rhs.getTitle();
	return *this;
}

void Sorcerer::polymorph(Victim const & i) const
{
	i.getPolymorphed();
	return ;
}

std::ostream & operator<<( std::ostream & o, Sorcerer const & i )
{
	o << i.getTitle();
	return o;
}