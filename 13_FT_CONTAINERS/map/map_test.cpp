#include <map>
#include <vector>
#include "../ft.hpp"
#include "../vector/vector.hpp"
#include "map.hpp"
//#include "map_bfs.hpp"
#include "test_bfs.hpp"
//#include "map_insert.hpp"
//#include "map_delete.hpp"

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
	std::vector<std::pair<int, int> > v;
	v.push_back(std::make_pair(31, 12));
	v.push_back(std::make_pair(15, 14));
	v.push_back(std::make_pair(13, 16));
	v.push_back(std::make_pair(17, 10));
	v.push_back(std::make_pair(21, 1));

	//ft::vector<std::pair<int, int> > ft_v;
	//ft_v.push_back(std::make_pair(11, 12));
	//ft_v.push_back(std::make_pair(13, 14));
	//ft_v.push_back(std::make_pair(15, 16));
	
	std::map<int, int>	std_mi(v.begin(), v.end());
	ft::map<int, int>	ft_mi(v.begin(), v.end());
	
	std_print(std_mi);
	std::cout << "std_size = " << std_mi.size() << std::endl;

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

//	std::cout << "begin = " << ft_m2.begin()->first << std::endl;
//	std::cout << "end = " << ft_m2.end()->first << std::endl;
	
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
	std::pair<ft::map<int, int>::iterator, bool> ft_p;
	std::pair<std::map<int, int>::iterator, bool> std_p;
	
	std_p = std_m.insert(std::make_pair(1, 2));
	std::cout << "std_p : " << std_p.first->first << ", " << std_p.second << std::endl;
	std_p = std_m.insert(std::make_pair(3, 4));
	std::cout << "std_p : " << std_p.first->first << ", " << std_p.second << std::endl;
	std_p = std_m.insert(std::make_pair(3, 4));
	std::cout << "std_p : " << std_p.first->first << ", " << std_p.second << std::endl;
	std_print(std_m);

	ft_p = ft_m.insert(std::make_pair(1, 2));
	std::cout << "ft_p : " << ft_p.first->first << ", " << ft_p.second << std::endl;
	ft_p = ft_m.insert(std::make_pair(3, 4));
	std::cout << "ft_p : " << ft_p.first->first << ", " << ft_p.second << std::endl;
	ft_p = ft_m.insert(std::make_pair(3, 4));
	std::cout << "ft_p : " << ft_p.first->first << ", " << ft_p.second << std::endl;
	ft_print(ft_m);

	std::cout << "---- insert(iterator, value_type) ---------------" << std::endl;
	std_it = std_m.begin();
	std_m.insert(std_it, std::make_pair(5, 6));
	std_m.insert(std_m.end(), std::make_pair(7, 8));
	std_m.insert(++std_it, std::make_pair(9, 10));
	std_print(std_m);

	ft_it = ft_m.begin();
	ft_m.insert(ft_it, std::make_pair(5, 6));
	ft_m.insert(ft_m.end(), std::make_pair(7, 8));
	ft_m.insert(++ft_it, std::make_pair(9, 10));
	ft_print(ft_m);
/*
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
	int		arr[100][2] = {{9, 10}, {11, 12}};

	std_m.insert(arr[0], arr[1]);
	std_print(std_m);

	ft_m.insert(arr[0], arr[1]);
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
	
	std::cout << "---- swap() --------------------------------------" << std::endl;
	std_print(std_m);
	std_print(std_m2);
	std_m.swap(std_m2);
	std_print(std_m);
	std_print(std_m2);
	std_m.swap(std_m2);

	ft_print(ft_m);
	ft_print(ft_m2);
	ft_m.swap(ft_m2);
	ft_print(ft_m);
	ft_print(ft_m2);
	ft_m.swap(ft_m2);

	std::cout << "---- count --------------------------------------" << std::endl;
	
	std::cout << "std_m.count(5) = " << std_m.count(5) << std::endl;
	std::cout << "std_m.count(20) = " << std_m.count(20) << std::endl;

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
	std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ft_itit;

	std_itit = std_m.equal_range(7);
	std::cout << "std_equal_range(7) : " << std_itit.first->second << ", " << std_itit->second->second << std::endl;
	std_itit = std_m.equal_range(200);
	std::cout << "std_equal_range(200) : " << std_itit.first->second << ", " << std_itit->second->second << std::endl;

	ft_itit = ft_m.equal_range(7);
	std::cout << "ft_equal_range(7) : " << ft_itit.first->second << ", " << ft_itit->second->second << std::endl;
	ft_itit = ft_m.equal_range(200);
	std::cout << "ft_equal_range(200) : " << ft_itit.first->second << ", " << ft_itit->second->second << std::endl;

	std::cout << "---- equal_range --------------------------------" << std::endl;
	std::pair<std::map<int, int>::const_iterator, std::map<int, int>::const_iterator> std_itit;
	std::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> ft_itit;

	std_itit = std_m.equal_range(7);
	std::cout << "std_equal_range(7) : " << std_itit.first->second << ", " << std_itit->second->second << std::endl;
	std_itit = std_m.equal_range(200);
	std::cout << "std_equal_range(200) : " << std_itit.first->second << ", " << std_itit->second->second << std::endl;

	ft_itit = ft_m.equal_range(7);
	std::cout << "ft_equal_range(7) : " << ft_itit.first->second << ", " << ft_itit->second->second << std::endl;
	ft_itit = ft_m.equal_range(200);
	std::cout << "ft_equal_range(200) : " << ft_itit.first->second << ", " << ft_itit->second->second << std::endl;

	std::cout << "---- lower_bound --------------------------------" << std::endl;
	
	std_it = std_m.lower_bound(15);
	std::cout << "std_lower_bound(15) : " << std_it->first << ", " << std_it->second << std::endl;
	std_it = std_m.lower_bound(1);
	std::cout << "std_lower_bound(1) : " << std_it->first << ", " << std_it->second << std::endl;

	ft_it = ft_m.lower_bound(15);
	std::cout << "ft_lower_bound(15) : " << ft_it->first << ", " << ft_it->second << std::endl;
	ft_it = ft_m.lower_bound(1);
	std::cout << "ft_lower_bound(1) : " << ft_it->first << ", " << ft_it->second << std::endl;
	
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
	if (ft_m > ft_m2)
		std::cout << "ft_m is bigger\n";
	else if (ft_m < ft_m2)
		std::cout << "ft_m is smaller\n";
	else
		std::cout << "ft_m and ft_m2 is same\n";
	std::cout << "--------------------------------------------------" << std::endl;
*/
	return 0;
}
