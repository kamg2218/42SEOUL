#include "Laborer.hpp"

Laborer::Laborer()
	: Victim(), m_name("default")
{
	std::cout << "Zog zog zog." << std::endl;
}

Laborer::Laborer(std::string name)
	: Victim(name), m_name(name)
{
	std::cout << "Zog zog zog." << std::endl;
}

Laborer&	Laborer::operator=(Laborer const &lb)
{
	m_name = lb.m_name;
	return *this;
}

Laborer::~Laborer()
{
	std::cout << "Labor..." << std::endl;
}

void	Laborer::introduce()
{
	std::cout << "I am " << m_name;
	std::cout << " and I like blue pony!" << std::endl;
}

std::string		Laborer::getName() const { return m_name; }

void			Laborer::getPolymorphed() const
{
	std::cout << m_name << " has been turned into a blue pony!" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, Laborer const &lb)
{
	os << "I am " << lb.getName();
	os << " and I like otters!" << std::endl;
	return os;
}
