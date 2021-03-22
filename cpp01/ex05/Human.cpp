#include "Human.hpp"

Human::Human( void )
{
	std::cout << "Human constructor called" << std::endl;
	return;
}

Human::~Human( void )
{
	std::cout << "Human destructor called" << std::endl;
	return ;
}

Brain const &Human::getBrain( void )
{
	return (this->_brain);
}

/* Brain const Human::getBrain( void )
{
	return (this->_brain);
}
 */

std::string const Human::identifier( void )
{
	return this->_brain.identifier();
}