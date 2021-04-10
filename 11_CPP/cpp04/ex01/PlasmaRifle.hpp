#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class	PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const &prf);
		PlasmaRifle&	operator=(PlasmaRifle const &prf);
		virtual void	attack() const;
		int				getAPCost() const;
		int				getDamage() const;
		std::string		getName() const;
		~PlasmaRifle();
};

#endif
