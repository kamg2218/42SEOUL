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
		class	GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw(){
					return "the grade is too high!\n";
				}
		};
		class	GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw(){
					return "the grade is too low!\n";
				}
		};
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &brc);

#endif
