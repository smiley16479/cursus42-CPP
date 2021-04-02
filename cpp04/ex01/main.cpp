#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

/* int main()
{
	// PlasmaRifle p;
	// PowerFist P;
	// std::cout << p.getName();
	// std::cout <<  p._name;
	// AWeapon a;

	return 0;
} */

int main()
{
	Character* moi = new Character("moi");
	std::cout << *moi;
	Enemy* b = new RadScorpion();
	(void)b;
	AWeapon* pr = new PlasmaRifle();
	std::cout << *pr;
	AWeapon* pf = new PowerFist();
	std::cout << *pf;
	moi->equip(pr);
	std::cout << *moi;
	moi->equip(pf);
	moi->attack(b);
	std::cout << *moi;
	moi->equip(pr);
	std::cout << *moi;
	moi->attack(b);
	// std::cout << *moi;
	// moi->attack(b);
	// std::cout << *moi;
	return 0;
}