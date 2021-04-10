#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice"), _name("ice")
{
}

Ice::Ice(std::string const &name)
	: AMateria("ice"), _name(name)
{
}

Ice&	Ice::operator=(Ice const &icy)
{
	this->_name = icy._name;
	return *this;
}

Ice::~Ice()
{
}

std::string const	&Ice::getName() const { return _name; }

AMateria*	Ice::clone() const
{
	AMateria*	tmp;

	tmp = new Ice;
	return tmp;
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	setXP(getXP() + 10);
}
