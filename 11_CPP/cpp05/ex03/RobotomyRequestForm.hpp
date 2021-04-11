#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class	RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &rmrf);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &rmrf);
		~RobotomyRequestForm();
		virtual void	action() const;
};

#endif
