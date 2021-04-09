#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Form		fm("home", 10, 8);
	Bureaucrat	brew("brew", 7);

	ShrubberyCreationForm	berry(&fm);
	//berry.action();
	brew.signForm(fm);
	berry.execute(brew);

	RobotomyRequestForm robert(&fm);
	//robert.action();
	robert.execute(brew);

	PresidentialPardonForm	president(&fm);
	//president.action();
	president.execute(brew);

	return 0;
}
