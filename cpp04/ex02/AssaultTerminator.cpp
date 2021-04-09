#include "AssaultTerminator.hpp"


AssaultTerminator::AssaultTerminator( void ) : _nb( 0 )
{
	std::cout << "Default Constructor called" << std::endl;
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator( int const n /* = 2  */) : _nb( n )
{
	std::cout << "Parametric Constructor called" << std::endl;
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator( AssaultTerminator const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	std::cout << "* teleports from space *" << std::endl;
	*this = src ;
	return ;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "AssaultTerminator Destructor called" << std::endl;
	std::cout << "I’ll be back ..." << std::endl;
	return ;
}

int AssaultTerminator::getNb( void ) const
{
	return _nb;
}

ISpaceMarine* AssaultTerminator::clone() const 
{
	return (ISpaceMarine*)(new AssaultTerminator(_nb));
}

void AssaultTerminator::battleCry() const 
{
	std::cout << "This code is unclean. Purify it !" << std::endl;
	return ;
}

void AssaultTerminator::rangedAttack() const 
{
	std::cout << "* does nothing *" << std::endl;
	return ;
}

void AssaultTerminator::meleeAttack() const 
{
	std::cout << "* attaque with chainfists *" << std::endl;
	return ;
}


AssaultTerminator & AssaultTerminator::operator=( AssaultTerminator const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		_nb = rhs._nb;
	return *this;
}

std::ostream & operator<<( std::ostream & o, AssaultTerminator const & i )
{
	o << "I am a Assault Terminator, Matricule : " << i.getNb() <<  std::endl;
	return o;
}