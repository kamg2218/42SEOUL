#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"

class	RadScorpion : public Enemy
{
	public:
		RadScorpion();
		RadScorpion(RadScorpion const &rsp);
		RadScorpion&	operator=(RadScorpion const &rsp);
		~RadScorpion();
		std::string		getType() const;
		int				getHP() const;
};

#endif
