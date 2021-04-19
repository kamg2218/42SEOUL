#include "easyfind.hpp"
#include <iostream>
#include <vector>

int			main(void)
{
	try{
		int		num[5] = {1, 2, 3, 4, 5};
		std::vector<int> v(num, num + 5);
		/*
		std::vector<int>	v;
		v.push_back(10);
		v.push_back(11);
		v.push_back(12);
		v.push_back(13);
		v.push_back(14);
		*/
		std::vector<int>::iterator	it;

		it = easyfind(v, 3);
		std::cout << *it << std::endl;
		it = easyfind(v, 16);
		std::cout << *it << std::endl;

	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}

	return 0;
}
