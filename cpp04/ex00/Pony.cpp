#include "Pony.hpp"

Pony::Pony( std::string name ) : Victim( name ), _nb( 0 )
{
	std::cout << "PPffllouuuu" << std::endl;
	return ;
}

Pony::Pony( Pony const & src ): Victim( src )
{
	std::cout << "HiiiiiHannnn" << std::endl;
	*this = src ;
	return ;
}

Pony::~Pony()
{
	std::cout <<  "This is the end of our beloved Pony" << std::endl;
	return ;
}

std::string Pony::getName( void ) const
{
	return ("Hiiiiiiii " + _name + "\n");
}

Pony & Pony::operator=( Pony const & rhs )
{
	std::cout << "HiiiiiHannnn?" << std::endl;
	if (this != &rhs )
		this->_name = rhs.getName();
	return *this;
}

void Pony::getPolymorphed( void ) const
{
	std::cout << _name << " was just polymorphed into a Peon!" << std::endl;
	return ;
}

std::ostream & operator<<( std::ostream & o, Pony const & i )
{
	o << i.getName();
	return o;
}