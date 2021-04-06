#include "Peon.hpp"

Peon::Peon()
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name)
	: Victim(name), m_name(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon&	Peon::operator=(Peon const &pn)
{
	m_name = pn.m_name;
	return *this;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void	Peon::introduce()
{
	std::cout << "I am " << m_name;
	std::cout << " and I like pink pony!" << std::endl;
}

std::string		Peon::getName() const { return m_name; }

void			Peon::getPolymorphed() const
{
	std::cout << m_name << " has been turned into a pink pony!" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, Peon const &pn)
{
	os << "I am " << pn.getName();
	os << " and I like otters!" << std::endl;
	return os;
}
