#include "Array.hpp"
#include <iostream>
#include <string>

int			main(void)
{
	try{
		Array<int>	a(10);
		a[2] = 1;
		a[4] = 8;

		std::cout << "'" << a[2] << "'" << std::endl;
		std::cout << "'" << a[4] << "'" << std::endl;
		//std::cout << "'" << a[6] << "'" << std::endl;

		Array<char>	a2(5);
		
		std::cout << "'" << a2[3] << "'" << std::endl;
		//std::cout << "'" << a2[6] << "'" << std::endl;
		
	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}
	return 0;
}
