#include "Victim.hpp"
#include "Peon.hpp"
#include "Pony.hpp"
#include "Sorcerer.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Pony cheval("Pony");

	std::cout << robert << jim << joe << cheval;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(cheval);
	return 0;
}