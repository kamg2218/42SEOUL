#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	Hit_points = 100;
	Max_hit_points = 100;
	Energy_points = 100;
	Max_energy_points = 100;
	Level = 1;
	Melee_attack_damage = 30;
	Ranged_attack_damage = 20;
	Armor_damage_reduction = 5;
	std::cout << "FT4G-TP " << Name << " made!!" << std::endl;
}

FragTrap::FragTrap(std::string const &str)
{
	Hit_points = 100;
	Max_hit_points = 100;
	Energy_points = 100;
	Max_energy_points = 100;
	Level = 1;
	Melee_attack_damage = 30;
	Ranged_attack_damage = 20;
	Armor_damage_reduction = 5;
	Name = str;
	std::cout << "FT4G-TP " << Name << " made!!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP " << Name << " died..." << std::endl; 
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int			num;
	std::string	skill[5] = {"Miniontrap", "Meat unicycle", "Funzerker", "Mechomagician", "Shhhh....trap"};

	num = rand() % 5;
	std::cout << "FR4G-TP " << Name << " attacks " << target;
	std::cout << " with " << skill[num] << std::endl;
	Energy_points -= 15;
	if (Energy_points < 0)
		Energy_points = 0;
	std::cout << "Now, Energy point is " << Energy_points << std::endl;
}
