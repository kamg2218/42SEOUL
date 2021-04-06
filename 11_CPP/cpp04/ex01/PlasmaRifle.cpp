#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
	: AWeapon("Plasma Rifle", 5, 21), m_name("Plasma Rifle"), m_apcost(5), m_damage(21)
{
	std::cout << "Clitter-rifle" << std::endl;
}

PlasmaRifle::PlasmaRifle(std::string const &name, int apcost, int damage)
	: AWeapon(name, apcost, damage), m_name(name), m_apcost(apcost), m_damage(damage)
{
	std::cout << "Clitter-rifle" << std::endl;
}

PlasmaRifle&	PlasmaRifle::operator=(PlasmaRifle const &prf)
{
	m_name = prf.m_name;
	m_apcost = prf.m_apcost;
	m_damage = prf.m_damage;
	return *this;
}

PlasmaRifle::~PlasmaRifle()
{
	std::cout << "clooooop-rifle" << std::endl;
}

int				PlasmaRifle::getAPCost() const { return m_apcost; }
int				PlasmaRifle::getDamage() const { return m_damage; }
std::string		PlasmaRifle::getName() const { return m_name; }

virtual void	PlasmaRifle::attack()
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
