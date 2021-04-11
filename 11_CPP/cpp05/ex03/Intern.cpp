#include "Intern.hpp"

Intern::Intern()
	: _name("default")
{
	_type[0].t_name = "shrubbery creation";
	_type[0].func = &createShrubberyForm;
	_type[1].t_name = "presidential pardon";
	_type[1].func = &createPresidentialForm;
	_type[2].t_name = "robotomy request";
	_type[2].func = &createRobotomyForm;
}

Intern::Intern(std::string const &name)
	: _name(name)
{
	_type[0].t_name = "shrubbery creation";
	_type[0].func = &createShrubberyForm;
	_type[1].t_name = "presidential pardon";
	_type[1].func = &createPresidentialForm;
	_type[2].t_name = "robotomy request";
	_type[2].func = &createRobotomyForm;
}

Intern::Intern(Intern const &it) { *this = it; }

Intern&	Intern::operator=(Intern const &it)
{
	this->_name = it._name;
	return *this;
}

Intern::~Intern()
{
}

Form*	Intern::makeForm(std::string const &name, std::string const &target)
{
	for (int i = 0; i < 3; i++)
	{
		if (name == _type[i].t_name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return _type[i].func(target);
		}
	}
	std::cout << name << " form doesn't exist!" << std::endl;
	return NULL;
}

Form*	createShrubberyForm(std::string const &target){ 
	return new ShrubberyCreationForm(target);
}

Form*	createRobotomyForm(std::string const &target){
	return new RobotomyRequestForm(target);
}

Form*	createPresidentialForm(std::string const &target){
	return new PresidentialPardonForm(target);
}
