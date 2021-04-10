#ifndef AMATRIA_HPP
# define AMATRIA_HPP

#include <iostream>
#include <string>

class AMateria;
#include "ICharacter.hpp"

class	AMateria
{
	private:
		unsigned int	_xp;
		std::string		_type;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria&	operator=(AMateria const &amt);
		virtual	~AMateria();
		void	setXP(unsigned int xp);
		void	setType(std::string const &type);
		unsigned int		getXP() const;
		std::string const	&getType() const;
		virtual	AMateria*	clone() const = 0;
		virtual	void		use(ICharacter& target);
};

#endif
