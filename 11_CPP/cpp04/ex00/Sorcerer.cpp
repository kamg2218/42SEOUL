#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
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
}

Sorcerer::~Sorcerer()
{
	std::cout << m_name << ", " << m_title << ", is dead. ";
	std::cout << ""
}
