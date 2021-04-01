#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		//using pointer
		//Weapon	*wpA;
		//using reference
		std::string	name;
		Weapon		&wpA;
	public:
		HumanA(const std::string str, Weapon &a);
		void		attack();
};

#endif
