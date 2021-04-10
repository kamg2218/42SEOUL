#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class	AssaultTerminator : public ISpaceMarine
{
	private:
		int		_hp;
	public:
		AssaultTerminator();
		AssaultTerminator(int hp);
		AssaultTerminator&		operator=(AssaultTerminator const &ast);
		~AssaultTerminator();
		virtual	ISpaceMarine*	clone() const;
		virtual	void	battleCry() const;
		virtual	void	rangedAttack() const;
		virtual	void	meleeAttack() const;
};

#endif
