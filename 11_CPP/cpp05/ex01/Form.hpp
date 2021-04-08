#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class	Form
{
	private:
		std::string const	_name;
		bool		_sign;
		int const	_sign_grade;
		int	const	_exec_grade;
		std::exception	_ex;
		Form();
	public:
		Form(std::string name, int sign, int exec);
		//Form(Form const &fm);
		~Form();
		std::string	getName();
		int		getSignGrade();
		int		getExecGrade();
		bool	getSign();
		void	beSigned(Bureaucrat const &brc);
		std::exception&	GradeTooHighException();
		std::exception&	GradeTooLowException();
};

std::ostream&	operator<<(std::ostream& os, Form const &fm);

#endif
