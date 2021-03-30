#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << "<" << name << " (" << type << ")> ";
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::setName(const std::string str)
{
	name = str;
}

void	Zombie::setType(const std::string str)
{
	type = str;
}

const std::string	Zombie::getName() {return name;}

const std::string	Zombie::getType() {return type;}
