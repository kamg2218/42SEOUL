#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
	: FragTrap(), NinjaTrap()
{
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 50;
	this->Max_energy_points = 50;
	this->Level = 1;
	this->Melee_attack_damage = 20;
	this->Ranged_attack_damage = 20;
	this->Armor_damage_reduction = 5;
	std::cout << "SuperTrap " << Name << "made!!" << std::endl;
}

SuperTrap::SuperTrap(std::string const &str)
	: FragTrap(str), NinjaTrap(str)
{
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 50;
	this->Max_energy_points = 50;
	this->Level = 1;
	this->Melee_attack_damage = 20;
	this->Ranged_attack_damage = 20;
	this->Armor_damage_reduction = 5;
	this->Name = str;
	std::cout << "SuperTrap " << Name << " made!!" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap " << Name << " died..." << std::endl; 
}

SuperTrap&	SuperTrap::operator=(SuperTrap const &spt)
{
	this->Hit_points = spt.Hit_points;
	this->Max_hit_points = spt.Max_hit_points;
	this->Energy_points = spt.Energy_points;
   	this->Max_energy_points = spt.Max_energy_points;
	this->Level = spt.Level;
	this->Melee_attack_damage = spt.Melee_attack_damage;
	this->Ranged_attack_damage = spt.Ranged_attack_damage;
	this->Armor_damage_reduction = spt.Armor_damage_reduction;
	this->Name = spt.Name;
	return *this;
}

void			SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);	
}

void			SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}
