#include "Bureaucrat.hpp"

int		main(void)
{
	try{
		Bureaucrat	brc1("owner", 1);
		Bureaucrat	brc2("ceo", 3);
		Form		fm("form_first", 2, 5);

		brc1.signForm(fm);
		std::cout << fm.getSign() << std::endl;
		
		brc2.signForm(fm);
		std::cout << fm.getSign() << std::endl;
		
		brc2.increment();
		brc2.signForm(fm);
		std::cout << fm.getSign() << std::endl;
		
		brc1.decrement();
		brc1.decrement();
		brc1.signForm(fm);
		std::cout << fm.getSign() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	std::cout << "------------------" << std::endl;
	try{
		Bureaucrat	brc3("owner", 1);
		Bureaucrat	brc4("ceo", 3);
		Form		ffm("form_first", 2, 5);

		//std::cout << "sign : " << ffm.getSign() << std::endl;
		//std::cout << "---------" << std::endl;
		ffm.beSigned(brc3);
		std::cout << "sign : " << ffm.getSign() << std::endl;
		std::cout << "---------" << std::endl;
		ffm.beSigned(brc4);
		std::cout << "sign : " << ffm.getSign() << std::endl;
		std::cout << "---------" << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	std::cout << "------------------" << std::endl;

	try{
		Bureaucrat	brc5("new", -1);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	std::cout << "------------------" << std::endl;

	try{
		Bureaucrat	brc6("low", 200);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}

	return 0;
}
