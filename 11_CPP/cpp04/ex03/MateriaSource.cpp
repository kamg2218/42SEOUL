#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	: IMateriaSource(), _idx(0), _max(4)
{
}

MateriaSource::MateriaSource(MateriaSource const &mts)
	: IMateriaSource(), _idx(0), _max(4)
{
	*this = mts;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const &mts)
{
	this->_idx = mts._idx;
	this->_max = mts._max;
	
	return *this;
}

MateriaSource::~MateriaSource()
{
}

void	MateriaSource::learnMateria(AMateria* amt)
{
	AMateria* tmp;

	
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
}
