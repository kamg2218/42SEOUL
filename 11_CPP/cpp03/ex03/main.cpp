#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <ctime>

int			main(void)
{
	srand(time(0));
	
	ClapTrap	ct("Parent");
	std::cout << "--------------------------------" << std::endl;
	FragTrap	ft("FragChild");

	std::cout << "--------------------------------" << std::endl;
	ft.meleeAttack("Parent");
	ft.takeDamage(10);
	ft.vaulthunter_dot_exe("FragChild");
	ft.beRepaired(10);
	std::cout << "--------------------------------" << std::endl;

	ScavTrap	st("ScavChild");
	std::cout << "--------------------------------" << std::endl;
	
	st.meleeAttack(ft.getName());
	st.takeDamage(10);
	st.beRepaired(10);
	st.rangedAttack(ft.getName());
	st.challengeNewcomer(ft.getName());
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
