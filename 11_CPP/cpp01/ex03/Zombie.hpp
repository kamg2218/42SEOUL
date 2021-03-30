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
		void		setName(const std::string str);
		void		setType(const std::string str);
		const std::string	getName();
		const std::string	getType();
};

#endif
