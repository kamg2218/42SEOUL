#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
	: AWeapon("Plasma Rifle", 5, 21), m_name("Plasma Rifle"), m_apcost(5), m_damage(21)
{
	std::cout << "Clitter-rifle" << std::endl;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &prf)
{
	std::cout << "Clitter-rifle" << std::endl;
	*this = prf;
}

PlasmaRifle&	PlasmaRifle::operator=(PlasmaRifle const &prf)
{
	std::cout << "Clitter=rifle" << std::endl;
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

void		PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
