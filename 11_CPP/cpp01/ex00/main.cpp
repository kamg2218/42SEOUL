#include "Pony.hpp"

int			main(void)
{
	Pony	pn;

	std::cout << "The address of pn is " << &pn << std::endl;
	pn.ponyOnTheHeap();
	pn.ponyOnTheStack();
	return (0);
}
