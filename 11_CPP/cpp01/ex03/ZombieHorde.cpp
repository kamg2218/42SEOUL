#include "ZombieHorde.hpp"

int			ZombieHorde::getTypeSize(void) { return 9; }
int			ZombieHorde::getAlphaSize(void) { return alpha_num.size();}

ZombieHorde::ZombieHorde(int n)
{
	num = n;
	zb = new Zombie*[n];
	for (int i = 0; i < n; i++)
	{
		zb[i] = randomChump();
		zb[i]->announce();
	}
}

void		ZombieHorde::clear()
{
	for (int i = 0; i < num; i++)
		delete zb[i];
}

std::string		ZombieHorde::setZombieType(void)
{
	int			len;

	len = rand() % getTypeSize();
	return (type_list[len]);
}

Zombie*			ZombieHorde::newZombie(std::string name)
{
	Zombie*		new_zombie;

	new_zombie = new Zombie;
	new_zombie->setName(name);
	new_zombie->setType(setZombieType());
	return (new_zombie);
}

Zombie*			ZombieHorde::randomChump()
{
	int			len;
	std::string	name;
	Zombie*		new_zombie;

	len = rand() % 10 + 1;
	for (int i = 0; i < len; i++)
		name += alpha_num[rand() % (getAlphaSize() - 1)];
	new_zombie = newZombie(name);
	//new_zombie->announce();
	return (new_zombie);
}
