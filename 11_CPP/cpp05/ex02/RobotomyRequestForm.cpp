#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(Form* fm)
	: Form(fm->getName(), 72, 45)
{
	_sign = fm->getSign();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rmrf)
{
	this->_sign = rmrf.getSign();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::action() const
{
	std::cout << "drilllllllllling..." << std::endl;
	srand(clock());
	if (rand() % 2)
		std::cout << _name << " has been robotomized successfully." << std::endl;
	else
		std::cout << "It's a failure." << std::endl;
}
/*
void	RobotomyRequestForm::check(Bureaucrat const &executor) const
{
	if (this->_sign == false)
		throw Form::IsNotSigned();
	else if (executor.getGrade() > this->_exec_grade)
		throw Form::GradeTooLowException();
}
*/
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
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
