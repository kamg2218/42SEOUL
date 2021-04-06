#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const &str);
		FragTrap&	operator=(FragTrap const &ft);
		void		vaulthunter_dot_exe(std::string const &target);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		~FragTrap();
};

#endif
