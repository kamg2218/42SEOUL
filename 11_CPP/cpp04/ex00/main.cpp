#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Victim.hpp"

int			main(void)
{
	Sorcerer	robert("Robert", "the Magnificient");

	Victim		jim("Jimmy");
	Peon		joe("Joe");

	std::cout << robert << jim << joe;
	
	robert.polymorph(jim);
	robert.polymorph(joe);
	return 0;
}
