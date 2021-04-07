#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include <string>

class	Enemy
{
	protected:
		int			m_hp;
		std::string m_type;
	public:
		Enemy();
		Enemy(int hp, std::string const &type);
		Enemy&			operator=(Enemy const &emy);
		virtual ~Enemy();
		std::string		getType() const;
		int				getHP() const;
		void			setHP(int amount);
		virtual void	takeDamage(int amount);
};

#endif
