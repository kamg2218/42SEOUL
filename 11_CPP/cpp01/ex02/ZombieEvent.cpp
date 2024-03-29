#include "ZombieEvent.hpp"

int			ZombieEvent::getTypeSize(void) { return 9; }

int			ZombieEvent::getAlphaSize(void) { return alpha_num.size();}

std::string	ZombieEvent::setZombieType(void)
{
	int			len;

	len = rand() % getTypeSize();
	return (type_list[len]);
}

Zombie*		ZombieEvent::newZombie(std::string name)
{
	Zombie*	new_zombie;

	new_zombie = new Zombie;
	new_zombie->setName(name);
	new_zombie->setType(setZombieType());
	return (new_zombie);
}

//void			ZombieEvent::randomChump(void)
Zombie*			ZombieEvent::randomChump(void)
{
	int			len;
	std::string	name;
	Zombie*		new_zombie;
	//Zombie	new_zombie;

	len = rand() % 10 + 1;
	for (int i = 0; i < len; i++)
		name += alpha_num[rand() % (getAlphaSize() - 1)];
	//스택 메모리 사용하는 경우
	/*
	new_zombie.setName(name);
	new_zombie.setType(setZombieType());
	new_zombie.announce();
	*/
	new_zombie = newZombie(name);
	new_zombie->setType(setZombieType());
	new_zombie->announce();
	return new_zombie;
}
