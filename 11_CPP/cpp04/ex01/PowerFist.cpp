#include "PowerFist.hpp"

PowerFist::PowerFist()
	: AWeapon("Power Fist", 8, 50)
//	: AWeapon("Power Fist", 8, 50), m_name("Power Fist"), m_apcost(8), m_damage(50)
{
	m_name = "Power Fist";
	m_apcost = 8;
	m_damage = 50;
	std::cout << "Clitter-fist" << std::endl;
}

PowerFist::PowerFist(PowerFist const &pf)
{
	std::cout << "Clitter-fist" << std::endl;
	*this = pf;
}

PowerFist&	PowerFist::operator=(PowerFist const &pf)
{
	std::cout << "Clitter=fist" << std::endl;
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

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
