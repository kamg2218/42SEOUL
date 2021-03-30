#include "Weapon.hpp"

Weapon::Weapon(const std::string str)
	: type(str)
{
}

void					Weapon::setType(const std::string str)
{
	type = str;
}

const std::string&		Weapon::getType()
{
	return type;
}
