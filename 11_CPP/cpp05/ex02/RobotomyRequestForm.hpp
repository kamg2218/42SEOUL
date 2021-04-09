#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class	RobotomyRequestForm : virtual public Form
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(Form *fm);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &rmrf);
		~RobotomyRequestForm();
		void	action() const;
		//void	check(Bureaucrat const &executor) const;
		void	execute(Bureaucrat const &executor) const;
};

#endif
