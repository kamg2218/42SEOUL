#include "Pony.hpp"

void		Pony::ponyOnTheHeap(void)
{
	Pony	*pny = new Pony;

	pny->name = "pink";
	std::cout << "heap pony = " << &pny << std::endl;
	std::cout << "new heap pony = " << pny << std::endl;
	std::cout << "new heap pony's name = " << pny->name << std::endl;
	std::cout << "new heap pony's address = " << &(pny->name) << std::endl;
	delete pny;
}

void		Pony::ponyOnTheStack(void)
{
	Pony	pny;

	pny.name = "blue";
	std::cout << "stack pony = " << &pny << std::endl;
	std::cout << "stack pony's name = " << pny.name << std::endl;
	std::cout << "stack pony's address = " << &pny.name << std::endl;
}
