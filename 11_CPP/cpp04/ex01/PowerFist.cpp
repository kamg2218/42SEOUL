#include "PowerFist.hpp"

PowerFist::PowerFist()
	: AWeapon("Power Fist", 8, 50), m_name("Power Fist"), m_apcost(8), m_damage(50)
{
	std::cout << "Clitter-fist" << std::endl;
}

PowerFist::PowerFist(std::string const &name, int apcost, int damage)
	: AWeapon(name, apcost, damage), m_name(name), m_apcost(apcost), m_damage(damage)
{
	std::cout << "Clitter-fist" << std::endl;
}

PowerFist&	PowerFist::operator=(PowerFist const &pf)
{
	m_name = pf.m_name;
	m_apcost = pf.m_apcost;
	m_damage = pf.m_damage;
	return *this;
}

PowerFist::~PowerFist()
{
	std::cout << "clooooop-fist" << std::endl;
}

int				PowerFist::getAPCost() const { return m_apcost; }
int				PowerFist::getDamage() const { return m_damage; }
std::string		PowerFist::getName() const { return m_name; }

virtual void	PowerFist::attack()
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
