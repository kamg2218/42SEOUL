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
	//스택 메모리 사용하는 경우
	//event.randomChump();
	//event.randomChump();
	
	new_zombie = event.randomChump();
	delete new_zombie;
	new_zombie = event.randomChump();
	delete new_zombie;
	
	return (0);
}
