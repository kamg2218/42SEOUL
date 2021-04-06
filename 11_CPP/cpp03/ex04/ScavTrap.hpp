#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "FragTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string const &str);
		ScavTrap&	operator=(ScavTrap const &st);
		void		challengeNewcomer(FragTrap const &ft);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		~ScavTrap();
};

#endif
