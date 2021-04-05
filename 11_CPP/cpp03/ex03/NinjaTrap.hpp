#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ScavTrap.hpp"

class	NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap();
		NinjaTrap(std::string const &str);
		void	ninjaShoebox(NinjaTrap& nt);
		void	ninjaShoebox(FragTrap& ft);
		void	ninjaShoebox(ScavTrap& st);
		void	ninjaShoebox(ClapTrap& ct);
		~NinjaTrap();
};

#endif
