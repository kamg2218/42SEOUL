#include "FragTrap.hpp"

int			main(void)
{
	FragTrap	ft1;
	std::cout << "--------------------------------" << std::endl;
	FragTrap	ft2("Newtrap");
	std::cout << "--------------------------------" << std::endl;

	srand(clock());
	ft1.rangedAttack("ft2");
	std::cout << "--------------------------------" << std::endl;
	ft2.meleeAttack("f1");
	ft2.takeDamage(10);
	ft2.beRepaired(10);
	ft2.vaulthunter_dot_exe("f1");
	ft2.beRepaired(10);
	ft2.vaulthunter_dot_exe("f1");
	ft2.vaulthunter_dot_exe("f1");
	ft2.vaulthunter_dot_exe("f1");
	ft2.vaulthunter_dot_exe("f1");
	ft2.vaulthunter_dot_exe("f1");
	ft2.vaulthunter_dot_exe("f1");
	std::cout << "--------------------------------" << std::endl;
	return 0;
}
