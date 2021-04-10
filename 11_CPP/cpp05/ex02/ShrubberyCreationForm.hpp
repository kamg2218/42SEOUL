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
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &sbcf);
		~ShrubberyCreationForm();
		void	action() const;
};

#endif
