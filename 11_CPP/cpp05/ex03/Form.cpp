#include "Form.hpp"

Form::Form()
	: _name("default"), _sign(false), _sign_grade(0), _exec_grade(0)
{
}

Form::Form(std::string name, int sign, int exec)
	: _name(name), _sign(false), _sign_grade(sign), _exec_grade(exec)
{
}

Form::Form(Form const &fm)
	: _name(fm.getName()), _sign(fm.getSign()), _sign_grade(fm.getSignGrade()), _exec_grade(getExecGrade())
{
	*this = fm;
}

Form&	Form::operator=(Form const &fm)
{
	this->_sign = fm._sign;
	return *this;
}

Form::~Form()
{
}

void	Form::beSigned(Bureaucrat const &brc)
{
	if (brc.getGrade() > _sign_grade)
		throw Form::GradeTooLowException();
	_sign = true;
}

void	Form::check(Bureaucrat const &executor) const
{
	if (this->_sign == false)
		throw Form::IsNotSigned();
	else if (executor.getGrade() > this->_exec_grade)
		throw Form::GradeTooLowException();
}

void	Form::execute(Bureaucrat const &executor) const
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

std::string		Form::getName() const { return _name; }
int				Form::getSignGrade() const { return _sign_grade; }
int				Form::getExecGrade() const { return _exec_grade; }
bool			Form::getSign() const { return _sign; }

std::ostream&	operator<<(std::ostream& os, Form const &fm)
{
	os << fm.getName() << " form needs " << fm.getSignGrade() << " grade for sign, ";
	os << fm.getExecGrade() << " grade for execution!" << std::endl;
	if (fm.getSign())
		os << fm.getName() << " is siged, already!" << std::endl;
	else
		os << fm.getName() << " is not signed, yet!" << std::endl;
	return os;
}
