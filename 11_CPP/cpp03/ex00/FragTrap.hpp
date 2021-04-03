#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>

class	FragTrap
{
	private:
		int				Hit_points;
		int				Max_hit_points;
		int				Energy_points;
		int				Max_energy_points;
		int				Level;
		std::string		Name;
		int				Melee_attack_damage;
		int				Ranged_attack_damage;
		int				Armor_damage_reduction;
	public:
		FragTrap();
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			vaulthunter_dot_exe(std::string const &target);
		~FragTrap() { };
};

#endif
