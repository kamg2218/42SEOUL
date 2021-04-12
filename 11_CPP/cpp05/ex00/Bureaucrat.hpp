#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat
{
	private:
		std::string	const _name;
		int			_grade;
		Bureaucrat();
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &brc);
		Bureaucrat&	operator=(Bureaucrat const &brc);
		~Bureaucrat();
		std::string	getName() const;
		int		getGrade() const;
		void	increment();
		void	decrement();
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return "the grade is too high!\n";
				}
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return "the grade is too low!\n";
				}
		};
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &brc);

#endif
