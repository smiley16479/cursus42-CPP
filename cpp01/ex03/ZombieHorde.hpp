#ifndef ZOMBIEHORDE_CLASS_HPP
#define ZOMBIEHORDE_CLASS_HPP
#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include "Zombie.hpp"

class ZombieHorde
{
private:
	Zombie *_horde;
	int _nb;

public:
	ZombieHorde(int n);
	~ZombieHorde( void );

	void randomChump(Zombie *to_return);
	void announce(void);
};

#endif