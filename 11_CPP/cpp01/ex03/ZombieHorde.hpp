#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

class	ZombieHorde
{
	private:
		std::string		alphanum;
		int				length;
		int				num;
		Zombie			*zb;
	public:
		ZombieHorde (int n)
		{
			num = n;
			zb = new Zombie[n];
		}
		
		std::string	setZombieType(void);
		void		randomChump(void);

		~ZombieHorde()
		{
			delete[] zb;
		}
};

#endif
