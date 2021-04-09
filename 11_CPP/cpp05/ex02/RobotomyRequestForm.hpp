#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class	RobotomyRequestForm : virtual public Form
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &rmrf);
		~RobotomyRequestForm();
		void	action() const;
		void	execute(Bureaucrat const &executor) const;
};

#endif
