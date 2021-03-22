#include "ZombieEvent.hpp"
#include "Zombie.hpp"


ZombieEvent::ZombieEvent( void )
{
	std::cout << "constructor called" << std::endl;
	srand (time(NULL));
	return;
}

ZombieEvent::~ZombieEvent( void )
{
	std::cout << "destructor called" << std::endl;
	return;
}

int ZombieEvent::setZombieType(int type)
{
	return(this->type = type);
}

Zombie *ZombieEvent::newZombie (std::string name)
{
	Zombie *to_return = new Zombie(this->type, name);
	return (to_return);
}

Zombie *ZombieEvent::randomChump(void)
{
	std::array<std::string, 10> petits_noms = {"Arrrggghhh", "Heeeeuuuu",
	"Agnagnagna", "heeeiinnnn", "Gheeeuuuuu", "Haaaaaaaaa",
	"Haaannnnnn", "Huuuuuuuuu", "Maaanngeer", "Faaaiiimmm" };

	std::string name = petits_noms[rand() % 10];
	Zombie *to_return = new Zombie(this->type, name);
	announce(to_return);
	return (to_return);
}

void ZombieEvent::announce(Zombie *zombie)
{
	std::cout << zombie->name << std::endl;
}