#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	Hit_points = 100;
	Max_hit_points = 100;
	Energy_points = 50;
	Max_energy_points = 50;
	Level = 1;
	Melee_attack_damage = 20;
	Ranged_attack_damage = 15;
	Armor_damage_reduction = 3;
	std::cout << "Gatekeeper " << Name << " made!!" << std::endl;
}

ScavTrap::ScavTrap(std::string const &str)
{
	Hit_points = 100;
	Max_hit_points = 100;
	Energy_points = 50;
	Max_energy_points = 50;
	Level = 1;
	Melee_attack_damage = 20;
	Ranged_attack_damage = 15;
	Armor_damage_reduction = 3;
	Name = str;
	std::cout << "Gatekeeper " << Name << " made!!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Gatekeeper " << Name << " opened the door!" << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const &ft)
{
	int			num;
	std::string	challenge[5] = {"Typone Jornal", "Target of opportunity", "Legendary Hunt", "Typone Tangent", "Crimson Radio"};

	num = rand() % 5;
	std::cout << "FR4G-TP " << ft << " starts new challenge, ";
	std::cout << challenge[num] << std::endl;
}
