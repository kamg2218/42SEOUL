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
	for (int i = 0; i < _idx; i++)
		delete _materia[i];
	this->_idx = mts._idx;
	this->_max = mts._max;
	for (int i = 0; i < _idx; i++)
		_materia[i] = mts._materia[i]->clone();
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _idx; i++)
		delete _materia[i];
}

void	MateriaSource::learnMateria(AMateria* amt)
{
	AMateria* tmp;

	if (_idx >= _max)
	{
		std::cout << "No more space!" << std::endl;
		return ;
	}
	tmp = amt->clone();
	tmp->setXP(amt->getXP());
	tmp->setType(amt->getType());
	_materia[_idx] = tmp;
	_idx++;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _idx; i++)
	{
		if (_materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}
