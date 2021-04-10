#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int			main()
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	tmp = src->createMateria("ice");
	
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "-----------------------------" << std::endl;
/*
	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "-----------------------------" << std::endl;
*/
/*
	ICharacter* you = new Character("you");
	AMateria*	icy = new Ice();
	AMateria*	cure = new Cure();

	you->equip(icy);
	you->equip(cure);

	you->use(0, *bob);
	you->use(1, *bob);
	
	std::cout << "-----------------------------" << std::endl;
	delete you;
*/	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}
