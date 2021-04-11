#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
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
	_grade -= 1;
}

void			Bureaucrat::decrement()
{
	if (_grade > 149)
		throw GradeTooLowException();
	_grade += 1;
}

void			Bureaucrat::signForm(Form &fm)
{
	try{
		fm.beSigned(*this);
		std::cout << this->_name << " signs " << fm.getName() << std::endl;
	}
	catch (std::exception& ex){
		std::cout << this->_name << " cannot sign " << fm.getName();
		std::cout << ", because " << ex.what();
	}
}

void	Bureaucrat::executeForm(Form const &form)
{
	try{
		form.check(*this);
		form.action();
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception& ex){
		std::cout << this->_name << " failed to execute " << form.getName() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &brc)
{
	os << brc.getName() << ", bureaucrat grade " << brc.getGrade() << "." << std::endl;
	return os;
}
