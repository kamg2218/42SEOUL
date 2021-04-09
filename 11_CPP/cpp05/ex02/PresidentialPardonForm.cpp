#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(Form* fm)
	: Form(fm->getName(), 25, 5)
{
	_sign = fm->getSign();
}

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
/*
void	PresidentialPardonForm::check(Bureaucrat const &executor) const
{
	if (this->_sign == false)
		throw Form::IsNotSigned();
	else if (executor.getGrade() > this->_exec_grade)
		throw Form::GradeTooLowException();
}
*/
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try{
		check(executor);
		action();
	}
	catch (std::exception& ex){
		std::cout << executor.getName() << " can not execute this form, ";
		std::cout << "because " << ex.what();
	}
}
