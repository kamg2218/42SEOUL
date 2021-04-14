#include "Span.hpp"
#include <iostream>
#include <unistd.h>

int			main(void)
{
	try{
		Span	sp1 = Span(5);

		sp1.addNumber(3);
		sp1.addNumber(3);
		std::cout << "sp1 shortest = " << sp1.shortestSpan() << std::endl;
		std::cout << "sp1 longest = " << sp1.longestSpan() << std::endl;
		std::cout << "------------------\n";
	
		Span	sp2(4);
	
		sp2.addNumber(3);
		sp2.addNumber(12);
		sp2.addNumber(13);
		sp2.addNumber(125);
		std::cout << "sp2 shortest = " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 longest = " << sp2.longestSpan() << std::endl;
		//sp2.addNumber(125);
		std::cout << "------------------\n";
		//Span	sp3(0);
		//sp3.addNumber(3);
		std::cout << "------------------\n";
		
		Span	sp4(20000);
	
		srand(clock());
		std::vector<unsigned int> v;
		for (int i = 0; i < 20000; i++)
			v.push_back(rand() % 10000 + 1);
		std::cout << "v size = " << v.size() << std::endl;

		std::vector<unsigned int>::iterator v1 = v.begin();
		std::vector<unsigned int>::iterator v2 = v.end();
		std::cout << "sp4 size = " << sp4.size() << std::endl;
		sp4.addNumber(v1, v2);
		std::cout << "sp4 size = " << sp4.size() << std::endl;
		std::cout << "sp4 shortest = " << sp4.shortestSpan() << std::endl;
		std::cout << "sp4 longest = " << sp4.longestSpan() << std::endl;
		std::cout << "------------------\n";
	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}

	return 0;
}
