#include "AMateria.hpp"

AMateria::AMateria()
	: _xp(0), _type("materia")
{
}

AMateria::AMateria(std::string const &type)
	: _xp(0), _type(type)
{
}

AMateria&	AMateria::operator=(AMateria const &amt)
{
	this->_xp = amt._xp;
	this->_type = amt._type;
	return *this;
}

AMateria::~AMateria()
{
}

std::string const	&AMateria::getType() const { return _type; }
unsigned int		AMateria::getXP() const { return _xp; }
void	AMateria::setXP(unsigned int xp) { _xp = xp; }
void	AMateria::setType(std::string const &type) { _type = type; }

void		AMateria::use(ICharacter& target)
{
	std::cout << "* " << target.getName() << " got damage *" << std::endl;
	_xp += 10;
}
