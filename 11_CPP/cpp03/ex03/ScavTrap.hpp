#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string const &str);
		ScavTrap&	operator=(ScavTrap const &st);
		void		challengeNewcomer(FragTrap const &ft);
		~ScavTrap();
};

#endif
