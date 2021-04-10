#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

typedef Form* (*function)(std::string const &target);
typedef struct	s_type
{
	std::string		t_name;
	function		func;
}	t_type;

class	Intern
{
	private:
		std::string		_name;
		t_type			_type[3];
	public:
		Intern();
		Intern(std::string const &name);
		Intern&	operator=(Intern const &it);
		~Intern();
		Form*	makeForm(std::string const &name, std::string const &target);
//		Form*	createShrubberyForm(std::string const &target);
//		Form*	createRobotomyForm(std::string const &target);
//		Form*	createPresidentialForm(std::string const &target);
};

Form*	createShrubberyForm(std::string const &target);
Form*	createRobotomyForm(std::string const &target);
Form*	createPresidentialForm(std::string const &target);

#endif
