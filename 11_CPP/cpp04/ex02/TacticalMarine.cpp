#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
	: _hp(10)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(int	hp)
	: _hp(hp)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine&		TacticalMarine::operator=(TacticalMarine const &tacm)
{
	this->_hp = tacm._hp;
	return *this;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

ISpaceMarine*	TacticalMarine::clone() const
{
	ISpaceMarine	*tmp;

	tmp = new TacticalMarine;
	return tmp;
}

void	TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void	TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}
