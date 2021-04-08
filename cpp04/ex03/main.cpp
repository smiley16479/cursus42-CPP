#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int test_sup(IMateriaSource* src, ICharacter* moi)
{
	((Character*)moi)->getType();

	std::cout << *((MateriaSource*)src)->invokeMateria(0);
	std::cout << *((MateriaSource*)src)->invokeMateria(1);
	std::cout << std::endl << "\033[1m\033[32mBack in : test_sujet()\033[0m" << std::endl;
	return 0;
}

int test_sujet()
{
	Ice* ice = new Ice();
	Cure* cure = new Cure();
	IMateriaSource* src = new MateriaSource();
/* 	src->learnMateria(new Ice());
	src->learnMateria(new Cure()); */
	src->learnMateria(ice);
	src->learnMateria(cure);
	ICharacter* moi = new Character("moi");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	moi->equip(tmp);
	tmp = src->createMateria("cure");
	moi->equip(tmp);
	ICharacter* bob = new Character("bob");
	moi->use(0, *bob);
	moi->use(1, *bob);

	std::cout << *tmp << std::endl;
	// moi->unequip(1);
	// moi->use(1, *bob);

	std::cout << std::endl << "\033[1m\033[32mOther_tests\033[0m" << std::endl;
	test_sup(src, moi);

	// delete tmp;
	delete bob;
	delete moi;
	delete src;
	//Pour éviter les leeks dû à la copie spécifier ds le sujet de la matéria (learnMateria)
	delete ice;
	delete cure;
	return 0;
}


int main()
{
	test_sujet();

	return 0;
}