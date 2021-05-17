#include <iostream>
#include <list>
#include <vector>
#include "../ft.hpp"

int		main(){
	ft::list<int>	ft_lst;
	ft::list<int>::iterator	ft_it;

	std::list<int>	std_lst;
	std::list<int>::iterator	std_it;
	
	std::cout << "ft_lst = " << sizeof(ft_lst) << ", ft_it = " << sizeof(ft_it) << std::endl;
	std::cout << &(*ft_lst.end()) << std::endl;
	std::cout << &(*ft_lst.rend()) << std::endl;
	std::cout << &(ft_lst) << std::endl;

	std::cout << "std_lst = " << sizeof(std_lst) << ", std_it = " << sizeof(std_it) << std::endl;
	std::cout << &(*std_lst.end()) << std::endl;
	std::cout << &(*std_lst.rend()) << std::endl;
	std::cout << &(std_lst) << std::endl;

	std::vector<int>	std_v;

	std::cout << "std_v = " << sizeof(std_v) << std::endl;
	std::cout << &(*std_v.end()) << std::endl;
	std::cout << &(*std_v.rend()) << std::endl;
	std::cout << &(std_v) << std::endl;

	ft::vector<int>		ft_v;

	std::cout << "ft_v = " << sizeof(ft_v) << std::endl;
	std::cout << &(*ft_v.end()) << std::endl;
	std::cout << &(*ft_v.rend()) << std::endl;
	std::cout << &(ft_v) << std::endl;


	return 0;
}
