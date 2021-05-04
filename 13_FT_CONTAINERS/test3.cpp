#include "ft.hpp"

int		main()
{
	//ft::list::iterator<int>	it;
	Iterator<int>	it;
	//ft::list::iterator<int> it;
	ft::list<int> lst(3, 5);
	
	std::cout << "size = " << lst.size() << std::endl;
	std::cout << "lst front = " << lst.front() << std::endl;
	it = lst.begin();
	for (ft::list<int>::iterator i = it; i != lst.end(); i++)
		std::cout << "list = " << *i << "\n";
	if (!lst.empty())
		std::cout << "front = " << lst.front() << std::endl;
	else
		std::cout << "It's empty\n";

	std::cout << "*begin = " << *(lst.begin()) << std::endl;
	it = lst.begin();
	std::cout << "begin = " << *it << std::endl;
	
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	std::cout << "size = " << lst.size() << std::endl;
	ft::list<int>::reverse_iterator fr_it = lst.rbegin();
	std::cout << "rend = " << &(*lst.rend()) << std::endl;
	for (size_t i = 0; i < lst.size(); i++){
		std::cout << *fr_it << " -> " << &(*fr_it) << std::endl;
		++fr_it;
	}
	std::cout << std::endl;

	std::cout << "size = " << lst.size() << std::endl;
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

	std::cout << "size = " << lt.size() << std::endl;
	lt.assign(3, 5);
	std::cout << "size = " << lt.size() << std::endl;
	ft::list<int>::iterator	l_it = lt.begin();
	std::cout << "front = " << lt.front() << "back = " << lt.back() << std::endl;
	for (size_t i = 0; i < lt.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	return 0;
}
