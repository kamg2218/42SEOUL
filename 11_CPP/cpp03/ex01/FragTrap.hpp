#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>

class	FragTrap
{
	protected:
		int				Hit_points;
		int				Max_hit_points;
		int				Energy_points;
		int				Max_energy_points;
		int				Level;
		int				Melee_attack_damage;
		int				Ranged_attack_damage;
		int				Armor_damage_reduction;
		std::string		Name;
	public:
		FragTrap();
		FragTrap(std::string const &str);
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			vaulthunter_dot_exe(std::string const &target);
		int				getLevel(void) const;
		std::string		getName(void) const;
		~FragTrap();
};

#endif
