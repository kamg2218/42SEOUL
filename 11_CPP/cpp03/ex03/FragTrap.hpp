#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const &str);
		FragTrap&	operator=(FragTrap const &ft);
		void		vaulthunter_dot_exe(std::string const &target);
		~FragTrap();
};

#endif
