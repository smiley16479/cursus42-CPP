#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include "unistd.h"

int main()
{
	ZombieHorde horde(2);
	horde.announce();
	usleep(1000000);
	return(0);
}