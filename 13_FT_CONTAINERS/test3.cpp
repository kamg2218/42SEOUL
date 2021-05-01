#include "ft.hpp"
#include "iterator.hpp"
#include <list>
#include <iostream>

int		main()
{
	std::list<int> vt;
	vt.push_back(3);
	vt.push_back(4);
	vt.push_back(5);
	vt.push_back(6);
	Iterator<int>	it;// = vt.begin();
	ft::list<int> lst;
	
	//lst.assign((int)3, (int)5);
	std::cout << "size = " << lst.size() << std::endl;
	//for (int i = 0; i < lst.size(); i++)
	//	std::cout << "i = " << lst.head[i] << "\n";
	if (!lst.empty())
		std::cout << "front = " << lst.front() << std::endl;
	else
		std::cout << "It's empty\n";
	//std::cout << lst.end();

	std::list<int>::iterator	itr = vt.begin();
	std::cout << "*begin = " << *(vt.begin()) << std::endl;
	
	std::cout << "*begin = " << *(lst.begin()) << std::endl;

	it = lst.begin();

	std::cout << *it;
	
	if (*(vt.begin()) == *it)
		std::cout << "Same\n";

	std::list<int>::reverse_iterator	r_it = vt.rbegin();
	for (size_t i = 0; i < vt.size(); i++){
		std::cout << *r_it << " -> " << &(*r_it) << std::endl;
		++r_it;
	}
	std::cout << std::endl;

	std::list<int>::iterator	c_it = vt.begin();
	for (size_t i = 0; i < vt.size(); i++) {
		std::cout << *c_it << " -> " << &(*c_it) << std::endl;
		++c_it;
	}
	std::cout << std::endl;

	ft::list<int>::reverse_iterator fr_it = lst.rbegin();
	std::cout << "rend = " << &(*lst.rend()) << std::endl;
	for (size_t i = 0; i < lst.size(); i++){
		std::cout << *fr_it << " -> " << &(*fr_it) << std::endl;
		++fr_it;
	}
	std::cout << std::endl;

	ft::list<int>::iterator	fc_it = lst.begin();
	std::cout << "front = " << lst.front() << "back = " << lst.back() << std::endl;
	for (size_t i = 0; i < lst.size(); i++) {
		std::cout << *fc_it << " -> " << &(*fc_it) << std::endl;
		++fc_it;
	}
	std::cout << std::endl;
	
	if (lst.empty())
		std::cout << "lst is empty\n";
	else
		std::cout << "lst is not empty\n";
	
	lst.clear();
	
	if (lst.empty())
		std::cout << "lst is empty\n";
	else
		std::cout << "lst is not empty\n";
	
	ft::list<int>	lt;
	if (lt.empty())
		std::cout << "lt is empty\n";
	else
		std::cout << "lt is not empty\n";

	return 0;
}
