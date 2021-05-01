#include <iostream>
#include <list>

int			main(void)
{
	std::allocator<int>	alloc;
	std::list<int>	lst1;
	std::cout << "lst1 made" << std::endl;

	std::cout << "lst1 size = " << lst1.size() << std::endl; 
	std::cout << "head = " << &(*lst1.begin()) << std::endl;
	std::cout << "end = " << &(*lst1.end()) << std::endl;
	std::cout << "empty = " << lst1.empty() << std::endl;

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

	std::cout << "begin = " << &(*lst5.begin()) << std::endl;
	std::cout << "end = " << &(*lst5.end()) << std::endl;
	std::cout << "back = " << &lst5.back() << std::endl;
	lst5.push_back(3);
	std::cout << "begin = " << &(*lst5.begin()) << std::endl;
	std::cout << "end = " << &(*lst5.end()) << std::endl;
	std::cout << "back = " << &lst5.back() << std::endl;
	lst5.push_front(6);
	std::cout << "begin = " << &(*lst5.begin()) << std::endl;
	std::cout << "end = " << &(*lst5.end()) << std::endl;
	std::cout << "back = " << &lst5.back() << std::endl;

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
	lst.push_back(4);
	std::list<int>	lst7;
	lst7.assign(lst.begin(), lst.end());
	std::cout << std::endl;
	
	unsigned int s;
	std::list<int> lst8(3);
	lst8.push_back(5);
	s = lst8.size();
	std::cout << "size = " << lst8.size() << std::endl;
	for (unsigned int i = 0; i < s; i++){
		std::cout << lst8.front() << ", ";
		lst8.pop_front();
	}
	std::cout << std::endl;
	
	std::list<int> lst9(4, 4);
	s = lst9.size();
	std::cout << "size = " << lst9.size() << std::endl;
	for (unsigned int i = 0; i < s; i++){
		std::cout << lst9.front() << ", ";
		lst9.pop_front();
	}
	std::cout << std::endl;
	return 0;
}
