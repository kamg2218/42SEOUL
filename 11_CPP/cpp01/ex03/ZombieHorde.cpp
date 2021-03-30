#include "ZombieHorde.hpp"

int			ZombieHorde::getTypeSize(void) { return 9; }
int			ZombieHorde::getAlphaSize(void) { return alpha_num.size();}
void		ZombieHorde::announce(Zombie &zb) { zb.announce(); }

void		ZombieHorde::initialize()
{
	alpha_num = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	type_list[0] = "Regular";
	type_list[1] = "Light";
	type_list[2] = "Heavy";
	type_list[3] = "Psycho";
	type_list[4] = "Venom";
	type_list[5] = "Stamper";
	type_list[6] = "Chaser";
	type_list[7] = "Banshee";
	type_list[8] = "Deimos";
}

ZombieHorde::ZombieHorde(int n)
{
	initialize();
	num = n;
	zb = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		randomChump(zb[i]);
		announce(zb[i]);
	}
}

const std::string&		ZombieHorde::setZombieType(void)
{
	int			len;

	len = rand() % getTypeSize();
	return (type_list[len]);
}

void			ZombieHorde::randomChump(Zombie &zb)
{
	int			len;
	std::string	name;

	len = rand() % 10 + 1;
	for (int i = 0; i < len; i++)
		name += alpha_num[rand() % (getAlphaSize() - 1)];
	zb.setName(name);
	zb.setType(setZombieType());
}
