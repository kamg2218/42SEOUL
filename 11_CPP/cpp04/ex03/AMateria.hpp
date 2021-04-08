#ifndef AMATRIA_HPP
# define AMATRIA_HPP

#include <iostream>
#include <string>

class	AMateria
{
	protected:
		unsigned int	_xp;
		std::string		_type;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria&	operator=(AMateria const &amt);
		~AMateria();
		std::string const	&getType() const;
		unsigned int		getXP() const;
		virtual	AMateria*	clone() const = 0;
		virtual	void		use(ICharacter& target);
};

#endif
