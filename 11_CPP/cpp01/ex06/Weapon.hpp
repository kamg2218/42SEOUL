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
		Weapon(const std::string str);
		void					setType(const std::string type);
		const std::string&		getType();
		~Weapon() { };
};

#endif
