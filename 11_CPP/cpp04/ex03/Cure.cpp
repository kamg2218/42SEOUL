#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure"), _name("cure")
{
}

Cure::Cure(std::string const &name)
	: AMateria("cure"), _name(name)
{
}

Cure&	Cure::operator=(Cure const &cr)
{
	this->_name = cr._name;
	return *this;
}

Cure::~Cure()
{
}

std::string const	&Cure::getName() const { return _name; }

AMateria*	Cure::clone() const
{
	AMateria*	tmp;

	tmp = new Cure;
	return tmp;
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	setXP(getXP() + 10);
}
