#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon		wpA;
		std::string	name;
	public:
		HumanA();
		HumanA(std::string str, Weapon &a);
		void		attack();
		~HumanA();
};

#endif
