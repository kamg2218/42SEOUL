#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"

class	RadScorpion : public Enemy
{
	private:
		int			m_hp;
		std::string m_type;
	public:
		RadScorpion();
		RadScorpion(RadScorpion const &rsp);
		RadScorpion&	operator=(RadScorpion const &rsp);
		~RadScorpion();
		std::string		getType() const;
		int				getHP() const;
};

#endif
