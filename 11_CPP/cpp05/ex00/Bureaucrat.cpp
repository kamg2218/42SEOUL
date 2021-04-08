#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &brc)
{
	this->_name = brc._name;
	this->_grade = brc._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string		Bureaucrat::getName() const { return _name; }
int				Bureaucrat::getGrade() const { return _grade; }

void			Bureaucrat::increment()
{
	if (_grade < 2)
		throw GradeTooHighException();
	else
		_grade -= 1;
}

void			Bureaucrat::decrement()
{
	if (_grade > 149)
		throw GradeTooLowException();
	else
		_grade += 1;
}

std::exception	Bureaucrat::GradeTooHighException()
{
	//std::exception	ex;
	std::cout << "Grade is too high!" << std::endl;
	return _ex;
}

std::exception	Bureaucrat::GradeTooLowException()
{
	//std::exception	ex;
	std::cout << "Grade is too low!" << std::endl;
	return _ex;
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &brc)
{
	os << brc.getName() << ", bureaucrat grade " << brc.getGrade() << "." << std::endl;
	return os;
}
