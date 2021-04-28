#include <iostream>
#include <list>

int			main(void)
{
	std::allocator<int>	alloc;
	std::list<int>	lst1;
	std::cout << "lst1 made" << std::endl;

	std::list<int>	lst2(alloc);
	std::cout << "lst2 made" << std::endl;

	std::list<int>	lst3(lst2);
	std::cout << "lst3 made" << std::endl;
	
	std::list<int>	lst4 = lst2;
	std::cout << "lst4 made" << std::endl;
	
	std::cout << "arr[5]\n";
	int		arr[5] = {1, 2, 3, 4, 5};
	std::list<int>	lst5(arr, arr+5);
	std::cout << std::endl;

	std::cout << "num, size\n";
	std::list<int>	lst6;
	int		num = 5;
	size_t	size = 3;
	lst6.assign(size, num);
	std::cout << std::endl;
	
	std::cout << "3, 4\n";
	lst6.assign(3, 4);
	std::cout << std::endl;
	
	std::cout << "num, num\n";
	lst6.assign(num, num);
	std::cout << std::endl;

	std::cout << "arr pointer\n";
	lst6.assign(arr, arr + 5);
	std::cout << std::endl;
	
	std::cout << "lst iterator\n";
	std::list<int>	lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(10);
	std::cout << "begin = " << &(*lst.begin()) << ", " << *lst.begin() << std::endl;
	std::cout << "end = " << &(*lst.end()) << ", " << *lst.end() << std::endl;
	lst.insert(lst.begin(), 3);
	std::cout << "begin = " << &(*lst.begin()) << ", " << *lst.begin() << std::endl;
	std::cout << "end = " << &(*lst.end()) << ", " << *lst.end() << std::endl;
	std::cout << "rbegin = " << &(*lst.rbegin()) << ", " << *lst.rbegin() << std::endl;
	std::cout << "rend = " << &(*lst.rend()) << ", " << *lst.rend() << std::endl;
	
	lst.insert(lst.begin(), 42);
	lst.insert(lst.begin(), 42);
	std::cout << "begin = " << &(*lst.begin()) << ", " << *lst.begin() << std::endl;
	std::cout << "end = " << &(*lst.end()) << ", " << *lst.end() << std::endl;
	while (!lst.empty()){
		std::cout << "lst = " << &(*lst.begin()) << ", " << *lst.begin() << std::endl;
		lst.pop_front();
	}
	std::cout << "lst = " << &(*lst.begin()) << ", " << *lst.begin() << std::endl;
	
	return 0;
}
