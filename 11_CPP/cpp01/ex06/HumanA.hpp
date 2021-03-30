#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		//using pointer
		//Weapon	*wpA;
		//using reference
		Weapon		&wpA;
		std::string	name;
	public:
		HumanA(const std::string str, Weapon &a);
		void		attack();
};

#endif
