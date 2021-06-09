#include <iostream>
#include <map>
#include <vector>
#include "../vector/vector.hpp"
#include "map.hpp"

int		main(){
	std::vector<std::pair<int, int> > v;
	v.push_back(std::make_pair(2, 10));
	v.push_back(std::make_pair(3, 30));
	v.push_back(std::make_pair(2, 20));
	ft::vector<ft::pair<int, int> > ft_v;
	ft_v.push_back(ft::make_pair(2, 10));
	ft_v.push_back(ft::make_pair(3, 30));
	ft_v.push_back(ft::make_pair(2, 20));
	std::map<int, int>	std_m;
	ft::map<int, int>	ft_m;
	
	std::cout << "std_m = " << sizeof(std_m) << std::endl;
	std::cout << "std_size = " << std_m.size() << std::endl;
	std::cout << &(*std_m.end()) << std::endl;
	std::cout << &(*std_m.begin()) << std::endl;
	std::cout << &(std_m) << std::endl;
	
	std::cout << "ft_m = " << sizeof(ft_m) << std::endl;
	std::cout << "ft_size = " << ft_m.size() << std::endl;
	std::cout << &(*ft_m.end()) << std::endl;
	std::cout << &(*ft_m.begin()) << std::endl;
	std::cout << &(ft_m) << std::endl;

	std_m.insert(v.begin(), v.end());
	ft_m.insert(ft_v.begin(), ft_v.end());
	
	std::cout << "std_m = " << sizeof(std_m) << std::endl;
	std::cout << "std_size = " << std_m.size() << std::endl;
	std::cout << &(*std_m.end()) << std::endl;
	std::cout << &(*std_m.begin()) << std::endl;
	std::cout << &(std_m) << std::endl;
	
	std::cout << "ft_m = " << sizeof(ft_m) << std::endl;
	std::cout << "ft_size = " << ft_m.size() << std::endl;
	std::cout << &(*ft_m.end()) << std::endl;
	std::cout << &(*ft_m.begin()) << std::endl;
	std::cout << &(ft_m) << std::endl;

	return 0;
}
