#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &brc)
	: _name(brc.getName())
{
	*this = brc;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &brc)
{
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
	_grade -= 1;
}

void			Bureaucrat::decrement()
{
	if (_grade > 149)
		throw GradeTooLowException();
	_grade += 1;
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &brc)
{
	os << brc.getName() << ", bureaucrat grade " << brc.getGrade() << "." << std::endl;
	return os;
}
