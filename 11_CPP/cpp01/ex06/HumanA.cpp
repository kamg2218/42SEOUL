#include "HumanA.hpp"

HumanA::HumanA(const std::string str, Weapon &wp)
	: name(str)
	, wpA(wp)
{
	//pointer
	//wpA(&wp)
}

void	HumanA::attack()
{
	//using reference
	std::cout << name << " attacks with his " << wpA.getType() << std::endl;
	//using pointer
	//std::cout << name << " attacks with his " << wpA->getType() << std::endl;
}
