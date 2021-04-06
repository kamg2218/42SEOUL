#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class	PlasmaRifle : public AWeapon
{
	private:
		std::string	m_name;
		int			m_apcost;
		int			m_damage;
	public:
		PlasmaRifle();
		PlasmaRifle(std::string const &name, int apcost, int damage);
		PlasmaRifle&	operator=(PlasmaRifle const &prf);
		virtual void	attack();
		int				getAPCost() const;
		int				getDamage() const;
		std::string		getName() const;
		~PlasmaRifle();
};

#endif
