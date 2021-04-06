#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: Hit_points(100), Max_hit_points(100)
	, Energy_points(100), Max_energy_points(100)
	, Level(1), Melee_attack_damage(30)
	, Ranged_attack_damage(20), Armor_damage_reduction(5)
{
	std::cout << "ClapTrap " << Name << " made!!" << std::endl;
}

ClapTrap::ClapTrap(std::string const &str)
	: Hit_points(100), Max_hit_points(100)
	, Energy_points(100), Max_energy_points(100)
	, Level(1), Melee_attack_damage(30)
	, Ranged_attack_damage(20), Armor_damage_reduction(5)
	, Name(str)
{
	std::cout << "ClapTrap " << Name << " made!!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " died..." << std::endl; 
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &ct)
{
	this->Hit_points = ct.Hit_points;
	this->Max_hit_points = ct.Max_hit_points;
	this->Energy_points = ct.Energy_points;
   	this->Max_energy_points = ct.Max_energy_points;
	this->Level = ct.Level;
	this->Melee_attack_damage = ct.Melee_attack_damage;
	this->Ranged_attack_damage = ct.Ranged_attack_damage;
	this->Armor_damage_reduction = ct.Armor_damage_reduction;
	this->Name = ct.Name;
	return *this;
}

int				ClapTrap::getLevel(void) const { return Level; }
std::string		ClapTrap::getName(void) const { return Name; }

void	ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << Name << " attacks " << target;
	std::cout << " at range, causing " << Ranged_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << Name << " attacks " << target;
	std::cout << " at melee, causing " << Melee_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << Name << " got ";
	std::cout << amount << " damage" << std::endl;
	Hit_points -= amount - Armor_damage_reduction;
	if (Hit_points < 0)
		Hit_points = 0;
	std::cout << "Hit point is " << Hit_points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << amount << " point was repaired" << std::endl;
	Hit_points += amount;
	if (Hit_points > Max_hit_points)
		Hit_points = Max_hit_points;
	Energy_points += amount;
	if (Energy_points > Max_energy_points)
		Energy_points = Max_energy_points;
	std::cout << "Hit point is " << Hit_points << std::endl;
	std::cout << "Energy point is " << Energy_points << std::endl;
}
