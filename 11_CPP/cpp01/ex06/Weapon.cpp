#include "Weapon.hpp"

Weapon::Weapon(std::string str)
	: type(str)
{
	//setType(type);
}

/*
Weapon&			Weapon::operator=(const Weapon &wp)
{
	type = wp.type;
	return *this;
}
*/

void			Weapon::setType(std::string str)
{
	type = str;
}

std::string		Weapon::getType()
{
	return type;
}
