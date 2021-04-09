#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class	PresidentialPardonForm : virtual public Form
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const &ppf);
		~PresidentialPardonForm();
		void	action() const;
		//void	check(Bureaucrat const &executor) const;
		void	execute(Bureaucrat const &executor) const;
};

#endif
