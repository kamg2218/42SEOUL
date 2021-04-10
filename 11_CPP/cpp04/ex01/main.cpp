#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int			main(void)
{
	Character *me = new Character("me");

	std::cout << *me;
	
	std::cout << "------------------------" << std::endl;
	
	Enemy *b = new RadScorpion();

	std::cout << "------------------------" << std::endl;
	
	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	std::cout << "------------------------" << std::endl;
	
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	std::cout << "------------------------" << std::endl;
	
	me->attack(b);
	std::cout << *me;
	std::cout << "------------------------" << std::endl;
	me->equip(pr);
	std::cout << *me;
	std::cout << "------------------------" << std::endl;
	me->attack(b);
	std::cout << *me;
	std::cout << "------------------------" << std::endl;
	me->attack(b);
	std::cout << *me;
	
	std::cout << "------------------------" << std::endl;
	Enemy *c = new SuperMutant();
	me->attack(c);
	std::cout << *me;
	std::cout << "------------------------" << std::endl;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	std::cout << "------------------------" << std::endl;
	me->attack(c);
	std::cout << *me;
	me->equip(pf);
	me->attack(c);
	std::cout << *me;
	std::cout << "------------------------" << std::endl;
	
	delete c;
	delete pf;
	delete pr;

	return 0;
}
