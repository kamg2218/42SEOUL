#include <iostream>
#include "iter.hpp"

int			main()
{
	int		array[5] = {1, 2, 3, 4, 5};
	char	array2[5] = {'1', '2', '3', '4', '5'};

	::iter(array, 5, &print);
	std::cout << std::endl;
	::iter(array2, 5, &print);
	return 0;
}
