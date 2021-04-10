#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Victim.hpp"
#include "Laborer.hpp"

int			main(void)
{
	Sorcerer	robert("Robert", "the Magnificient");

	Victim		jim("Jimmy");
	Peon		joe("Joe");

	std::cout << robert << jim << joe;
	
	robert.polymorph(jim);
	robert.polymorph(joe);
	
	
	std::cout << "------------------------" << std::endl;
	Laborer		jay("Jaison");
	
	std::cout << jay;

	robert.polymorph(jay);
	std::cout << "------------------------" << std::endl;
	Laborer		lab("Lab");
	robert.polymorph(lab);
	std::cout << "------------------------" << std::endl;
	return 0;
}
