#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;
		std::exception	_ex;
		Bureaucrat();
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat&	operator=(Bureaucrat const &brc);
		~Bureaucrat();
		std::string	getName() const;
		int		getGrade() const;
		void	increment();
		void	decrement();
		std::exception	GradeTooHighException();
		std::exception	GradeTooLowException();
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &brc);

#endif
