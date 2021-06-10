#include <list>
#include <iostream>
#include "list.hpp"

void	std_print(std::list<int>& lst){
	std::cout << "---- std::list<int> -----------------------------------" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end();)
		std::cout << *it << ": " << &(*it++) << std::endl;
}

void	ft_print(ft::list<int>& lst){
	std::cout << "---- ft::list<int> ------------------------------------" << std::endl;
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end();)
		std::cout << *it << ": " << &(*it++) << std::endl;
}

int		main()
{
	ft::list<int>::iterator ft_it;
	ft::list<int> ft_lst(3, 5);
	std::list<int>::iterator std_it;
	std::list<int> std_lst(3, 5);
	
	std::cout << "---- lst(3, 5) ------------------------------------" << std::endl;
	std_print(std_lst);
	std::cout << "std_size = " << std_lst.size() << std::endl;
	std::cout << "std_front = " << std_lst.front() << std::endl;
	std::cout << "std_back = " << std_lst.back() << std::endl;

	ft_print(ft_lst);
	std::cout << "ft_size = " << ft_lst.size() << std::endl;
	std::cout << "ft_front = " << ft_lst.front() << std::endl;
	std::cout << "ft_back = " << ft_lst.back() << std::endl;
	
	std::cout << "---- empty() ------------------------------------" << std::endl;
	if (!std_lst.empty())
		std::cout << "std_lst is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	if (!ft_lst.empty())
		std::cout << "ft_lst is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	std::cout << "---- push_back() --------------------------------" << std::endl;
	std_lst.push_back(1);
	std_lst.push_back(2);
	std_lst.push_back(3);
	std_print(std_lst);
	std::cout << "std_lst size = " << std_lst.size() << std::endl;

	ft_lst.push_back(1);
	ft_lst.push_back(2);
	ft_lst.push_back(3);
	ft_print(ft_lst);
	std::cout << "ft_lst size = " << ft_lst.size() << std::endl;

	std::cout << "---- push_front() --------------------------------" << std::endl;
	std_lst.push_front(1);
	std_lst.push_front(2);
	std_lst.push_front(3);
	std_print(std_lst);
	std::cout << "std_lst size = " << std_lst.size() << std::endl;

	ft_lst.push_front(1);
	ft_lst.push_front(2);
	ft_lst.push_front(3);
	ft_print(ft_lst);
	std::cout << "ft_lst size = " << ft_lst.size() << std::endl;

	std::cout << "---- pop_back() --------------------------------" << std::endl;
	std_lst.pop_back();
	std_lst.pop_back();
	std_print(std_lst);
	std::cout << "std_lst size = " << std_lst.size() << std::endl;

	ft_lst.pop_back();
	ft_lst.pop_back();
	ft_print(ft_lst);
	std::cout << "ft_lst size = " << ft_lst.size() << std::endl;

	std::cout << "---- pop_front() --------------------------------" << std::endl;
	std_lst.pop_front();
	std_lst.pop_front();
	std_print(std_lst);
	std::cout << "std_lst size = " << std_lst.size() << std::endl;

	ft_lst.pop_front();
	ft_lst.pop_front();
	ft_print(ft_lst);
	std::cout << "ft_lst size = " << ft_lst.size() << std::endl;

	std::cout << "---- clear() --------------------------------" << std::endl;
	std_lst.clear();
	std::cout << "size = " << std_lst.size() << std::endl;
	
	if (std_lst.empty())
		std::cout << "std_lst is empty\n";
	else
		std::cout << "std_lst is not empty\n";
	
	ft_lst.clear();
	std::cout << "size = " << ft_lst.size() << std::endl;
	
	if (ft_lst.empty())
		std::cout << "ft_lst is empty\n";
	else
		std::cout << "ft_lst is not empty\n";
	
	std::cout << "---- assign(int, int) --------------------------" << std::endl;
	std_lst.assign(3, 5);
	std_print(std_lst);
	
	ft_lst.assign(3, 5);
	ft_print(ft_lst);
	
	std::cout << "---- assign(iterator, iterator) ----------------" << std::endl;
	std::list<int>	std_lst2((unsigned int)3, 6);

	std_print(std_lst2);
	std_lst.assign(std_lst2.begin(), std_lst2.end());
	std_print(std_lst);

	ft::list<int>	ft_lst2((unsigned int)3, 6);

	ft_print(ft_lst2);
	ft_lst.assign(ft_lst2.begin(), ft_lst2.end());
	ft_print(ft_lst);

	std::cout << "---- assign(pointer, pointer) ----------------" << std::endl;
	int		arr[3] = {1, 2, 3};

	std_lst.assign(arr, arr + 2);
	std_print(std_lst);

	ft_lst.assign(arr, arr + 2);
	ft_print(ft_lst);

	std::cout << "---- insert(iterator, int) ----------------------" << std::endl;
	std_it = std_lst.begin();
	std_lst.insert(std_it, 100);
	std_it++;
	std_lst.insert(std_it, 100);
	std_print(std_lst);

	ft_it = ft_lst.begin();
	ft_lst.insert(ft_it, 100);
	ft_it++;
	ft_lst.insert(ft_it, 100);
	ft_print(ft_lst);

	std::cout << "---- insert(iterator, count, value) ------------" << std::endl;
	std_it = std_lst.begin();
	std_lst.insert(std_it, 2, 200);
	std_it++;
	std_lst.insert(std_it, 2, 200);
	std_print(std_lst);

	ft_it = ft_lst.begin();
	ft_lst.insert(ft_it, 2, 200);
	ft_it++;
	ft_lst.insert(ft_it, 2, 200);
	ft_print(ft_lst);

	std::cout << "---- insert(iterator, pointer, pointer) --------" << std::endl;
	std_lst.insert(std_lst.begin(), arr, arr + 2);
	std_print(std_lst);

	ft_lst.insert(ft_lst.begin(), arr, arr + 2);
	ft_print(ft_lst);

	std::cout << "---- insert(iterator, iterator, iterator) ------" << std::endl;
	std_it = ++std_lst.begin();
	std_lst.insert(std_it, std_lst2.begin(), std_lst2.end());
	std_print(std_lst);

	ft_it = ++ft_lst.begin();
	ft_lst.insert(ft_it, ft_lst2.begin(), ft_lst2.end());
	ft_print(ft_lst);

	std::cout << "---- erase(iterator) ----------------------------" << std::endl;
	std_lst.erase(std_it);
	//std_lst.erase(std_it);
	std_print(std_lst);
	
	ft_lst.erase(ft_it);
	//ft_lst.erase(ft_it);
	ft_print(ft_lst);
	
	std::cout << "---- erase(iterator, iterator) -------------------" << std::endl;
	std_it = std_lst.end();
	std_it--;
	std_it--;
	std_lst.erase(std_it, std_lst.end());
	std_print(std_lst);
	
	ft_it = ft_lst.end();
	ft_it--;
	ft_it--;
	ft_lst.erase(ft_it, ft_lst.end());
	ft_print(ft_lst);
	
	std::cout << "---- resize(count) -------------------------------" << std::endl;
	std_lst.resize(std_lst.size() - 2);
	std_print(std_lst);

	ft_lst.resize(ft_lst.size() - 2);
	ft_print(ft_lst);

	std::cout << "---- resize(count, value) ------------------------" << std::endl;
	std_lst2.resize(6, 30);
	std_print(std_lst2);

	ft_lst2.resize(6, 30);
	ft_print(ft_lst2);

	std::cout << "---- swap() --------------------------------------" << std::endl;
	std_print(std_lst);
	std_print(std_lst2);
	std_lst.swap(std_lst2);
	std_print(std_lst);
	std_print(std_lst2);
	std_lst.swap(std_lst2);

	ft_print(ft_lst);
	ft_print(ft_lst2);
	ft_lst.swap(ft_lst2);
	ft_print(ft_lst);
	ft_print(ft_lst2);
	ft_lst.swap(ft_lst2);

	std::cout << "---- remove() ------------------------------------" << std::endl;
	std_lst.remove(100);
	std_print(std_lst);

	ft_lst.remove(100);
	ft_print(ft_lst);

/*
	std::cout << "---- remove_if() ------------------------------------" << std::endl;
	std_lst.remove_if(p);
	std_print(std_lst);

	ft_lst.remove_if(p);
	ft_print(ft_lst);
*/

	std::cout << "---- merge() -------------------------------------" << std::endl;
	std_print(std_lst);
	std_print(std_lst2);
	std_lst.merge(std_lst2);
	std_print(std_lst);
	std_print(std_lst2);

	ft_print(ft_lst);
	ft_print(ft_lst2);
	ft_lst.merge(ft_lst2);
	ft_print(ft_lst);
	ft_print(ft_lst2);

/*
	std::cout << "---- splice(iterator, list) ----------------------" << std::endl;
	std_lst2.push_back(1);
	std_print(std_lst);
	std_print(std_lst2);
	std_lst.splice(std_lst.end(), std_lst2);
	std_print(std_lst);

	ft_lst2.push_back(1);
	ft_print(ft_lst);
	ft_print(ft_lst2);
	ft_lst.splice(ft_lst.end(), ft_lst2);
	ft_print(ft_lst);
*/
/*
	std::cout << "---- splice(iterator, list, iterator) ------------" << std::endl;
	std_lst2.push_back(1);
	std_print(std_lst);
	std_print(std_lst2);
	std_lst.splice(std_lst.end(), std_lst2, std_lst2.begin());
	std_print(std_lst);

	ft_lst2.push_back(1);
	ft_print(ft_lst);
	ft_print(ft_lst2);
	ft_lst.splice(ft_lst.end(), ft_lst2, ft_lst2.begin());
	ft_print(ft_lst);
*/
	
	std::cout << "---- splice(iterator, list, iterator, iterator) --" << std::endl;
	std_lst2.push_back(1);
	std_lst.splice(std_lst.end(), std_lst2, std_lst2.begin(), std_lst2.end());
	std_print(std_lst);

	ft_lst2.push_back(1);
	ft_lst.splice(ft_lst.end(), ft_lst2, ft_lst2.begin(), ft_lst2.end());
	ft_print(ft_lst);

	std::cout << "---- sort() --------------------------------------" << std::endl;
	std_lst.sort();
	std_print(std_lst);

	ft_lst.sort();
	ft_print(ft_lst);

	std::cout << "---- reverse() -----------------------------------" << std::endl;
	std_lst.reverse();
	std_print(std_lst);

	ft_lst.reverse();
	ft_print(ft_lst);

	std::cout << "---- unique() ------------------------------------" << std::endl;
	std_lst.unique();
	std_print(std_lst);

	ft_lst.unique();
	ft_print(ft_lst);

	std::cout << "---- compare -------------------------------------" << std::endl;
	if (std_lst > std_lst2)
		std::cout << "std_lst is bigger\n";
	else if (std_lst < std_lst2)
		std::cout << "std_lst is smaller\n";
	else
		std::cout << "std_lst and std_lst2 is same\n";
	
	if (ft_lst > ft_lst2)
		std::cout << "ft_lst is bigger\n";
	else if (ft_lst < ft_lst2)
		std::cout << "ft_lst is smaller\n";
	else
		std::cout << "ft_lst and ft_lst2 is same\n";
	
	std::cout << "---- compare -------------------------------------" << std::endl;
	std_lst = std_lst2;
	ft_lst = ft_lst2;
	
	if (std_lst > std_lst2)
		std::cout << "std_lst is bigger\n";
	else if (std_lst < std_lst2)
		std::cout << "std_lst is smaller\n";
	else
		std::cout << "std_lst and std_lst2 is same\n";
	
	if (ft_lst > ft_lst2)
		std::cout << "ft_lst is bigger\n";
	else if (ft_lst < ft_lst2)
		std::cout << "ft_lst is smaller\n";
	else
		std::cout << "ft_lst and ft_lst2 is same\n";
	std::cout << "--------------------------------------------------" << std::endl;

	//while (1) ;

	return 0;
}
