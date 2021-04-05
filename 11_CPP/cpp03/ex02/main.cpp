#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <ctime>

int			main(void)
{
	srand(time(0));
	
	std::cout << "--------------------------------" << std::endl;
	FragTrap	ft("claptrap");

	std::cout << "--------------------------------" << std::endl;
	ft.meleeAttack("claptrap");
	ft.takeDamage(10);
	ft.vaulthunter_dot_exe("claptrap");
	ft.beRepaired(10);
	std::cout << "--------------------------------" << std::endl;

	ScavTrap	st("poly");
	std::cout << "--------------------------------" << std::endl;
	
	st.meleeAttack("claptrap");
	st.takeDamage(10);
	st.beRepaired(10);
	st.rangedAttack(ft.getName());
	st.challengeNewcomer(ft);
	std::cout << "--------------------------------" << std::endl;

	return 0;
}
