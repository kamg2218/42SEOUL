#include "Form.hpp"

Form::Form()
	: _name("default"), _sign(false), _sign_grade(0), _exec_grade(0)
{
}

Form::Form(std::string name, int sign, int exec)
	: _name(name), _sign(false), _sign_grade(sign), _exec_grade(exec)
{
}
/*
Form::Form(Form const &fm)
{
	*this = fm;
}

Form&	Form::operator=(Form const &fm)
{
	this->_name = fm._name;
	this->_sign = fm._sign;
	this->_sign_grade = fm._sign_grade;
	this->_exec_grade = fm._exec_grade;
	return *this;
}
*/

Form::~Form()
{
}

void	Form::beSigned(Bureaucrat const &brc)
{
	if (brc.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_sign = true;
}

std::exception&	Form::GradeTooHighException()
{
	std::cout << "Grade is too high!" << std::endl;
	return _ex;
}

std::exception&	Form::GradeTooLowException()
{
	std::cout << "Grade is too low!" << std::endl;
	return _ex;
}

std::string		Form::getName() { return _name; }
int				Form::getSignGrade() { return _sign_grade; }
int				Form::getExecGrade() { return _exec_grade; }
bool			Form::getSign() { return _sign; }

std::ostream&	operator<<(std::ostream& os, Form const &fm)
{
	os << fm.getName() << " form needs " << fm.getSignGrade() << " grade for sign, ";
	os << fm.getExecGrade << " grade for execution!" << std::endl;
	return os;
}
