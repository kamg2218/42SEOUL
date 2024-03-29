#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		int			_idx;
		int			_max;
		AMateria*	_materia[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &mts);
		MateriaSource&	operator=(MateriaSource const &mts);
		virtual	~MateriaSource();
		virtual	void	learnMateria(AMateria* amt);
		virtual	AMateria*	createMateria(std::string const &type);
};

#endif
