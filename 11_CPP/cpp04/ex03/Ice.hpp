#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria
{
	private:
		std::string		_name;
	public:
		Ice();
		Ice(std::string const &name);
		Ice&	operator=(Ice const &icy);
		~Ice();
		virtual	AMateria*		clone() const;
		std::string const		&getName() const;
		void	use(ICharacter& target);
};

#endif
