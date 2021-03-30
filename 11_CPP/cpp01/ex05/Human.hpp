#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class	Human
{
	private:
		Brain		brn;
	public:
		const std::string	identify();
		Brain				&getBrain();
};

#endif
