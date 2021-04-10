#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
	: _hp(10)
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(int hp)
	: _hp(hp)
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator&		AssaultTerminator::operator=(AssaultTerminator const &ast)
{
	this->_hp = ast._hp;
	return *this;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
}

ISpaceMarine*	AssaultTerminator::clone() const
{
	ISpaceMarine* tmp;

	tmp = new AssaultTerminator();
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
