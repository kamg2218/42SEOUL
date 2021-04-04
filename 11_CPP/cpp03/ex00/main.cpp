#include "FragTrap.hpp"

int			main(void)
{
	FragTrap	ft1;
	FragTrap	ft2("claptrap");

	ft1.rangedAttack("ft2");
	std::cout << "--------------------------------" << std::endl;
	ft2.meleeAttack("claptrap");
	ft2.takeDamage(10);
	ft2.vaulthunter_dot_exe("claptrap");
	ft2.beRepaired(10);
	return 0;
}
