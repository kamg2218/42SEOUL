#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
	Hit_points = 60;
	Max_hit_points = 60;
	Energy_points = 120;
	Max_energy_points = 120;
	Level = 1;
	Melee_attack_damage = 60;
	Ranged_attack_damage = 5;
	Armor_damage_reduction = 0;
	std::cout << "NinjaTrap " << Name << " made!!" << std::endl;
}

NinjaTrap::NinjaTrap(std::string const &str)
{
	Hit_points = 60;
	Max_hit_points = 60;
	Energy_points = 120;
	Max_energy_points = 120;
	Level = 1;
	Melee_attack_damage = 60;
	Ranged_attack_damage = 5;
	Armor_damage_reduction = 0;
	Name = str;
	std::cout << "NinjaTrap " << Name << " made!!" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap " << Name << " died..." << std::endl; 
}

NinjaTrap&	NinjaTrap::operator=(NinjaTrap const &nt)
{
	this->Hit_points = nt.Hit_points;
	this->Max_hit_points = nt.Max_hit_points;
	this->Energy_points = nt.Energy_points;
   	this->Max_energy_points = nt.Max_energy_points;
	this->Level = nt.Level;
	this->Melee_attack_damage = nt.Melee_attack_damage;
	this->Ranged_attack_damage = nt.Ranged_attack_damage;
	this->Armor_damage_reduction = nt.Armor_damage_reduction;
	this->Name = nt.Name;
	return *this;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap& nt)
{
	std::cout << "NinjaTrap " << nt.getName() << " is wearing nt shoes!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap& ft)
{
	std::cout << "FragTrap " << ft.getName() << " is wearing ft shoes!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap& st)
{
	std::cout << "ScavTrap " << st.getName() << " is wearing st shoes!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap& ct)
{
	std::cout << "ClapTrap " << ct.getName() << " is wearing ct shoes!" << std::endl;
}

void	NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << "ScavTrap " << Name << " attacked " << target;
	std::cout << " at range, causing " << Ranged_attack_damage;
	std::cout << " points of damage!" << std::endl;
}

void	NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "ScavTrap " << Name << " attacked " << target;
	std::cout << " at melee, causing " << Melee_attack_damage;
	std::cout << " points of damage!" << std::endl;
}
