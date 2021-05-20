#include <iostream>
#include <map>
#include <vector>
//#include "../ft.hpp"

int		main(){
	//ft::map<int>	ft_m;
	//ft::map<int>::iterator	ft_it;
	//char	arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<std::pair<int, int> > v;
	v.push_back(std::make_pair(2, 10));
	v.push_back(std::make_pair(3, 30));
	v.push_back(std::make_pair(1, 20));
	std::map<int, int>	std_m(v.begin(), v.end());
	
	/*
	std::cout << "ft_lst = " << sizeof(ft_lst) << ", ft_it = " << sizeof(ft_it) << std::endl;
	std::cout << &(*ft_lst.end()) << std::endl;
	std::cout << &(*ft_lst.rend()) << std::endl;
	std::cout << &(ft_lst) << std::endl;
	*/
	std::cout << "std_m = " << sizeof(std_m) << std::endl;
	std::cout << &(*std_m.end()) << std::endl;
	std::cout << &(std_m) << std::endl;

	//std_m.insert(std::make_pair(1, 10));
	//std_m.insert(std::make_pair(1, 30));
	//std_m.insert(std::make_pair(2, 20));

	std::cout << "std_m = " << sizeof(std_m) << std::endl;
	std::cout << &(*std_m.begin()) << std::endl;
	std::cout << &(*std_m.end()) << std::endl;
	std::cout << &(std_m) << std::endl;
	
	std::cout << "size = " << std_m.size() << std::endl;
	for (std::map<int, int>::iterator it = std_m.begin(); it != std_m.end(); it++)
		std::cout << "it = " << it->first << ", " << it->second << ", " << &(*it) << std::endl;

	std::cout << "map[2] = " << std_m[2] << std::endl;
	std::cout << "map[6] = " << std_m[6] << std::endl;
	std::cout << "map[4] = " << std_m[4] << std::endl;
	std::cout << "size = " << std_m.size() << std::endl;
	for (std::map<int, int>::iterator it = std_m.begin(); it != std_m.end(); it++)
		std::cout << "it = " << it->first << ", " << it->second << ", " << &(*it) << std::endl;

	return 0;
}
