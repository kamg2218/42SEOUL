#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

class	ZombieHorde
{
	private:
		int				length;
		int				num;
		Zombie			**zb;
		std::string		alpha_num;
		std::string		type_list[10];
	public:
		ZombieHorde()
		{
			alpha_num = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
			type_list[0] = "Regular";
			type_list[1] = "Light";
			type_list[2] = "Heavy";
			type_list[3] = "Psycho";
			type_list[4] = "Venom";
			type_list[5] = "Stamper";
			type_list[6] = "Chaser";
			type_list[7] = "Banshee";
			type_list[8] = "Deimos";
		}
		
		ZombieHorde(int n);
		
		int			getTypeSize();
		int			getAlphaSize();
		void		clear();
		Zombie		*randomChump();
		Zombie		*newZombie(std::string name);
		std::string	setZombieType();

		~ZombieHorde() { delete[] zb; }
};

#endif
