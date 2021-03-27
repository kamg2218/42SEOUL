#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << "<" << name << " (" << type << ")> ";
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::setName(std::string str)
{
	name = str;
}

void	Zombie::setType(std::string str)
{
	type = str;
}

std::string	Zombie::getName() {return name;}

std::string	Zombie::getType() {return type;}
