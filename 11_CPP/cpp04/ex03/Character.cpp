#include "Character.hpp"

Character::Character()
	: ICharacter(), _idx(0), _max(4), _name("default")
{
}

Character::Character(std::string const &name)
	: ICharacter(), _idx(0), _max(4), _name(name)
{
}

Character&	Character::operator=(Character const &ch)
{
	for (int i = 0; i < _idx; i++)
		delete _materia[i];
	this->_idx = ch._idx;
	this->_max = ch._max;
	for (int i = 0; i < ch._idx; i++)
		this->_materia[i] = ch._materia[i]->clone();
	return *this;
}

Character::~Character()
{
}

std::string const	&Character::getName() const { return _name; }
		
void	Character::equip(AMateria* m)
{
	if (_idx == _max)
	{
		std::cout << "It's full, already!" << std::endl;
		return ;
	}
	_materia[_idx] = m->clone();
	_idx++;
}
		
void	Character::unequip(int idx)
{
	if (idx >= _idx)
	{
		std::cout << "It's empty!" << std::endl;
		return ;
	}
	delete _materia[idx];
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= _idx)
	{
		std::cout << "It's empty!" << std::endl;
		return ;
	}
	_materia[idx]->use(target);
}
