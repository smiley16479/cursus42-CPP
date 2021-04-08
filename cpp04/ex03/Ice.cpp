#include "Ice.hpp"

Ice::Ice( std::string const & type ) : AMateria(type)
{
	std::cout << "Ice Default Constructor called" << std::endl;
	return ;
}

Ice::Ice( Ice const & src ) : AMateria()
{
	std::cout << "Ice Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
	return ;
}

AMateria* Ice::clone( void ) const
{
	AMateria* tmp = new Ice;
	tmp->setXP( _xp );
	return tmp;
}

void Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout <<  "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
	return ;
}

Ice & Ice::operator=( Ice const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		_nb = rhs._nb;
	return *this;
}

std::ostream & operator<<( std::ostream & o, Ice const & i )
{
	o << "The Ice _xp is : " << i.getXP();
	return o;
}