#ifndef FORM_HPP
# define FORM_HPP

class	Form;
#include "Bureaucrat.hpp"

class	Form
{
	protected:
		std::string const	_name;
		bool		_sign;
		int const	_sign_grade;
		int	const	_exec_grade;
		Form();
	public:
		Form(std::string name, int sign, int exec);
		Form(Form const &fm);
		Form&	operator=(Form const &fm);
		virtual ~Form();
		std::string getName() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		bool	getSign() const;
		virtual void	action() const = 0;
		void	beSigned(Bureaucrat const &brc);
		void	check(Bureaucrat const &executor) const;
		void	execute(Bureaucrat const &executor) const;
		class	GradeTooHighException : public std::exception
		{
			public:
			virtual const char* what() const throw(){
				return "the grade is too hgih!\n";
			}
		};
		class	GradeTooLowException : public std::exception
		{
			public:
			virtual const char* what() const throw(){
				return "the grade is too low!\n";
			}
		};
		class	IsNotSigned : public std::exception
		{
			public:
			virtual const char* what() const throw(){
				return "this form is not signed yet!\n";
			}
		};
};

std::ostream&	operator<<(std::ostream& os, Form const &fm);

#endif
