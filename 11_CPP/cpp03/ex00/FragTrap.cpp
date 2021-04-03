#include "FragTrap.hpp"

FragTrap::FragTrap()
	: Hit_points(100), Max_hit_points(100)
	, Energy_points(100), Max_energy_points(100)
	, Level(1), Melee_attack_damage(30)
	, Ranged_attack_damage(20), Armor_damage_reduction(5)
{
}

FragTrap::FragTrap(std::string const &str)
	: Hit_points(100), Max_hit_points(100)
	, Energy_points(100), Max_energy_points(100)
	, Level(1), Melee_attack_damage(30)
	, Ranged_attack_damage(20), Armor_damage_reduction(5)
	, Name(str)
{
}

void	FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << Name << " attacks " << target;
	std::cout << " at range, causing " << Ranged_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << Name << " attacks " << target;
	std::cout << " at melee, causing " << Melee_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP " << Name << " got ";
	std::cout << amount << "damage" << std::endl;
	Hit_points -= amount;
	if (Hit_points < 0)
		Hit_points = 0;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << amount << " was repaired" << std::endl;
	Hit_points += amount;
	if (Hit_points > Max_hit_points)
		Hit_points = Max_hit_points;
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int			num;
	std::string	skill[5] = {"Miniontrap", "Meat unicycle", "Funzerker", "Mechomagician", "Shhhh....trap"};

	num = rand(clock()) % 5;
	std::cout << "FR4G-TP " << Name << " attacks " << target;
	std::cout << " with " << skill[num] << std::endl;
	Energy_points -= Ranged_attack_damage;
	if (Energy_points < 0)
		Energy_points = 0;
}
