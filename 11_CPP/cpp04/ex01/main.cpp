#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"

int			main(void)
{
	//AWeapon wp("new_weapon", 10, 10);

	std::cout << "------------------------" << std::endl;
	PlasmaRifle prf;
	prf.attack();
	std::cout << "------------------------" << std::endl;
	PowerFist	pf;
	pf.attack();
	std::cout << "------------------------" << std::endl;
	return 0;
}
