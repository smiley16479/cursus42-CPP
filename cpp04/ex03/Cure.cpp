#include "Cure.hpp"

Cure::Cure( std::string const & type ) : AMateria(type, 0)
{
	std::cout << "Cure Default Constructor called" << std::endl;
	return ;
}

Cure::Cure( Cure const & src ) : AMateria()
{
	std::cout << "Cure Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
	return ;
}

AMateria* Cure::clone( void ) const
{
	AMateria* tmp = new Cure;
	tmp->setXP( _xp );
	return tmp;
}

void Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals " + target.getName() + "’s wounds *" << std::endl;
	return ;
}

Cure & Cure::operator=( Cure const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		_nb = rhs._nb;
	return *this;
}

std::ostream & operator<<( std::ostream & o, Cure const & i )
{
	o << "The Cure _xp is : " << i.getXP();
	return o;
}