#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

class	ZombieEvent
{
	private:
		std::string		alpha_num;
		std::string		type_list[10];
	public:
		int			getTypeSize();
		int			getAlphaSize();
		std::string	setZombieType();
		Zombie		*newZombie(std::string name);
		//void		randomChump(); //스택 영역
		Zombie		*randomChump(); //힙 영역
		
		ZombieEvent()
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
		~ZombieEvent() {}
};

#endif
