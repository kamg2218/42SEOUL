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
		delete brc;
	}
	catch (std::exception& e)
	{
		std::cout << "Error : " << e.what();
	}
	
	try
	{
		brc = new Bureaucrat("second", 149);
		std::cout << *brc;
		brc->decrement();
		std::cout << *brc;
		brc->decrement();
		std::cout << *brc;
		delete brc;
	}
	catch (std::exception& e)
	{
		std::cout << "Error : " << e.what();
	}

	try
	{
		brc = new Bureaucrat("third", -1);
		std::cout << *brc;
		delete brc;
	}
	catch (std::exception& e)
	{
		std::cout << "Error : " << e.what();
	}

	try
	{
		brc = new Bureaucrat("forth", 200);
		std::cout << *brc;
		delete brc;
	}
	catch (std::exception& e)
	{
		std::cout << "Error : " << e.what();
	}

	return 0;
}
