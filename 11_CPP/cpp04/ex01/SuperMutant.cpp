#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
	: Enemy(170, "Super Mutant")
{
	m_hp = 170;
	m_type = "Super Mutant";
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &smt)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	*this = smt;
}

SuperMutant&	SuperMutant::operator=(SuperMutant const &smt)
{
	this->m_hp = smt.m_hp;
	this->m_type = smt.m_type;
	return *this;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

std::string		SuperMutant::getType() const { return m_type; }
int				SuperMutant::getHP() const { return m_hp; }

void			SuperMutant::takeDamage(int amount)
{
	Enemy::takeDamage(amount - 3);
}
