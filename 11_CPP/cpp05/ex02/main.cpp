#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	try{	
		//Bureaucrat	brew("brew", 200);
		//Bureaucrat	brew("brew", -1);
		Bureaucrat	brew("brew", 3);

		ShrubberyCreationForm	berry("home");
		brew.signForm(berry);
		berry.execute(brew);
		std::cout << "----------------------" << std::endl;
		
		ShrubberyCreationForm	burry("home");
		brew.signForm(burry);
		brew.executeForm(burry);
		std::cout << "----------------------" << std::endl;
	
		RobotomyRequestForm robert("robert");
		brew.signForm(robert);
		robert.execute(brew);
		robert.execute(brew);
		robert.execute(brew);
		robert.execute(brew);
		std::cout << "----------------------" << std::endl;

		PresidentialPardonForm	president("presi");
		president.execute(brew);
		std::cout << "----------------------" << std::endl;
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what();
	}
	return 0;
}
