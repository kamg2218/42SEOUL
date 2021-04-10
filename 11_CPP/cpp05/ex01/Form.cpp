#include "Form.hpp"

Form::Form()
	: _name("default"), _sign(false), _sign_grade(0), _exec_grade(0)
{
}

Form::Form(std::string name, int sign, int exec)
	: _name(name), _sign(false), _sign_grade(sign), _exec_grade(exec)
{
}

Form::~Form()
{
}

void	Form::beSigned(Bureaucrat const &brc)
{
	if (brc.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_sign = true;
}

std::string		Form::getName() const { return _name; }
int				Form::getSignGrade() const { return _sign_grade; }
int				Form::getExecGrade() const { return _exec_grade; }
bool			Form::getSign() const { return _sign; }

std::ostream&	operator<<(std::ostream& os, Form const &fm)
{
	os << fm.getName() << " form needs " << fm.getSignGrade() << " grade for sign, ";
	os << fm.getExecGrade() << " grade for execution!" << std::endl;
	return os;
}
