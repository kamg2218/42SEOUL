#include "Character.hpp"

Character::Character()
	: m_name("default"), m_apcost(40), m_max_apcost(40), m_awp(0)
{
	std::cout << m_name << " made.." << std::endl;
}

Character::Character(std::string const &str)
	: m_name(str), m_apcost(40), m_max_apcost(40), m_awp(0)
{
	std::cout << m_name << " made.." << std::endl;
}

Character&		Character::operator=(Character const &crt)
{
	this->m_name = crt.m_name;
	this->m_apcost = crt.m_apcost;
	std::cout << m_name << " made.." << std::endl;
	return *this;
}

Character::~Character()
{
	std::cout << m_name << " is dead..." << std::endl;
}

void	Character::recoverAP()
{
	std::cout << "recovering APcost..." << std::endl;
	m_apcost += 10;
	if (m_apcost > m_max_apcost)
		m_apcost = m_max_apcost;
}
void	Character::equip(AWeapon *awp)
{
	std::cout << m_name << " have a weapon, now!" << std::endl;
	m_awp = awp;
}
void	Character::attack(Enemy *enm)
{
	if (m_awp == NULL)
	{
		std::cout << m_name << " doesn't have equipped weapon!!" << std::endl;
		return ;
	}
	else if (enm == NULL)
	{
		std::cout << "Enemy is already died..." << std::endl;
		return ;
	}
	else if (m_apcost < m_awp->getAPCost())
	{
		std::cout << "Not enough apcost.." << std::endl;
		return ;
	}
	std::cout << m_name << " attacks " << enm->getType() << " with a ";
	std::cout << m_awp->getName() << std::endl;
	m_awp->attack();
	m_apcost -= m_awp->getAPCost();
	enm->setHP(enm->getHP() - m_awp->getDamage());
	if (enm->getHP() <= 0 && enm)
	{
		std::cout << enm->getType() << " died!!" << std::endl;
		delete enm;
		enm = NULL;
	}
}

std::ostream&	operator<<(std::ostream &os, Character const &crt)
{
	os << crt.getName() << " has " << crt.getAPCost() << " AP and ";
	if (crt.isAWP())
		os << "wields a " << crt.getWeaponName() << std::endl;
	else
		os << "is unarmed" << std::endl;
	return os;
}

std::string	Character::getName() const { return m_name; }

std::string	Character::getWeaponName() const
{
	if (m_awp)
		return m_awp->getName();
	return "NULL";
}

int			Character::getAPCost() const { return m_apcost; }

bool		Character::isAWP() const
{
	if (m_awp)
		return true;
	return false;
}
