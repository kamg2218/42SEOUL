#include "ZombieEvent.hpp"

std::string	ZombieEvent::setZombieType(void)
{
	std::string	str;
	int			len;

	len = rand() % 10 + 1;
	for (int i = 0; i < len; i++)
		str += alphanum[rand() % (length - 1)];
	return (str);
}

Zombie*		ZombieEvent::newZombie(std::string name)
{
	Zombie*	new_zombie;

	new_zombie = new Zombie;
	new_zombie->name = name;
	new_zombie->type = setZombieType();
	return (new_zombie);
}

Zombie*		ZombieEvent::randomChump(void)
{
	std::string	name;
	Zombie*		new_zombie;

	alphanum = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	length = alphanum.size();
	name = "zombie" + std::to_string(rand() % 10);
	new_zombie = newZombie(name);
	new_zombie->announce();
	return (new_zombie);
}

int			main(void)
{
	Zombie		*new_zombie;
	ZombieEvent	event;

	srand(time(0));
	new_zombie = event.randomChump();
	delete new_zombie;
	return (0);
}
