#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap f("shoeBox");
	FragTrap g("BeatBox");

	g.takeDamage(f.vaulthunter_dot_exe(g._name));
	std::cout << g._name << " has now : " << g.getHealth() << " of Energy\n";
	std::cout << "and ...\n";
	std::cout << f._name << " has now : " << f.getHealth() << " of Energy\n";

	f.takeDamage(g.vaulthunter_dot_exe(f._name));
	std::cout << f._name << " has now : " << f.getHealth() << " of Energy\n";
	f.beRepaired(1000);
	std::cout << f._name << " has now : " << f.getHealth() << " of Energy\n";

	ScavTrap h("Scavicon");
	h.challengeNewcomer();

	return 0;
}