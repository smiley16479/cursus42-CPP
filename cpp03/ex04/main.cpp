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
	S1.vaulthunter_dot_exe(S1._name);
	
	NinjaTrap n("ninja");
	S1.ninjaShoebox(n);

	return 0;
}