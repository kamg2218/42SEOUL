#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
	: m_name("default"), m_title("default")
{
	std::cout << m_name << ", " << m_title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(std::string name, std::string title)
	: m_name(name), m_title(title)
{
	std::cout << m_name << ", " << m_title << ", is born!" << std::endl;
}

Sorcerer&	Sorcerer::operator=(Sorcerer const &scr)
{
	m_name = scr.m_name;
	m_title = scr.m_title;
	return *this;
}

Sorcerer::~Sorcerer()
{
	std::cout << m_name << ", " << m_title << ", is dead. ";
	std::cout << "Consequences will never be the same!" << std::endl;
}

std::string		Sorcerer::getName() const { return m_name; }
std::string		Sorcerer::getTitle() const { return m_title; }

void			Sorcerer::polymorph(Victim const &vt)
{
	vt.getPolymorphed();
}

std::ostream&	operator<<(std::ostream& os, Sorcerer const &scr)
{
	os << "I am " << scr.getName() << ", " << scr.getTitle();
	os << ", and I like ponies!" << std::endl;
	return os;
}
