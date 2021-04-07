#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class	SuperMutant : public Enemy
{
	private:
		int			m_hp;
		std::string m_type;
	public:
		SuperMutant();
		SuperMutant(SuperMutant const &smt);
		SuperMutant&	operator=(SuperMutant const &smt);
		~SuperMutant();
		std::string		getType() const;
		int				getHP() const;
		virtual void	takeDamage(int amount);
};

#endif
