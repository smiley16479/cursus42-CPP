#include "AMateria.hpp"

AMateria::AMateria( std::string const & type, unsigned int xp) : _type( type ), _xp( xp )
{
	std::cout << "AMateria Default Constructor called" << std::endl;
	return ;
}

AMateria::AMateria( AMateria const & src )
{
	std::cout << "AMateria Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
	return ;
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return _type;
}

unsigned int AMateria::getXP() const //Returns the Materia's XP
{
	return _xp;
}

unsigned int AMateria::setXP( unsigned int x ) //Sets the Materia's XP
{
	return ( _xp = x );
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	_xp += 10;
	return ;
}

std::ostream & operator<<( std::ostream & o, AMateria const & i )
{
	o << "The type is " << i.getType() <<
	", and the _xp value is : " << i.getXP() << std::endl;
	return o;
}