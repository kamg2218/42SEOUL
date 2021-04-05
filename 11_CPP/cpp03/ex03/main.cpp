#include "NinjaTrap.hpp"
#include <ctime>

int			main(void)
{
	srand(time(0));
	
	ClapTrap	ct("Parent");
	std::cout << "--------------------------------" << std::endl;
	
	FragTrap	ft("FragChild");
	std::cout << "--------------------------------" << std::endl;

	ScavTrap	st("ScavChild");
	std::cout << "--------------------------------" << std::endl;

	NinjaTrap	nt("NinjaChild");
	std::cout << "--------------------------------" << std::endl;
	nt.meleeAttack(ft.getName());
	nt.takeDamage(10);
	nt.beRepaired(10);
	nt.rangedAttack(ft.getName());
	std::cout << "--------------------------------" << std::endl;

	nt.ninjaShoebox(nt);
	std::cout << "--------------------------------" << std::endl;
	nt.ninjaShoebox(ft);
	std::cout << "--------------------------------" << std::endl;
	nt.ninjaShoebox(st);
	std::cout << "--------------------------------" << std::endl;
	nt.ninjaShoebox(ct);
	std::cout << "--------------------------------" << std::endl;

	return 0;
}
