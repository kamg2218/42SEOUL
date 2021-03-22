#include "ZombieHorde.hpp"

std::string	ZombieHorde::setZombieType(void)
{
	std::string	str;
	int			len;

	len = rand() % 10 + 1;
	for (int i = 0; i < len; i++)
		str += alphanum[rand() % (length - 1)];
	return (str);
}

void			ZombieHorde::randomChump(void)
{
	std::string	name;

	alphanum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	length = alphanum.size();
	for (int i = 0; i < num; i++)
	{
		zb[i].name = "zombie" + std::to_string(rand() % 9 + 1) + std::to_string(rand() % 10);
		zb[i].type = setZombieType();
		zb[i].announce();
	}
}

int			main(void)
{
	ZombieHorde	horde(10);

	srand(time(0));
	horde.randomChump();
	return (0);
}
