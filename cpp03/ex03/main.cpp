// #include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap c(8);
	FragTrap t("hello");
	FragTrap f("shoeBox");
	f.vaulthunter_dot_exe("innocent cardboard box");
	ScavTrap s("BeatBox");
	s.challengeNewcomer();

	return 0;
}