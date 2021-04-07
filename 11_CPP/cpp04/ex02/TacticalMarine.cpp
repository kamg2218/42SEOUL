#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
	: m_ispm(0)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &tacm)
{
	*this = tacm;
}

TacticalMarine&		TacticalMarine::operator=(TacticalMarine const &tacm)
{
	if (m_ispm)
		delete m_ispm;
	this->m_ispm = tacm.clone();
	return *this;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
	if (m_ispm)
		delete m_ispm;
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
