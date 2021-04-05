#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const &str);
		void	vaulthunter_dot_exe(std::string const &target);
		void	rangedAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		~FragTrap();
};

#endif
