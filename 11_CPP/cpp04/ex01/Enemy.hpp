#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include <string>

class	Enemy
{
	pivate:
		int			m_hp;
		int			m_apcost;
		int			m_damage;
		std::string m_type;
	public:
		Enemy();
		Enemy(int hp, std::string const &type);
		Enemy&			operator=(Enemy const &emy);
		~Enemy();
		std::string		getType() const;
		int				getHP() const;
		virtual void	takeDamage(int);
};

#endif
