#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon		*wpB;
	public:
		HumanB() { };
		HumanB(const std::string str);
		HumanB(const std::string str, Weapon &b);
		void		attack();
		void		setWeapon(Weapon &wp);
		~HumanB() { };
};

#endif
