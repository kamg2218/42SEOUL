#include "ZombieHorde.hpp"

int			main(void)
{
	srand(time(0));
	
	std::cout << "a" << std::endl;
	ZombieHorde		a;

	std::cout << "b" << std::endl;
	ZombieHorde		b(1);

	std::cout << "c" << std::endl;
	ZombieHorde 	c(3);
	
	std::cout << "d" << std::endl;
	ZombieHorde		d = ZombieHorde(2);

	return (0);
}
