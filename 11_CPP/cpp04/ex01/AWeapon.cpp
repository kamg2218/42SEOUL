#include "AWeapon.hpp"

AWeapon::AWeapon()
	: m_name("default"), m_apcost(0), m_damage(0)
{
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
	: m_name(name), m_apcost(apcost), m_damage(damage)
{
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
}

int				AWeapon::getAPCost() const { return m_apcost; }
int				AWeapon::getDamage() const { return m_damage; }
std::string		AWeapon::getName() const { return m_name; }
