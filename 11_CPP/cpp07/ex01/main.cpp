#include <iostream>
#include "iter.hpp"

int			main()
{
	int		array[5] = {1, 2, 3, 4, 5};
	char	array2[5] = {'1', '2', '3', '4', '5'};

	::iter(array, 5, &print);
	std::cout << std::endl;
	::iter(array2, 5, &print);
	std::cout << std::endl;
	
	int		tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);
	
	return 0;
}
