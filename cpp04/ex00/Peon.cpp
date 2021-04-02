#include "Peon.hpp"

Peon::Peon( std::string name ) : Victim( name ), _nb( 0 )
{
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::Peon( Peon const & src ): Victim( src )
{
	std::cout << "Zog zog." << std::endl;
	*this = src ;
	return ;
}

Peon::~Peon()
{
	std::cout <<  "Bleuark..." << std::endl;
	return ;
}

std::string Peon::getName( void ) const
{
	return ("Naaame... Meee... (" + _name + ")\n");
}

Peon & Peon::operator=( Peon const & rhs )
{
	std::cout << "Zog zog?" << std::endl;
	if (this != &rhs )
		this->_name = rhs.getName();
	return *this;
}

void Peon::getPolymorphed( void ) const
{
	std::cout << _name << " was just polymorphed into a pink pony!" << std::endl;
	return ;
}

std::ostream & operator<<( std::ostream & o, Peon const & i )
{
	o << i.getName();
	return o;
}