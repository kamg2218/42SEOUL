#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

class	ZombieEvent
{
	private:
		std::string		alphanum;
		int				length;
		//std::string	alphanum = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		//int			length = alphanum.size();
	public:
		std::string	setZombieType(void);
		Zombie		*newZombie(std::string name);
		Zombie		*randomChump(void);
};

#endif
