#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		int			_idx;
		int			_max;
		AMateria*	_materia[4];
		std::string	_name;
	public:
		Character();
		Character(std::string const &name);
		Character&	operator=(Character const &ch);
		virtual ~Character();
		virtual std::string const	&getName() const;
		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual	void	use(int idx, ICharacter& target);
};

#endif
