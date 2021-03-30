// #include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main(void)
{
	ClapTrap c(8);
	FragTrap f("FragTrap");
	ScavTrap s("ScavTrap");
	NinjaTrap n("NinjaTrap");
	f.vaulthunter_dot_exe("innocent cardboard box");
	s.challengeNewcomer();
	n.ninjaShoebox(f);
	n.ninjaShoebox(s);
	n.ninjaShoebox(c);
	n.ninjaShoebox(n);

	return 0;
}