#include "ZombieHorde.hpp"

int			main(void)
{
	ZombieHorde		**horde;

	srand(time(0));
	horde = new ZombieHorde*[3];
	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 2 << std::endl;
		horde[i] = new ZombieHorde(i + 2);
	}
	for (int i = 0; i < 3; i++)
		delete horde[i];
	delete horde;
	return (0);
}
