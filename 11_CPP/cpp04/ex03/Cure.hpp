#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
	private:
		std::string		_name;
	public:
		Cure();
		Cure(std::string const &name);
		Cure&	operator=(Cure const &cr);
		~Cure();
		virtual	AMateria*		clone() const;
		std::string& const		getName() const;
};

#endif
