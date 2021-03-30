// #include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	SuperTrap S1("superTrap1");
	SuperTrap S2(S1);
	SuperTrap S3(10);


	// S1.rangedAttack(S1._name);
	// S1.vaulthunter_dot_exe(S1._name);

	// Others inherited method :

	ScavTrap s1("ScavTrap");
	ScavTrap s2(s1);


	NinjaTrap n("ninja");
	// S1.ninjaShoebox(n);
	S1.meleeAttack(n._name);
	S1.rangedAttack(n._name);
	// S1.hammerAttack(n._name);

	std::cout << S1 << std::endl;

	return 0;
}