#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class	PowerFist : public AWeapon
{
	private:
		std::string	m_name;
		int			m_apcost;
		int			m_damage;
	public:
		PowerFist();
		PowerFist(std::string const &name, int apcost, int damage);
		PowerFist&		operator=(PowerFist const &pf);
		virtual void	attack();
		int				getAPCost() const;
		int				getDamage() const;
		std::string		getName() const;
		~PowerFist();
};

#endif
