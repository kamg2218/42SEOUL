#include "Pony.hpp"

int			main(void)
{
	Pony	pn;

	std::cout << "The address of pn is " << &pn << std::endl;
	pn.ponyOnTheHeap();
	std::cout << "-------------------------" << std::endl;
	pn.ponyOnTheStack();
	return (0);
}
