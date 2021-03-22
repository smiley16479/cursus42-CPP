#include "Pony.hpp"

Pony::Pony( int size, std::string color, std::string name ) : size(size), color(color), name(name) 
{
	std::cout << "constructor called" << std::endl;
	this->secoue_ma_criniere(this->name);
	return;
}

Pony::~Pony( void )
{
	std::cout << "destructor called" << std::endl;
	return ;
}

int Pony::trote( void ) const
{
	std::cout << "tchikipoum,tchikipoum,tchikipoum..." << std::endl;
	return (0);
}
int Pony::galop( void ) const
{
	std::cout << "Tagada, tagada, tagada... Hihihiiiihhii" << std::endl;
	return (0);
}
int Pony::secoue_ma_criniere( std::string name ) const
{
	std::cout << "Je suis " << name << " et je secoue ma crinière" << std::endl;
	return (0);
}