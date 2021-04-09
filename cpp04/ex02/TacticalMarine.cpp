#include "TacticalMarine.hpp"


TacticalMarine::TacticalMarine( void ) : _nb( 0 )
{
	std::cout << "Default Constructor called" << std::endl;
	std::cout << "Tactical Marine ready for action !" << std::endl;
	return ;
}

TacticalMarine::TacticalMarine( int const n /* = 2 */) : _nb( n )
{
	std::cout << "Parametric Constructor called" << std::endl;
	std::cout << "Tactical Marine ready for action !" << std::endl;
	return ;
}

TacticalMarine::TacticalMarine( TacticalMarine const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	std::cout << "Tactical Marine ready for action !" << std::endl;
	*this = src ;
	return ;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "TacticalMarine Destructor called" << std::endl;
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

int TacticalMarine::getNb( void ) const
{
	return _nb;
}

ISpaceMarine* TacticalMarine::clone() const 
{
	return (ISpaceMarine*)(new TacticalMarine(_nb));
}

void TacticalMarine::battleCry() const 
{
	std::cout << "For the Holy PLOT !" << std::endl;
	return ;
}

void TacticalMarine::rangedAttack() const 
{
	std::cout << "* attacks with a bolter *" << std::endl;
	return ;
}

void TacticalMarine::meleeAttack() const 
{
	std::cout << "* attacks with a chainsword *" << std::endl;
	return ;
}


TacticalMarine & TacticalMarine::operator=( TacticalMarine const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
		_nb = rhs._nb;
	return *this;
}

std::ostream & operator<<( std::ostream & o, TacticalMarine const & i )
{
	o << "I am a Tactical Marine Matricule : " << i.getNb() <<  std::endl;
	return o;
}