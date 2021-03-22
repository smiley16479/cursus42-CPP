#include "Pony.hpp"

void ponyOnTheStack(void)
{
	Pony	pony(180, "blue", "bleuet");
	++Pony::_instance_nb;
	std::cout << std::right << "Instance allouée : " << Pony::_instance_nb << std::endl;
	pony.trote();
	pony.galop();
	--Pony::_instance_nb;
	std::cout << std::right << "Instance désallouée au return: " << Pony::_instance_nb << std::endl;
	return;
}


void ponyOnTheHeap(void)
{
	Pony	*pony_ptr = new Pony(220, "vert", "goliat");
	++Pony::_instance_nb;
	std::cout << std::right << "Instance allouée : " << Pony::_instance_nb << std::endl;
	pony_ptr->trote();
	pony_ptr->galop();
	delete pony_ptr;
	--Pony::_instance_nb;
	std::cout << std::right << "Instance désallouée au return: " << Pony::_instance_nb << std::endl;
	return;
}

int Pony::_instance_nb = 0;

int main()
{
	std::cout << std::right << "Instance allouée au début du main : " << Pony::_instance_nb << std::endl;
	ponyOnTheStack();
	ponyOnTheHeap();
	std::cout << std::right << "Instance allouée à la fin du main : " << Pony::_instance_nb << std::endl;
	return(0);
}