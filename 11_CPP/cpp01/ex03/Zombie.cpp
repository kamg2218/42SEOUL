#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << "<" << name << " (" << type << ")> ";
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}
