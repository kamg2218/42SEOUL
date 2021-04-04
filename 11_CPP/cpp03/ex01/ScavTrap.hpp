#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "FragTrap.hpp"

class	ScavTrap
{
	private:
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
		ScavTrap();
		ScavTrap(std::string const &str);
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		int				getLevel(void) const;
		void			challengeNewcomer(FragTrap& ft);
		~ScavTrap();
};
/*
class	ScavTrap : public FragTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string const &str);
		void			challengeNewcomer(FragTrap& ft);
		~ScavTrap();
};
*/
#endif
