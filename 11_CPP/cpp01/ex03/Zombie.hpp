#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	name;
		std::string type;
	public:
		Zombie() {};
		~Zombie() {};
		
		void		announce(void);
		void		setName(std::string str);
		void		setType(std::string str);
		std::string	getName();
		std::string	getType();
};

#endif
