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

ScavTrap&	ScavTrap::operator=(ScavTrap const &st)
{
	this->Hit_points = st.Hit_points;
	this->Max_hit_points = st.Max_hit_points;
	this->Energy_points = st.Energy_points;
   	this->Max_energy_points = st.Max_energy_points;
	this->Level = st.Level;
	this->Melee_attack_damage = st.Melee_attack_damage;
	this->Ranged_attack_damage = st.Ranged_attack_damage;
	this->Armor_damage_reduction = st.Armor_damage_reduction;
	this->Name = st.Name;
	return *this;
}

void	ScavTrap::challengeNewcomer(FragTrap const &ft)
{
	int			num;
	std::string	challenge[5] = {"Typone Jornal", "Target of opportunity", "Legendary Hunt", "Typone Tangent", "Crimson Radio"};

	num = rand() % 5;
	std::cout << "FR4G-TP " << ft.getName() << " starts new challenge, ";
	std::cout << challenge[num] << std::endl;
}

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "ScavTrap " << Name << " attacked " << target;
	std::cout << " at range, causing " << Ranged_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "ScavTrap " << Name << " attacked " << target;
	std::cout << " at melee, causing " << Melee_attack_damage;
	std::cout << " points of damage!" << std::endl;
}
