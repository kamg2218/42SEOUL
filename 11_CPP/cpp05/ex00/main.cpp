#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat	*brc;

	try
	{
		brc = new Bureaucrat("first", 2);
		std::cout << *brc;
		brc->increment();
		std::cout << *brc;
		brc->increment();
		std::cout << *brc;
	}
	catch (std::exception& e)
	{
		std::cout << "Error!!!" << std::endl;
	}
	
	delete brc;
	
	try
	{
		brc = new Bureaucrat("first", 149);
		std::cout << *brc;
		brc->decrement();
		std::cout << *brc;
		brc->decrement();
		std::cout << *brc;
	}
	catch (std::exception& e)
	{
		std::cout << "Error!!!" << std::endl;
	}

	delete brc;

	return 0;
}
