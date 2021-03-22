#ifndef ZOMBIE_EVENT_CLASS_HPP
#define ZOMBIE_EVENT_CLASS_HPP
#include <iostream>
#include <string>
#include <array>
#include <stdlib.h>
#include <iomanip>
#include "Zombie.hpp"

class ZombieEvent
{
private:
	int type;

public:
	ZombieEvent( void );
	~ZombieEvent( void );

	std::string name;
	int setZombieType(int type);
	Zombie *newZombie (std::string name);
	Zombie *randomChump(void);
	void announce(Zombie *zombie);
};

#endif