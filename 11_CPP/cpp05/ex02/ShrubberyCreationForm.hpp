#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class	ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &sbcf);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &sbcf);
		~ShrubberyCreationForm();
		virtual void	action() const;
};

#endif
