#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
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
		ClapTrap();
		ClapTrap(std::string const &str);
		ClapTrap&		operator=(ClapTrap const &ct);
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		int				getLevel(void) const;
		std::string		getName(void) const;
		~ClapTrap();
};

#endif
