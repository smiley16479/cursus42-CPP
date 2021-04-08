#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int test_sup(ISquad* vlc)
{
	ISpaceMarine* bobbyFisher = new TacticalMarine(42);
	ISpaceMarine* kasparov = bobbyFisher->clone();

	std::cout << ((TacticalMarine*)bobbyFisher)->getNb() << std::endl;
	std::cout << ((TacticalMarine*)kasparov)->getNb() << std::endl;

	ISquad* vlc_1 = new Squad;

	std::cout << "vlc squad has " << vlc->getCount() << " Marine(s)" << std::endl;
	vlc->getUnit(1)->battleCry(); // Appel de battleCry() de l'unité #2 (AssaultTerminator)
	std::cout << "vlc_1 squad has " << vlc_1->getCount() << " Marine(s)" << std::endl;
	vlc_1->push(bobbyFisher);
	std::cout << "vlc_1 squad has " << vlc_1->getCount() << " Marine(s)" << std::endl;
	vlc_1->push(kasparov);
	std::cout << "vlc_1 squad has " << vlc_1->getCount() << " Marine(s)" << std::endl;
	*(Squad*)vlc_1 = *(Squad*)vlc;
	std::cout << "vlc_1 squad has " << vlc_1->getCount() << " Marine(s)" << std::endl;
	delete vlc_1;
	return 0;
}

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* totor = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	vlc->push(totor);
	std::cout << "vlc->getCount() : " << vlc->getCount() << std::endl;
	for (int i = 0; i < vlc->getCount(); ++i) {
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << std::endl << "\033[1m\033[32mOther_tests\033[0m" << std::endl;
	test_sup(vlc);
	std::cout << std::endl << "\033[1m\033[32mBack_in_Main()\033[0m" << std::endl;
	delete vlc;

	return 0;
}

/* int main()
{
	TacticalMarine a;
	std::cout << a;
} */