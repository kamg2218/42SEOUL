#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: Form(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ppf) { *this = ppf; }

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &ppf)
{
	this->_sign = ppf._sign;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::action() const
{
	std::cout << _name << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
