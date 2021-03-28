#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	private:
		std::string			type;
	public:
		void				setType(const std::string type);
		const std::string	&getType();
};

#endif
