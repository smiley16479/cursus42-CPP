#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : _nb(n)
{
	std::cout << "ZombieHorde constructor called" << std::endl;
	srand (time(NULL));
	this->_horde = new Zombie[n];
	for (int i = 0; i < n; ++i)
		randomChump(&this->_horde[i]);
	return;
}

ZombieHorde::~ZombieHorde( void )
{
	std::cout << "ZombieHorde destructor called" << std::endl;
	delete [] this->_horde;
	return ;
}

void ZombieHorde::randomChump(Zombie *to_return)
{
	std::array<std::string, 10> petits_noms = {"Arrrggghhh", "Heeeeuuuu",
	"Agnagnagna", "heeeiinnnn", "Gheeeuuuuu", "Haaaaaaaaa",
	"Haaannnnnn", "Huuuuuuuuu", "Maaanngeer", "Faaaiiimmm" };

	to_return->_name = petits_noms[rand() % 10];
}

void ZombieHorde::announce(void)
{
	for (int i = 0; i < this->_nb; ++i)
		this->_horde[i].announce();
}