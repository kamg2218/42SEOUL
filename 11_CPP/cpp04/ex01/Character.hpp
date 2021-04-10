#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class	Character
{
	private:	
		std::string m_name;
		int			m_apcost;
		int			m_max_apcost;
		AWeapon		*m_awp;
		Character();
	public:
		Character(std::string const &name);
		Character&		operator=(Character const &crt);
		~Character();
		void			recoverAP();
		void			equip(AWeapon *awp);
		void			attack(Enemy *em);
		std::string		getName() const;
		std::string		getWeaponName() const;
		int				getAPCost() const;
		bool			isAWP() const;
};

std::ostream&	operator<<(std::ostream& os, Character const &crt);

#endif
