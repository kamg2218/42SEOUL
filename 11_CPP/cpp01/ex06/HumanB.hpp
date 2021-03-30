#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon		*wpB;
		std::string	name;
	public:
		HumanB() { };
		HumanB(std::string str);
		HumanB(std::string str, Weapon &b);
		void		attack();
		void		setWeapon(Weapon &wp);
		~HumanB() { };
};

#endif
