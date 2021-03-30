#include "ZombieEvent.hpp"

int			main(void)
{
	Zombie		*new_zombie;
	ZombieEvent	event;

	srand(time(0));
	std::cout << "Zombie Class" << std::endl;
	new_zombie = new Zombie;
	new_zombie->announce();
	delete new_zombie;

	std::cout << "ZombieEvent Class" << std::endl;
	event.randomChump();
	event.randomChump();
	return (0);
}
