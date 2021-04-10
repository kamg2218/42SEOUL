#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	try{	
		Bureaucrat	brew("brew", 3);
		Intern		randomIntern;
		Form*	fm;

		fm = randomIntern.makeForm("shrubbery creation", "home");
		brew.signForm(*fm);
		fm->execute(brew);
		delete fm;
		std::cout << "----------------------" << std::endl;
		
		fm = randomIntern.makeForm("shrubbery creation", "house");
		brew.signForm(*fm);
		brew.executeForm(*fm);
		delete fm;
		std::cout << "----------------------" << std::endl;
	
		fm = randomIntern.makeForm("robotomy request", "robert");
		brew.signForm(*fm);
		fm->execute(brew);
		fm->execute(brew);
		fm->execute(brew);
		fm->execute(brew);
		delete fm;
		std::cout << "----------------------" << std::endl;

		fm = randomIntern.makeForm("presidential pardon", "press");
		fm->execute(brew);
		fm->beSigned(brew);
		fm->execute(brew);
		delete fm;
		std::cout << "----------------------" << std::endl;
		
		fm = randomIntern.makeForm("no one know", "creative");
		delete fm;
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what();
	}
	return 0;
}
