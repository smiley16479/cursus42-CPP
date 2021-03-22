#include "Brain.hpp"

Brain::Brain(int Uptime, int Task, int Load_average) :_Uptime(Uptime), _Task(Task), _Load_average(Load_average)
{
	std::cout << "Brain constructor called" << std::endl;
	return;
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

std::string Brain::identifier( void ) const
{
	std::stringstream s;
	s << this;
	return (s.str());
}