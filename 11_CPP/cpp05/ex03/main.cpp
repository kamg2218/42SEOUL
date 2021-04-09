#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Bureaucrat	brew("brew", 7);

	ShrubberyCreationForm	berry("home");
	//brew.signForm(berry);
	//berry.execute(brew);
	brew.executeForm(berry);

	RobotomyRequestForm robert("robert");
	brew.signForm(robert);
	robert.execute(brew);

	PresidentialPardonForm	president("presi");
	president.execute(brew);

	return 0;
}
