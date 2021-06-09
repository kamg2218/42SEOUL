#include <map>
#include <vector>
#include "../vector/vector.hpp"
#include "map.hpp"
#include <iostream>

void	std_print(std::map<int, int>& m){
	std::cout << "---- std::map<int, int> -------------------------" << std::endl;
	std::map<int, int>::iterator	it;
	for (it = m.begin(); it != m.end(); it++)
		std::cout << it->first << ", " << it->second << std::endl;
}

void	ft_print(ft::map<int, int>& m){
	std::cout << "---- ft::map<int, int> --------------------------" << std::endl;
	ft::map<int, int>::iterator		it;
	
	for (it = m.begin(); it != m.end(); ++it)
		std::cout << it->first << ", " << it->second << std::endl;
}

int		main()
{
	ft::map<int, int>::iterator ft_it;
	ft::map<int, int> ft_m;
	std::map<int, int>::iterator std_it;
	std::map<int, int> std_m;
	
	std::cout << "---- m() ----------------------------------------" << std::endl;
	std_print(std_m);
	std::cout << "std_size = " << std_m.size() << std::endl;

	ft_print(ft_m);
	std::cout << "ft_size = " << ft_m.size() << std::endl;
	
	std::cout << "---- m(iterator, iterator) ----------------------------------------" << std::endl;
	std::vector<std::pair<int, int> > std_v;
	std_v.push_back(std::make_pair(31, 12));
	std_v.push_back(std::make_pair(15, 14));
	std_v.push_back(std::make_pair(13, 16));
	std_v.push_back(std::make_pair(17, 10));
	std_v.push_back(std::make_pair(21, 1));

	ft::vector<ft::pair<int, int> > v;
	v.push_back(ft::make_pair(31, 12));
	v.push_back(ft::make_pair(15, 14));
	v.push_back(ft::make_pair(13, 16));
	v.push_back(ft::make_pair(17, 10));
	v.push_back(ft::make_pair(21, 1));

	std::map<int, int>	std_mi(std_v.begin(), std_v.end());
	
	std_print(std_mi);
	std::cout << "std_size = " << std_mi.size() << std::endl;

	ft::map<int, int>	ft_mi(v.begin(), v.end());
	
	ft_print(ft_mi);
	std::cout << "ft_size = " << ft_mi.size() << std::endl;

	std::cout << "---- m[3] = 50 ----------------------------------" << std::endl;
	std_m[3] = 50;
	std_m[5] = 100;
	std_print(std_m);
	std::cout << "std_size = " << std_m.size() << std::endl;

	ft_m[3] = 50;
	ft_m[5] = 100;
	ft_print(ft_m);
	std::cout << "ft_size = " << ft_m.size() << std::endl;
	
	std_mi[3] = 50;
	std_mi[5] = 100;
	std_print(std_mi);
	std::cout << "std_i_size = " << std_mi.size() << std::endl;

	ft_mi[3] = 50;
	ft_mi[5] = 100;
	ft_print(ft_mi);
	std::cout << "ft_i_size = " << ft_mi.size() << std::endl;
	
	std::cout << "---- 3 to end -----------------------------------" << std::endl;
	
	std::map<int, int> std_m2(std_m.find(3), std_m.end());
	ft::map<int, int> ft_m2(ft_m.find(3), ft_m.end());
	
	std_print(std_m2);
	std::cout << "std2_size = " << std_m2.size() << std::endl;

	ft_print(ft_m2);
	std::cout << "ft2_size = " << ft_m2.size() << std::endl;
	
	std::cout << "---- copy ---------------------------------------" << std::endl;
	
	std::map<int, int> std_m3(std_m);
	ft::map<int, int> ft_m3(ft_m);
	
	std_print(std_m3);
	std::cout << "std3_size = " << std_m3.size() << std::endl;

	ft_print(ft_m3);
	std::cout << "ft3_size = " << ft_m3.size() << std::endl;

	std::cout << "---- empty() ------------------------------------" << std::endl;
	if (!std_m.empty())
		std::cout << "std_m is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	if (!ft_m.empty())
		std::cout << "ft_m is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	std::cout << "---- clear() --------------------------------" << std::endl;
	std_m.clear();
	std::cout << "size = " << std_m.size() << std::endl;
	
	if (std_m.empty())
		std::cout << "std_m is empty\n";
	else
		std::cout << "std_m is not empty\n";
	
	ft_m.clear();
	std::cout << "size = " << ft_m.size() << std::endl;
	
	if (ft_m.empty())
		std::cout << "ft_m is empty\n";
	else
		std::cout << "ft_m is not empty\n";

	std::cout << "---- insert(value_type) -------------------------" << std::endl;
	ft::pair<ft::map<int, int>::iterator, bool> ft_p;
	std::pair<std::map<int, int>::iterator, bool> std_p;
	
	std_p = std_m.insert(std::make_pair(1, 2));
	std::cout << "std_p : " << std_p.first->first << ", " << std_p.second << std::endl;
	std_p = std_m.insert(std::make_pair(3, 4));
	std::cout << "std_p : " << std_p.first->first << ", " << std_p.second << std::endl;
	std_p = std_m.insert(std::make_pair(3, 4));
	std::cout << "std_p : " << std_p.first->first << ", " << std_p.second << std::endl;
	std_print(std_m);

	ft_p = ft_m.insert(ft::make_pair(1, 2));
	std::cout << "ft_p : " << ft_p.first->first << ", " << ft_p.second << std::endl;
	ft_p = ft_m.insert(ft::make_pair(3, 4));
	std::cout << "ft_p : " << ft_p.first->first << ", " << ft_p.second << std::endl;
	ft_p = ft_m.insert(ft::make_pair(3, 4));
	std::cout << "ft_p : " << ft_p.first->first << ", " << ft_p.second << std::endl;
	ft_print(ft_m);

	std::cout << "---- insert(iterator, value_type) ---------------" << std::endl;
	std_it = std_m.begin();
	std_m.insert(std_it, std::make_pair(5, 6));
	std_m.insert(std_m.end(), std::make_pair(7, 8));
	std_m.insert(++std_it, std::make_pair(9, 10));
	std_print(std_m);

	ft_it = ft_m.begin();
	ft_m.insert(ft_it, ft::make_pair(5, 6));
	ft_m.insert(ft_m.end(), ft::make_pair(7, 8));
	ft_m.insert(++ft_it, ft::make_pair(9, 10));
	ft_print(ft_m);

	std::cout << "---- insert(iterator, iterator) -----------------" << std::endl;
	std_it = std_m2.begin();
	std_it++;
	std_m.insert(std_it, std_m2.end());
	std_print(std_m);

	ft_it = ft_m2.begin();
	ft_it++;
	ft_m.insert(ft_it, ft_m2.end());
	ft_print(ft_m);

	std::cout << "---- insert(pointer, pointer) -------------------" << std::endl;
	std::pair<int, int>	arr[2] = {std::make_pair(9, 10), std::make_pair(11, 12)};
	ft::pair<int, int>	ft_arr[2] = {ft::make_pair(9, 10), ft::make_pair(11, 12)};

	std_m.insert(arr, arr + 1);
	std_print(std_m);

	ft_m.insert(ft_arr, ft_arr + 1);
	ft_print(ft_m);

	std::cout << "---- erase(key_type) ----------------------------" << std::endl;
	std::cout << "std_erase = " << std_m.erase(3) << std::endl;
	std::cout << "std_erase = " << std_m.erase(10) << std::endl;
	std::cout << "std_erase = " << std_m.erase(100) << std::endl;
	std_print(std_m);
	
	std::cout << "ft_erase = " << ft_m.erase(3) << std::endl;
	std::cout << "ft_erase = " << ft_m.erase(10) << std::endl;
	std::cout << "ft_erase = " << ft_m.erase(100) << std::endl;
	ft_print(ft_m);
	
	std::cout << "---- erase(iterator) ----------------------------" << std::endl;
	std_it = std_m.begin();
	std_it++;
	std_m.erase(std_it);
	std_print(std_m);
	
	ft_it = ft_m.begin();
	ft_it++;
	ft_m.erase(ft_it);
	ft_print(ft_m);
	
	std::cout << "---- erase(iterator, iterator) -------------------" << std::endl;
	std_it = std_m.end();
	std_it--;
	std_it--;
	std_m.erase(std_it, std_m.end());
	std_print(std_m);
	
	ft_it = ft_m.end();
	ft_it--;
	ft_it--;
	ft_m.erase(ft_it, ft_m.end());
	ft_print(ft_m);


	std::cout << "---- erase(iterator, iterator) -------------------" << std::endl;
	std_m.erase(std_m.begin(), std_m.end());
	std_print(std_m);
	
	ft_m.erase(ft_m.begin(), ft_m.end());
	ft_print(ft_m);

	std::cout << "---- swap() --------------------------------------" << std::endl;
	std_m.insert(std::make_pair(5, 6));
	std_m.insert(std::make_pair(7, 8));
	
	std_print(std_m);
	std_print(std_m2);
	std_m.swap(std_m2);
	std_print(std_m);
	std_print(std_m2);
	std_m.swap(std_m2);

	ft_m.insert(ft::make_pair(5, 6));
	ft_m.insert(ft::make_pair(7, 8));
	
	ft_print(ft_m);
	ft_print(ft_m2);
	ft_m.swap(ft_m2);
	ft_print(ft_m);
	ft_print(ft_m2);
	ft_m.swap(ft_m2);

	std::cout << "---- count --------------------------------------" << std::endl;
	std_m.insert(std::make_pair(5, 6));
	std_m.insert(std::make_pair(7, 8));
	ft_m.insert(ft::make_pair(5, 6));
	ft_m.insert(ft::make_pair(7, 8));
	
	std::cout << "std_m.count(1) = " << std_m.count(1) << std::endl;
	std::cout << "std_m.count(5) = " << std_m.count(5) << std::endl;
	std::cout << "std_m.count(20) = " << std_m.count(20) << std::endl;

	std::cout << "ft_m.count(1) = " << ft_m.count(1) << std::endl;
	std::cout << "ft_m.count(5) = " << ft_m.count(5) << std::endl;
	std::cout << "ft_m.count(20) = " << ft_m.count(20) << std::endl;
	
	std::cout << "---- find ---------------------------------------" << std::endl;
	
	std_it = std_m.find(5);
	std::cout << "std_m.find(5) = " << std_it->first << ", " << std_it->second << std::endl;
	std_it = std_m.find(20);
	std::cout << "std_m.find(20) = " << std_it->first << ", " << std_it->second << std::endl;

	ft_it = ft_m.find(5);
	std::cout << "ft_m.find(5) = " << ft_it->first << ", " << ft_it->second << std::endl;
	ft_it = ft_m.find(20);
	std::cout << "ft_m.find(20) = " << ft_it->first << ", " << ft_it->second << std::endl;
	
	std::cout << "---- find ---------------------------------------" << std::endl;
	std::map<int, int>::const_iterator	std_cit;
	ft::map<int, int>::const_iterator	ft_cit;

	std_cit = std_m.find(5);
	std::cout << "std_m.find(5) = " << std_cit->first << ", " << std_cit->second << std::endl;
	std_cit = std_m.find(20);
	std::cout << "std_m.find(20) = " << std_cit->first << ", " << std_cit->second << std::endl;

	ft_cit = ft_m.find(5);
	std::cout << "ft_m.find(5) = " << ft_cit->first << ", " << ft_cit->second << std::endl;
	ft_cit = ft_m.find(20);
	std::cout << "ft_m.find(20) = " << ft_cit->first << ", " << ft_cit->second << std::endl;
	
	std::cout << "---- equal_range --------------------------------" << std::endl;
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> std_itit;
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ft_itit;

	std_itit = std_m.equal_range(7);
	std::cout << "std_equal_range(7) : " << std_itit.first->first << ", " << std_itit.second->first << std::endl;
	std_itit = std_m.equal_range(200);
	std::cout << "std_equal_range(200) : " << std_itit.first->first << ", " << std_itit.second->first << std::endl;

	ft_itit = ft_m.equal_range(7);
	std::cout << "ft_equal_range(7) : " << ft_itit.first->first << ", " << ft_itit.second->first << std::endl;
	ft_itit = ft_m.equal_range(200);
	std::cout << "ft_equal_range(200) : " << ft_itit.first->first << ", " << ft_itit.second->first << std::endl;

	std::cout << "---- equal_range --------------------------------" << std::endl;
	std::pair<std::map<int, int>::const_iterator, std::map<int, int>::const_iterator> std_citit;
	ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> ft_citit;

	std_citit = std_m.equal_range(7);
	std::cout << "std_equal_range(7) : " << std_citit.first->first << ", " << std_citit.second->first << std::endl;
	std_citit = std_m.equal_range(200);
	std::cout << "std_equal_range(200) : " << std_citit.first->first << ", " << std_citit.second->first << std::endl;


	ft_citit = ft_m.equal_range(7);
	std::cout << "ft_equal_range(7) : " << ft_citit.first->first << ", " << ft_citit.second->first << std::endl;
	ft_citit = ft_m.equal_range(200);
	std::cout << "ft_equal_range(200) : " << ft_citit.first->first << ", " << ft_citit.second->first << std::endl;

	std::cout << "---- lower_bound --------------------------------" << std::endl;

	std_it = std_m.lower_bound(15);
	std::cout << "std_lower_bound(15) : " << std_it->first << ", " << std_it->second << std::endl;
	std_it = std_m.lower_bound(1);
	std::cout << "std_lower_bound(1) : " << std_it->first << ", " << std_it->second << std::endl;
	std_it = std_m.lower_bound(6);
	std::cout << "std_lower_bound(6) : " << std_it->first << ", " << std_it->second << std::endl;

	ft_it = ft_m.lower_bound(15);
	std::cout << "ft_lower_bound(15) : " << ft_it->first << ", " << ft_it->second << std::endl;
	ft_it = ft_m.lower_bound(1);
	std::cout << "ft_lower_bound(1) : " << ft_it->first << ", " << ft_it->second << std::endl;
	ft_it = ft_m.lower_bound(6);
	std::cout << "ft_lower_bound(6) : " << ft_it->first << ", " << ft_it->second << std::endl;

	std::cout << "---- upper_bound --------------------------------" << std::endl;
	
	std_it = std_m.upper_bound(15);
	std::cout << "std_upper_bound(15) : " << std_it->first << ", " << std_it->second << std::endl;
	std_it = std_m.upper_bound(1);
	std::cout << "std_upper_bound(1) : " << std_it->first << ", " << std_it->second << std::endl;

	ft_it = ft_m.upper_bound(15);
	std::cout << "ft_upper_bound(15) : " << ft_it->first << ", " << ft_it->second << std::endl;
	ft_it = ft_m.upper_bound(1);
	std::cout << "ft_upper_bound(1) : " << ft_it->first << ", " << ft_it->second << std::endl;
	
	std::cout << "---- compare -------------------------------------" << std::endl;

	if (std_m > std_m2)
		std::cout << "std_m is bigger\n";
	else if (std_m < std_m2)
		std::cout << "std_m is smaller\n";
	else
		std::cout << "std_m and std_m2 is same\n";
	
	if (ft_m > ft_m2)
		std::cout << "ft_m is bigger\n";
	else if (ft_m < ft_m2)
		std::cout << "ft_m is smaller\n";
	else
		std::cout << "ft_m and ft_m2 is same\n";
	
	std::cout << "--------------------------------------------------" << std::endl;

	return 0;
}
