#include "Span.hpp"
#include <iostream>

int			main(void)
{
	try{
		Span	sp1 = Span(5);

		sp1.addNumber(3);
		std::cout << "shortest = " << sp1.shortestSpan() << std::endl;
		std::cout << "longest = " << sp1.longestSpan() << std::endl;
		std::cout << "------------------\n";
	
		Span	sp2(4);
	
		sp2.addNumber(3);
		sp2.addNumber(12);
		sp2.addNumber(12);
		sp2.addNumber(125);
		std::cout << "shortest = " << sp2.shortestSpan() << std::endl;
		std::cout << "longest = " << sp2.longestSpan() << std::endl;
		//sp2.addNumber(125);
		std::cout << "------------------\n";
		//Span	sp3(0);
		//sp3.addNumber(3);
		std::cout << "------------------\n";
		
		Span	sp4;
		//sp4.addNumber(3);
		std::cout << "------------------\n";
	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}

	return 0;
}
