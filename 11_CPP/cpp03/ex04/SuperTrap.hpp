#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "NinjaTrap.hpp"

class	SuperTrap : virtual public FragTrap, virtual public NinjaTrap
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
		SuperTrap();
		SuperTrap(std::string const &str);
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		~SuperTrap();
};

#endif
