#include "ft.hpp"
#include <list>

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
	
	std::cout << "arr[5]\n";
	int		arr[5] = {1, 2, 3, 4, 5};
	ft::list<int>	lst5(arr, arr+5);
	for (int i = 0; i < 5; i++)
		std::cout << lst5.head[i];
	std::cout << std::endl;

	std::cout << "num, size\n";
	ft::list<int>	lst6;
	int		num = 5;
	size_t	size = 3;
	lst6.assign(size, num);
	for (int i = 0; i < lst6.size; i++)
		std::cout << lst6.head[i];
	std::cout << std::endl;
	
	std::cout << "3, 4\n";
	lst6.assign(3, 4);
	for (int i = 0; i < lst6.size; i++)
		std::cout << lst6.head[i];
	std::cout << std::endl;
	
	std::cout << "num, num\n";
	lst6.assign(num, num);
	for (int i = 0; i < lst6.size; i++)
		std::cout << lst6.head[i];
	std::cout << std::endl;

	std::cout << "arr pointer\n";
	lst6.assign(arr, arr + 5);
	for (int i = 0; i < lst6.size; i++)
		std::cout << lst6.head[i];
	std::cout << std::endl;
	
	std::cout << "lst iterator\n";
	std::list<int>	lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	ft::list<int>	lst7;
	lst7.assign(lst.begin(), lst.end());
	for (int i = 0; i < lst7.size; i++)
		std::cout << lst7.head[i];
	std::cout << std::endl;
	return 0;
}
