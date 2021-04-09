#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(std::string const &name, std::string const &target);
		Intern&	operator=(Intern const &it);
		~Intern();
		Form*	makeForm(std::string name, std::string target);
};

#endif
