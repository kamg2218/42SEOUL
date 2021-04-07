#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
	: Enemy(80, "RadScorpion"), m_hp(80), m_type("RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &rsp)
{
	std::cout << "* click click click *" << std::endl;
	*this = rsp;
}

RadScorpion&	RadScorpion::operator=(RadScorpion const &rsp)
{
	this->m_hp = rsp.m_hp;
	this->m_type = rsp.m_type;
	return *this;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

std::string		RadScorpion::getType() const { return m_type; }
int				RadScorpion::getHP() const { return m_hp; }
