#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class	ShrubberyCreationForm : virtual public Form
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &sbcf);
		~ShrubberyCreationForm();
		void	action() const;
		//void	check(Bureaucrat const &executor) const;
		void	execute(Bureaucrat const &executor) const;
};

#endif
