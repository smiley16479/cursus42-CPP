// #include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	SuperTrap S1("superTrap1");
	SuperTrap S2(S1);


	S1.rangedAttack(S1._name);

	return 0;
}