#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
	: FragTrap(), NinjaTrap()
{
	FragTrap::Hit_points = 100;
	FragTrap::Max_hit_points = 100;
	NinjaTrap::Energy_points = 100;
	NinjaTrap::Max_energy_points = 100;
	Level = 1;
	Melee_attack_damage = 30;
	Ranged_attack_damage = 20;
	Armor_damage_reduction = 5;
	std::cout << "SuperTrap " << FragTrap::Name << " made!!" << std::endl;
}

SuperTrap::SuperTrap(std::string const &str)
	: FragTrap(str), NinjaTrap(str)
{
	/*
	Hit_points = 100;
	Max_hit_points = 100;
	Energy_points = 100;
	Max_energy_points = 100;
	Level = 1;
	Melee_attack_damage = 30;
	Ranged_attack_damage = 20;
	Armor_damage_reduction = 5;
	Name = str;
	*/
	std::cout << "SuperTrap " << FragTrap::Name << " made!!" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap " << FragTrap::Name << " died..." << std::endl; 
}
