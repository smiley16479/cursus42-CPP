#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent zombie_event;
	zombie_event.setZombieType(1);
	Zombie *zombie1 = zombie_event.randomChump();
	zombie1->advert();

	zombie_event.setZombieType(2);
	Zombie *zombie2 = zombie_event.newZombie("fleur_des_champs");
	zombie2->advert();

	zombie_event.setZombieType(3);
	Zombie *zombie3 = zombie_event.randomChump();
	zombie3->advert();

	delete zombie1;
	delete zombie2;
	delete zombie3;
	return(0);
}