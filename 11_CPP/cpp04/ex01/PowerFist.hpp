#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class	PowerFist : public AWeapon
{
	public:
		PowerFist();
		PowerFist(PowerFist const &pf);
		PowerFist&		operator=(PowerFist const &pf);
		virtual void	attack() const;
		int				getAPCost() const;
		int				getDamage() const;
		std::string		getName() const;
		~PowerFist();
};

#endif
