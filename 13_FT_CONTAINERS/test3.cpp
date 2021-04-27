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
	lst.assign((int)3, (int)5);
	std::cout << "size = " << lst.size() << std::endl;
	for (int i = 0; i < lst.size(); i++)
		std::cout << "i = " << lst.head[i] << "\n";
	std::cout << "front = " << lst.front() << std::endl;
	//std::cout << lst.end();

	std::list<int>::iterator	itr = vt.begin();
	std::cout << "itr = " << *itr << std::endl;
	std::cout << "*begin = " << *(vt.begin()) << std::endl;

	//std::cout << "begin = " << lst.begin() << std::endl;
	std::cout << "*begin = " << *(lst.begin()) << std::endl;

	it = lst.begin();
	int num[5] = {1, 2, 3, 4, 5};
	//std::list<int>::iterator	it;

	//it = &num[0];

	//it++;
	//++it;

	std::cout << *it;
	
	if (*(vt.begin()) == *it)
		std::cout << "Same\n";

	std::list<int>::reverse_iterator	r_it = vt.rbegin();
	for (int i = 0; i < vt.size(); i++)
		std::cout << *r_it++ << " ";
	std::cout << std::endl;

	//r_it--;
	itr = vt.begin();
	//std::list<int>::reverse_iterator	r_it2 = vt.rend();
	for (int i = 0; i < vt.size(); i++)
		std::cout << *itr++ << " ";
	std::cout << std::endl;
	return 0;
}
