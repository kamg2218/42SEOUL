#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &ast)
{
	*this = ast;
}

AssaultTerminator&		AssaultTerminator::operator=(AssaultTerminator const &ast)
{
	if (m_ispm)
		delete m_ispm;
	this->m_ispm = ast.clone();
	return *this;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
	if (m_ispm)
		delete m_ispm;
}

ISpaceMarine*	AssaultTerminator::clone() const
{
	ISpaceMarine* tmp;

	tmp = new AssaultTerminator;
	return tmp;
}

void	AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void	AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void	AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}
