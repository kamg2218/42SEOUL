#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>
#include <string>

class	AWeapon
{
	protected:
		std::string	m_name;
		int			m_apcost;
		int			m_damage;
	public:
		AWeapon();
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon&	operator=(AWeapon const &awp);
		std::string	getName() const;
		int			getAPCost() const;
		int			getDamage() const;
		virtual void	attack() const = 0;
		virtual ~AWeapon();
};

#endif
