#include "ft.hpp"

int			main(void)
{
	std::allocator<int>	alloc;
	ft::list<int>	lst1;
	std::cout << "lst1 made" << std::endl;

	ft::list<int>	lst2(alloc);
	std::cout << "lst2 made" << std::endl;

	ft::list<int>	lst3(lst2);
	std::cout << "lst3 made" << std::endl;
	
	ft::list<int>	lst4 = lst2;
	std::cout << "lst4 made" << std::endl;
	return 0;
}
