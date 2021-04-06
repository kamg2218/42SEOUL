#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ScavTrap.hpp"

class	NinjaTrap : virtual public ClapTrap
{
	public:
		NinjaTrap();
		NinjaTrap(std::string const &str);
		NinjaTrap&	operator=(NinjaTrap const &nt);
		void		ninjaShoebox(NinjaTrap& nt);
		void		ninjaShoebox(FragTrap& ft);
		void		ninjaShoebox(ScavTrap& st);
		void		ninjaShoebox(ClapTrap& ct);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		~NinjaTrap();
};

#endif
