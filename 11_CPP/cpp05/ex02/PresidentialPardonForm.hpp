#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class	PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &ppf);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const &ppf);
		~PresidentialPardonForm();
		virtual void	action() const;
};

#endif
