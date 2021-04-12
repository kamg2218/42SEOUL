#include "Array.hpp"
#include <iostream>
#include <string>

int			main(void)
{
	try{
		Array<int>	a(3);
		
		std::cout << "'" << a.getNum(2) << "'" << std::endl;
		//std::cout << "'" << a.getNum(6) << "'" << std::endl;

		Array<char>	a2(5);
		
		std::cout << "'" << a2.getNum(3) << "'" << std::endl;
		//std::cout << "'" << a2.getNum(6) << "'" << std::endl;
		
		//Array<int>	a3[3];
		
		//std::cout << "'" << a3->getNum(2) << "'" << std::endl;
		//std::cout << "'" << a3->getNum(6) << "'" << std::endl;
	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}
	return 0;
}
