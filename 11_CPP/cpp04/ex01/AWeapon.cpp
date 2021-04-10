#include "AWeapon.hpp"

AWeapon::AWeapon()
{
	//std::cout << "Clitter-clatter" << std::endl;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
	: m_name(name), m_apcost(apcost), m_damage(damage)
{
	//std::cout << "Clitter-clatter" << std::endl;
}

AWeapon&	AWeapon::operator=(AWeapon const &awp)
{
	m_name = awp.m_name;
	m_apcost = awp.m_apcost;
	m_damage = awp.m_damage;
	return *this;
}

AWeapon::~AWeapon()
{
	//std::cout << "clooooop" << std::endl;
}

int				AWeapon::getAPCost() const { return m_apcost; }
int				AWeapon::getDamage() const { return m_damage; }
std::string		AWeapon::getName() const { return m_name; }
