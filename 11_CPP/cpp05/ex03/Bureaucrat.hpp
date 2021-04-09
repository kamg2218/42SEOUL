#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat;
#include "Form.hpp"

class	Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;
		Bureaucrat();
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat&	operator=(Bureaucrat const &brc);
		~Bureaucrat();
		std::string	getName() const;
		int		getGrade() const;
		void	increment();
		void	decrement();
		void	signForm(Form &fm);
		void	executeForm(Form const &form);
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &brc);

#endif
