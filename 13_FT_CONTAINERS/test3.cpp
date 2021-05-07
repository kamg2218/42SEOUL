#include <list>
#include "ft.hpp"

int		main()
{
	//Iterator<int>	it;
	ft::list<int>::iterator it;
	ft::list<int> lst(3, 5);
	
	it = lst.begin();
	for (size_t i = 0; i < lst.size(); i++){
		std::cout << *it << " -> " << &(*it) << std::endl;
		++it;
	}
	std::cout << std::endl;
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
		std::cout << "next = " << *fc_it++ << std::endl;
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

	it = lt.begin();
	it = lt.insert(it, 10);
	it++;
	it++;
	it = lt.insert(it, 20);
	it = lt.insert(it, 30);
	l_it = lt.begin();
	for (size_t i = 0; i < lt.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	
	ft::list<int> new_lst;
	new_lst.assign(1, 5);
	new_lst.insert(new_lst.begin(), 3, 6);
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	
	std::cout << "--------sort---------\n";
	new_lst.sort();
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;

	std::cout << "--------reverse---------\n";
	new_lst.reverse();
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;

	std::cout << "--------push_back---------\n";
	lst.push_back(100);
	lst.push_back(300);
	lst.push_back(200);
	lst.push_back(300);
	l_it = lst.begin();
	for (size_t i = 0; i < lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	std::cout << "--------merge---------\n";
	new_lst.merge(lst);
	new_lst.push_back(3);
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	std::cout << "--------unique---------\n";
	new_lst.unique();
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	
	if (lst.empty())
		std::cout << "lst is empty\n";
	std::cout << "--------splice---------\n";
	l_it--;
	l_it--;
	//l_it = new_lst.begin();
	//lst.splice(lst.begin(), new_lst, l_it);
	lst.splice(lst.begin(), new_lst, l_it, new_lst.end());
	//lst.splice(lst.begin(), new_lst);
	l_it = lst.begin();
	for (size_t i = 0; i < lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	std::cout << "--------splice---------\n";
	new_lst.pop_back();
	new_lst.pop_front();
	new_lst.push_back(100);
	new_lst.erase(new_lst.begin());
	new_lst.push_back(110);
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	std::cout << "--------swap---------\n";
	new_lst.swap(lst);
	std::cout << "lst \n";
	l_it = lst.begin();
	for (size_t i = 0; i < lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	std::cout << "new_lst \n";
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	std::cout << "--------swap2---------\n";
	//swap(new_lst, lst);
	ft::swap(new_lst, lst);
	std::cout << "lst \n";
	l_it = lst.begin();
	for (size_t i = 0; i < lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	std::cout << "new_lst \n";
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	std::cout << "--------cmp---------\n";
	if (lst > new_lst)
		std::cout << "lst is bigger\n";
	else if (lst < new_lst)
		std::cout << "lst is smaller\n";
	else
		std::cout << "lst and new_lst is same\n";
/*
	std::cout << "--------erase---------\n";
	new_lst.erase(new_lst.begin(), new_lst.end());
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
*/	
	std::cout << "--------sort---------\n";
	new_lst.sort();
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}

	std::cout << "--------remove---------\n";
	new_lst.remove(new_lst.front());
	//new_lst.erase(new_lst.begin());
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << "sizeof = " << sizeof(*new_lst.head) << std::endl;

/*	if (new_lst.empty())
		std::cout << "It's empty\n";
	std::cout << std::endl;

	new_lst.resize(3, 5);
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;

	new_lst.swap(lst);
	if (new_lst.empty())
		std::cout << "It's empty\n";
	l_it = new_lst.begin();
	for (size_t i = 0; i < new_lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	
	l_it = lst.begin();
	for (size_t i = 0; i < lst.size(); i++) {
		std::cout << *l_it << " -> " << &(*l_it) << std::endl;
		++l_it;
	}
	std::cout << std::endl;
	*/
/*
	std::list<int>				new_lst2;
	std::list<int>::iterator	new_it2;
	new_lst2.assign(1, 5);
	new_it2 = new_lst2.begin();
	for (size_t i = 0; i < new_lst2.size(); i++) {
		std::cout << *new_it2 << " -> " << &(*new_it2) << std::endl;
		++new_it2;
	}
	std::cout << std::endl;
	new_lst2.insert(new_lst2.begin(), 3, 6);
	new_it2 = new_lst2.begin();
	for (size_t i = 0; i < new_lst2.size(); i++) {
		std::cout << *new_it2 << " -> " << &(*new_it2) << std::endl;
		++new_it2;
	}
	std::cout << std::endl;

	new_lst2.pop_back();
	new_lst2.push_back(100);
	new_it2 = new_lst2.begin();
	for (size_t i = 0; i < new_lst2.size(); i++) {
		std::cout << *new_it2 << " -> " << &(*new_it2) << std::endl;
		++new_it2;
	}
*/
	return 0;
}
