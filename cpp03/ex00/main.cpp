#include "FragTrap.hpp"

int main(void)
{
	FragTrap f("shoeBox");
	FragTrap g(f);
	f.vaulthunter_dot_exe("test");
	return 0;
}