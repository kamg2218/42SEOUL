#include "iterator.hpp"
#include <list>
#include <iostream>

int		main()
{
	std::list<int> vt;
	vt.push_back(3);
	vt.push_back(4);
	vt.push_back(5);
	vt.push_back(6);
	Iterator<int>	it = vt.begin();
	
	it++;
	++it;

	std::cout << *it;
	
	if (*(vt.begin()) == *it)
		return (-1);

	return 0;
}
