#include "Enemy.hpp"

Enemy::Enemy()
	: m_hp(10), m_type("default")
{
	std::cout << "I'm coming...." << std::endl;
}

Enemy::Enemy(int hp, std::string const &type)
	: m_hp(hp), m_type(type)
{
	std::cout << "I'm coming...." << std::endl;
}

Enemy&		Enemy::operator=(Enemy const &emy)
{
	std::cout << "I'm coming....with..." << std::endl;
	this->m_hp = emy.m_hp;
	this->m_type = emy.m_type;
	return *this;
}

Enemy::~Enemy()
{
	std::cout << "I'm going....bye..." << std::endl;
}

std::string		Enemy::getType() const { return m_type; }
int				Enemy::getHP() const { return m_hp; }
void			Enemy::setHP(int amount) { m_hp = amount; }

void			Enemy::takeDamage(int amount)
{
	if (amount < 0)
	{
		std::cout << m_type << ", Enemy didn't get damage!" << std::endl;
		return ;
	}
	std::cout << m_type << ", Enemy got damage!!" << std::endl;
	m_hp -= amount; 
	if (m_hp < 0)
		m_hp = 0;
}
