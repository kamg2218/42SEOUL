#include "FragTrap.hpp"

FragTrap::FragTrap()
	: Hit_points(100), Max_hit_points(100)
	, Energy_points(100), Max_energy_points(100)
	, Level(1), Melee_attack_damage(30)
	, Ranged_attack_damage(20), Armor_damage_reduction(5)
{
	std::cout << "FT4G-TP " << Name << " made!!" << std::endl;
}

FragTrap::FragTrap(std::string const &str)
	: Hit_points(100), Max_hit_points(100)
	, Energy_points(100), Max_energy_points(100)
	, Level(1), Melee_attack_damage(30)
	, Ranged_attack_damage(20), Armor_damage_reduction(5)
	, Name(str)
{
	std::cout << "FT4G-TP " << Name << " made!!" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const &ft)
{
	this->Hit_points = ft.Hit_points;
	this->Max_hit_points = ft.Max_hit_points;
	this->Energy_points = ft.Energy_points;
   	this->Max_energy_points = ft.Max_energy_points;
	this->Level = ft.Level;
	this->Melee_attack_damage = ft.Melee_attack_damage;
	this->Ranged_attack_damage = ft.Ranged_attack_damage;
	this->Armor_damage_reduction = ft.Armor_damage_reduction;
	this->Name = ft.Name;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP " << Name << " died..." << std::endl; 
}

int		FragTrap::getLevel(void) const { return Level; }

void	FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << Name << " attacked " << target;
	std::cout << " at range, causing " << Ranged_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << Name << " attacked " << target;
	std::cout << " at melee, causing " << Melee_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP " << Name << " got ";
	std::cout << amount << " damage" << std::endl;
	Hit_points -= amount - Armor_damage_reduction;
	if (Hit_points < 0)
		Hit_points = 0;
	std::cout << "Hit point is " << Hit_points << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << amount << " was repaired" << std::endl;
	Hit_points += amount;
	if (Hit_points > Max_hit_points)
		Hit_points = Max_hit_points;
	Energy_points += amount;
	if (Energy_points > Max_energy_points)
		Energy_points = Max_energy_points;
	std::cout << "Hit point is " << Hit_points << std::endl;
	std::cout << "Energy point is " << Energy_points << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int			num;
	std::string	skill[5] = {"Miniontrap", "Meat unicycle", "Funzerker", "Mechomagician", "Shhhh....trap"};

	if (Energy_points < 25)
	{
		std::cout << "FR4G-TP " << Name << " has not enough energy!!" << std::endl;
		return ;
	}
	num = rand() % 5;
	std::cout << "FR4G-TP " << Name << " attacked " << target;
	std::cout << " with " << skill[num] << std::endl;
	Energy_points -= 25;
	if (Energy_points < 0)
		Energy_points = 0;
	std::cout << "Energy point is " << Energy_points << std::endl;
}
