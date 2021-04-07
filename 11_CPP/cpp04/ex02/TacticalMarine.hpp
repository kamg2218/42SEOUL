#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class	TacticalMarine : public ISpaceMarine
{
	private:
		ISpaceMarine*	m_ispm;
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const &tacm);
		TacticalMarine&		operator=(TacticalMarine const &tacm);
		~TacticalMarine();
		virtual	ISpaceMarine*	clone() const;
		virtual	void	battleCry() const;
		virtual	void	rangedAttack() const;
		virtual	void	meleeAttack() const;
};

#endif
