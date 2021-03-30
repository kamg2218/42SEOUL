#include "HumanB.hpp"

HumanB::HumanB(const std::string str)
	: name(str)
{
}

HumanB::HumanB(const std::string str, Weapon &wp)
	: name(str)
	, wpB(&wp)
{
}

void	HumanB::attack()
{
	std::cout << name << " attacks with his " << wpB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &wp)
{
	wpB = &wp;
}
