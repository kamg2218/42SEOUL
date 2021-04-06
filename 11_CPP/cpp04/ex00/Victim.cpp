#include "Victim.hpp"

Victim::Victim()
{
	std::cout << "Some random victim called " << m_name;
	std::cout << " just appeared!" << std::endl;
}

Victim::Victim(std::string name)
	: m_name(name)
{
	std::cout << "Some random victim called " << m_name;
	std::cout << " just appeared!" << std::endl;
}

Victim&	Victim::operator=(Victim const &vt)
{
	m_name = vt.m_name;
	return *this;
}

Victim::~Victim()
{
	std::cout << "Victim " << m_name << " just died for no apparent reason!" << std::endl;
}

void	Victim::introduce()
{
	std::cout << "I am " << m_name;
	std::cout << " and I like otters!" << std::endl;
}

std::string		Victim::getName() const { return m_name; }

void			Victim::getPolymorphed() const
{
	std::cout << m_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, Victim const &vt)
{
	os << "I am " << vt.getName();
	os << " and I like otters!" << std::endl;
	return os;
}
