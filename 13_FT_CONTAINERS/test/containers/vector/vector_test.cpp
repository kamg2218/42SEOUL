#include <vector>
#include "vector.hpp"
#include <iostream>

void	std_print(std::vector<int>& v){
	std::cout << "---- std::vector<int> -----------------------------------" << std::endl;
	std::cout << "size = " << v.size() << ", cap = " << v.capacity() << std::endl;
	std::cout << "front = " << v.front() << ", back = " << v.back() << std::endl;
	std::cout << "begin() = " << &(*v.begin()) << ", end() = " << &(*v.end()) << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
		std::cout << *it << ": " << &(*it) << std::endl;
	}
}

void	ft_print(ft::vector<int>& v){
	std::cout << "---- ft::vector<int> ------------------------------------" << std::endl;
	std::cout << "size = " << v.size() << ", cap = " << v.capacity() << std::endl;
	std::cout << "front = " << v.front() << ", back = " << v.back() << std::endl;
	std::cout << "begin() = " << &(*v.begin()) << ", end() = " << &(*v.end()) << std::endl;
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++){
		std::cout << *it << ": " << &(*it) << std::endl;
	}
}

int		main()
{
	ft::vector<int>::iterator ft_it;
	ft::vector<int> ft_v(3, 5);
	std::vector<int>::iterator std_it;
	std::vector<int> std_v(3, 5);
	
	std::cout << "---- v(3, 5) ------------------------------------" << std::endl;
	std_print(std_v);
	std::cout << "std_size = " << std_v.size() << std::endl;
	std::cout << "std_front = " << std_v.front() << std::endl;
	std::cout << "std_back = " << std_v.back() << std::endl;

	ft_print(ft_v);
	std::cout << "ft_size = " << ft_v.size() << std::endl;
	std::cout << "ft_front = " << ft_v.front() << std::endl;
	std::cout << "ft_back = " << ft_v.back() << std::endl;
	
	std::cout << "---- at() ---------------------------------------" << std::endl;
	try{
		std::cout << "std_v.at(0) = " << std_v.at(0) << std::endl;
		std::cout << "std_v.at(2) = " << std_v.at(2) << std::endl;
		std::cout << "std_v.at(-1) = " << std_v.at(-1) << std::endl;
		std::cout << "std_v.at(100) = " << std_v.at(100) << std::endl;
	}
	catch (std::out_of_range& e){
		std::cerr << "Out of Range error: " << e.what() << std::endl;
	}
	try{
		std::cout << "ft_v.at(0) = " << ft_v.at(0) << std::endl;
		std::cout << "ft_v.at(2) = " << ft_v.at(2) << std::endl;
		std::cout << "ft_v.at(-1) = " << ft_v.at(-1) << std::endl;
		std::cout << "ft_v.at(100) = " << ft_v.at(100) << std::endl;
	}
	catch (std::out_of_range& e){
		std::cerr << "Out of Range error: " << e.what() << std::endl;
	}

	std::cout << "---- operator[] ---------------------------------" << std::endl;
	try{
		std::cout << "std_v[0] = " << std_v[0] << std::endl;
		std::cout << "std_v[2] = " << std_v[2] << std::endl;
		std::cout << "std_v[-1] = " << std_v[-1] << std::endl;
		std::cout << "std_v[100] = " << std_v[100] << std::endl;
	}catch (std::out_of_range& e){
		std::cerr << "Out of Range error: " << e.what() << std::endl;
	}
	try{
		std::cout << "ft_v[0] = " << ft_v[0] << std::endl;
		std::cout << "ft_v[2] = " << ft_v[2] << std::endl;
		std::cout << "ft_v[-1] = " << ft_v[-1] << std::endl;
		std::cout << "ft_v[100] = " << ft_v[100] << std::endl;
	}catch (std::out_of_range& e){
		std::cerr << "Out of Range error: " << e.what() << std::endl;
	}

	std::cout << "---- empty() ------------------------------------" << std::endl;
	if (!std_v.empty())
		std::cout << "std_v is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	if (!ft_v.empty())
		std::cout << "ft_v is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	std::cout << "---- push_back() --------------------------------" << std::endl;
	std_v.push_back(1);
	std_v.push_back(2);
	std_v.push_back(3);
	std_print(std_v);
	std::cout << "std_v size = " << std_v.size() << std::endl;

	ft_v.push_back(1);
	ft_v.push_back(2);
	ft_v.push_back(3);
	ft_print(ft_v);
	std::cout << "ft_v size = " << ft_v.size() << std::endl;

	std::cout << "---- pop_back() --------------------------------" << std::endl;
	std_v.pop_back();
	std_v.pop_back();
	std_print(std_v);
	std::cout << "std_v size = " << std_v.size() << std::endl;

	ft_v.pop_back();
	ft_v.pop_back();
	ft_print(ft_v);
	std::cout << "ft_v size = " << ft_v.size() << std::endl;

	std::cout << "---- clear() --------------------------------" << std::endl;
	std_v.clear();
	std::cout << "size = " << std_v.size() << std::endl;
	
	if (std_v.empty())
		std::cout << "std_v is empty\n";
	else
		std::cout << "std_v is not empty\n";
	
	ft_v.clear();
	std::cout << "size = " << ft_v.size() << std::endl;
	
	if (ft_v.empty())
		std::cout << "ft_v is empty\n";
	else
		std::cout << "ft_v is not empty\n";
	
	std::cout << "---- assign(int, int) --------------------------" << std::endl;
	std_v.assign(4, 5);
	std_print(std_v);
	
	ft_v.assign(4, 5);
	ft_print(ft_v);

	std_v.assign(7, 5);
	std_print(std_v);
	
	ft_v.assign(7, 5);
	ft_print(ft_v);

	std::cout << "---- assign(pointer, pointer) ----------------" << std::endl;
	int		arr[2] = {2, 3};

	std_v.assign(arr, arr + 2);
	std_print(std_v);

	ft_v.assign(arr, arr + 2);
	ft_print(ft_v);
	
	std::cout << "---- assign(iterator, iterator) ----------------" << std::endl;
	std::vector<int>	std_v2((unsigned int)3, 6);

	std_print(std_v2);
	std_v.assign(std_v2.begin(), std_v2.end());
	std_print(std_v);

	ft::vector<int>		ft_v2((unsigned int)3, 6);

	ft_print(ft_v2);
	ft_v.assign(ft_v2.begin(), ft_v2.end());
	ft_print(ft_v);

	std::cout << "---- insert(iterator, int) ----------------------" << std::endl;
	std_it = std_v.begin();
	std_v.insert(std_it, 100);
	std_it = std_v.begin();
	std_v.insert(std_it, 150);
	std_print(std_v);

	ft_it = ft_v.begin();
	ft_v.insert(ft_it, 100);
	ft_it = ft_v.begin();
	ft_v.insert(ft_it, 150);
	ft_print(ft_v);

	std_v.insert(std_v.end(), 10);
	std_v.insert(std_v.end(), 15);
	std_print(std_v);

	ft_v.insert(ft_v.end(), 10);
	ft_v.insert(ft_v.end(), 15);
	ft_print(ft_v);

	std::cout << "---- insert(iterator, count, value) ------------" << std::endl;
	std_it = std_v.begin();
	std_v.insert(std_it, 10, 200);
	std_print(std_v);
	std_it = std_v.end();
	std_v.insert(std_it, 10, 250);
	std_print(std_v);

	ft_it = ft_v.begin();
	ft_v.insert(ft_it, 10, 200);
	ft_print(ft_v);
	ft_it = ft_v.end();
	ft_v.insert(ft_it, 10, 250);
	ft_print(ft_v);

	std::cout << "---- insert(iterator, iterator, iterator) ------" << std::endl;
	std::vector<int>	std_v3;

	std_v3.push_back(1);
	std_v3.push_back(2);
	std_v3.push_back(4);
	std_it = ++std_v.begin();
	std_v.insert(std_it, std_v3.begin(), std_v3.end());
	std_print(std_v);

	ft::vector<int>	ft_v3;

	ft_v3.push_back(1);
	ft_v3.push_back(2);
	ft_v3.push_back(4);
	ft_it = ++ft_v.begin();
	ft_v.insert(ft_it, ft_v3.begin(), ft_v3.end());
	ft_print(ft_v);

	std::cout << "---- insert(iterator, pointer, pointer) ------" << std::endl;
	std_v.insert(std_v.begin(), arr, arr + 2);
	std_print(std_v);

	ft_v.insert(ft_v.begin(), arr, arr + 2);
	ft_print(ft_v);

	std::cout << "---- erase(iterator) ----------------------------" << std::endl;
	std_v.erase(std_v.begin());
	//std_v.erase(std_it);
	std_print(std_v);
	
	ft_v.erase(ft_v.begin());
	//ft_v.erase(ft_it);
	ft_print(ft_v);
	
	std::cout << "---- erase(iterator, iterator) -------------------" << std::endl;
	std_it = std_v.end();
	std_it--;
	std_it--;
	std_v.erase(std_it, std_v.end());
	std_print(std_v);
	
	ft_it = ft_v.end();
	ft_it--;
	ft_it--;
	ft_v.erase(ft_it, ft_v.end());
	ft_print(ft_v);
	
	std::cout << "---- resize(count, value) ------------------------" << std::endl;
	std_print(std_v2);
	std_v2.resize((unsigned int)6, 30);
	std_print(std_v2);

	ft_print(ft_v2);
	ft_v2.resize((unsigned int)6, 30);
	ft_print(ft_v2);

	std::cout << "---- swap() --------------------------------------" << std::endl;
	std_print(std_v);
	std_print(std_v2);
	std_v.swap(std_v2);
	std_print(std_v);
	std_print(std_v2);
	std_v.swap(std_v2);

	ft_print(ft_v);
	ft_print(ft_v2);
	ft_v.swap(ft_v2);
	ft_print(ft_v);
	ft_print(ft_v2);
	ft_v.swap(ft_v2);

	std::cout << "---- compare -------------------------------------" << std::endl;
	if (std_v > std_v2)
		std::cout << "std_v is bigger\n";
	else if (std_v < std_v2)
		std::cout << "std_v is smaller\n";
	else
		std::cout << "std_v and std_v2 are same\n";
	
	if (ft_v > ft_v2)
		std::cout << "ft_v is bigger\n";
	else if (ft_v < ft_v2)
		std::cout << "ft_v is smaller\n";
	else
		std::cout << "ft_v and ft_v2 are same\n";
	std::cout << "---- compare -------------------------------------" << std::endl;
	std_v2 = std_v;
	if (std_v > std_v2)
		std::cout << "std_v is bigger\n";
	else if (std_v < std_v2)
		std::cout << "std_v is smaller\n";
	else
		std::cout << "std_v and std_v2 are same\n";

	ft_v2 = ft_v;
	//ft_print(ft_v);
	//ft_print(ft_v2);
	if (ft_v > ft_v2)
		std::cout << "ft_v is bigger\n";
	else if (ft_v < ft_v2)
		std::cout << "ft_v is smaller\n";
	else
		std::cout << "ft_v and ft_v2 are same\n";
	std::cout << "--------------------------------------------------" << std::endl;
	ft::vector<int>::const_iterator ft_cit;
	std::vector<int>::const_iterator std_cit;
	
	std_cit = std_v.begin();
	std::cout << "std_cit = " << *std_cit << std::endl;
	std_cit++;
	std::cout << "std_cit = " << *std_cit << std::endl;

	ft_cit = ft_v.begin();
	std::cout << "ft_cit = " << *ft_cit << std::endl;
	ft_cit++;
	std::cout << "ft_cit = " << *ft_cit << std::endl;
	
	std::cout << "--------------------------------------------------" << std::endl;
	
	//while (1);

	return 0;
}
