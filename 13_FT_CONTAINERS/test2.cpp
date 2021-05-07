#include <iostream>
#include <list>
#include "ft.hpp"

void		print(std::list<int>& lst){
	std::list<int>::iterator	tmp;

	tmp = lst.begin();
	while (tmp != lst.end()){
		std::cout << *tmp << ", " << &(*tmp) << std::endl;
		tmp++;
	}
}

void		ft_print(ft::list<int>& lst){
	ft::list<int>::iterator	tmp;

	tmp = lst.begin();
	while (tmp != lst.end()){
		std::cout << *tmp << ", " << &(*tmp) << std::endl;
		tmp++;
	}
}

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
	int		arr[5] = {5, 4, 3, 2, 1};
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

	print(lst5);
	std::cout << std::endl;
	lst5.sort();
	print(lst5);

	std::cout << "num, size\n";
	std::list<int>	lst6;
	int		num = 7;
	size_t	size = 3;
	lst6.assign(size, num);
	print(lst6);
	std::cout << std::endl;
	
	std::cout << "3, 4\n";
	lst6.assign(3, 4);
	print(lst6);
	std::cout << std::endl;
	
	std::cout << "num, num\n";
	lst6.assign((int)3, num);
	print(lst6);
	std::cout << std::endl;

	std::cout << "arr pointer\n";
	lst6.assign(arr, arr + 5);
	print(lst6);
	std::cout << std::endl;
	lst6.remove(3);
	print(lst6);
	std::cout << std::endl;
	lst6.insert(lst6.begin()++, 3);
	print(lst6);
	std::cout << std::endl;
	lst6.push_back(1);
	lst6.push_back(3);
	lst6.push_front(3);
	print(lst6);
	std::cout << std::endl;
	lst6.unique();
	print(lst6);
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
/*
	std::cout << "-----------------\n";
	ft::list<int>	ft_lst;
	ft_lst.assign(size, num);
	ft_print(ft_lst);
	std::cout << std::endl;
	
	std::cout << "3, 4\n";
	ft_lst.assign(3, 4);
	ft_print(ft_lst);
	std::cout << std::endl;
	
	std::cout << "num, num\n";
	ft_lst.assign((int)3, num);
	ft_print(ft_lst);
	std::cout << std::endl;

	std::cout << "arr pointer\n";
	ft_lst.assign(arr, arr + 5);
	ft_print(ft_lst);
	std::cout << std::endl;
	
	ft::list<int>	ft_lst2(3, 5);
	ft_print(ft_lst2);
	std::cout << std::endl;
	
	ft::list<int>	ft_lst3((unsigned int)3, 5);
	ft_print(ft_lst3);
	std::cout << std::endl;
*/
	/*
	std::cout << "-----------------\n";
	
	std::list<int>	lst_2(7, 5);
	print(lst_2);
	std::cout << std::endl;
	
	std::list<int>	lst_3((unsigned int)7, 5);
	print(lst_3);
	std::cout << std::endl;

	lst_2.resize(5);
	print(lst_2);
	std::cout << std::endl;

	//lst_2.push_back(1);
	//lst_2.push_back(2);
	lst_2.resize(7, 4);
	print(lst_2);
	std::cout << std::endl;

	lst_2.swap(lst_3);
	print(lst_2);
	std::cout << std::endl;
	
	print(lst_3);
*/
	return 0;
}
