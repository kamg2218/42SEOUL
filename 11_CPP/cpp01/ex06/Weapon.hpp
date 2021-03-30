#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	private:
		std::string			type;
	public:
		Weapon() { };
		Weapon(std::string str);
		void				setType(std::string type);
		std::string			getType();
		//Weapon& 			operator=(const Weapon &wp);
		~Weapon() { };
};

#endif
