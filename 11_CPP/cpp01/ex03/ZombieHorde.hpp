#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

class	ZombieHorde
{
	private:
		int				num;
		Zombie			*zb;
		std::string		alpha_num;
		std::string		type_list[10];
	public:
		ZombieHorde() {initialize();};
		ZombieHorde(int n);
		
		int			getTypeSize();
		int			getAlphaSize();
		void		initialize();
		void		announce(Zombie &zb);
		void		randomChump(Zombie &zb);
		const std::string	setZombieType();

		~ZombieHorde() { delete[] zb;}
};

#endif
