#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: Hit_points(100), Max_hit_points(100)
	, Energy_points(50), Max_energy_points(50)
	, Level(1), Melee_attack_damage(20)
	, Ranged_attack_damage(15), Armor_damage_reduction(3)
{
	std::cout << "Gatekeeper " << Name << " made!!" << std::endl;
}

ScavTrap::ScavTrap(std::string const &str)
	: Hit_points(100), Max_hit_points(100)
	, Energy_points(50), Max_energy_points(50)
	, Level(1), Melee_attack_damage(20)
	, Ranged_attack_damage(15), Armor_damage_reduction(3)
	, Name(str)
{
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

int		ScavTrap::getLevel(void) const { return Level; }

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "Gatekeeper " << Name << " attacked " << target;
	std::cout << " at range, causing " << Ranged_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "Gatekeeper " << Name << " attacked " << target;
	std::cout << " at melee, causing " << Melee_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "Gatekeeper " << Name << " got ";
	std::cout << amount << " damage" << std::endl;
	Hit_points -= amount - Armor_damage_reduction;
	if (Hit_points < 0)
		Hit_points = 0;
	std::cout << "Hit point is " << Hit_points << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
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

void	ScavTrap::challengeNewcomer(FragTrap const &ft)
{
	int			num;
	std::string	challenge[5] = {"Typone Jornal", "Target of opportunity", "Legendary Hunt", "Typone Tangent", "Crimson Radio"};

	num = rand() % 5;
	std::cout << "FR4G-TP " << ft.getName() << " starts new challenge, ";
	std::cout << challenge[num] << std::endl;
}
