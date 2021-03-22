#ifndef HUMAN_CLASS_HPP
#define HUMAN_CLASS_HPP

#include "Brain.hpp"

class Human
{
private:
	Brain const _brain;
public:
	Human( void );
	~Human( void );

	std::string const identifier( void );
	Brain const &getBrain( void );
	// Brain const getBrain( void );
};

#endif