#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const &str);
		void			vaulthunter_dot_exe(std::string const &target);
		~FragTrap();
};

#endif
