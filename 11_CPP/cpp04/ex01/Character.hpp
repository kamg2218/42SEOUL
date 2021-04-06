#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>

class	Character
{
	pivate:	
		std::string m_name;
		int			m_apcost;
		int			m_damage;
		AWeapon		*m_awp;
	public:
		Character();
		Character(std::string const &name);
		Character&		operator=(Character const &crt);
		~Character();
		void			recoverAP();
		void			equip(AWeapon *awp);
		void			attack(Enemy *em);
		std::string		getName() const;
};

#endif
