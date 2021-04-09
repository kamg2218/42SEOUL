#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat	brc1("owner", 1);
	Bureaucrat	brc2("ceo", 3);
	Form		fm("form_first", 2, 5);

	brc1.signForm(fm);
	brc2.signForm(fm);

	return 0;
}
