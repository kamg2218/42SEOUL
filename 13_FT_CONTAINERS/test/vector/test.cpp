#include <iostream>
#include <vector>
#include "vector.hpp"

int		main(){
	std::vector<int>	std_v;

	std::cout << "std_v = " << sizeof(std_v) << std::endl;
	std::cout << &(*std_v.begin()) << std::endl;
	std::cout << &(*std_v.rbegin()) << std::endl;
	std::cout << &(*std_v.end()) << std::endl;
	std::cout << &(*std_v.rend()) << std::endl;
	std::cout << &(std_v) << std::endl;

	ft::vector<int>		ft_v;

	std::cout << "ft_v = " << sizeof(ft_v) << std::endl;
	std::cout << &(*ft_v.begin()) << std::endl;
	std::cout << &(*ft_v.rbegin()) << std::endl;
	std::cout << &(*ft_v.end()) << std::endl;
	std::cout << &(*ft_v.rend()) << std::endl;
	std::cout << &(ft_v) << std::endl;

	return 0;
}
