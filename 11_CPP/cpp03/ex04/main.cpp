#include "SuperTrap.hpp"
#include <ctime>

int			main(void)
{
	srand(time(0));
	
	SuperTrap	spt("SuperChild");
	std::cout << "--------------------------------" << std::endl;
	spt.meleeAttack("FragChild");
	spt.rangedAttack("FragChild");
	std::cout << "--------------------------------" << std::endl;

	return 0;
}
