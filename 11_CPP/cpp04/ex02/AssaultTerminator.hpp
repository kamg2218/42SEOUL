#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class	AssaultTerminator : public ISpaceMarine
{
	private:
		ISpaceMarine*	m_ispm;
	public:
		AssaultTerminator();
		AssaultTerminator(AssaultTerminator const &ast);
		AssaultTerminator&		operator=(AssaultTerminator const &ast);
		~AssaultTerminator();
		virtual	ISpaceMarine*	clone() const;
		virtual	void	battleCry() const;
		virtual	void	rangedAttack() const;
		virtual	void	meleeAttack() const;
};

#endif
