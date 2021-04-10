#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int			main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	
	ISquad* vlc = new Squad;
	
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << "---------" << std::endl;
	}
<<<<<<< HEAD
	std::cout << "----------------------------" << std::endl;
	ISpaceMarine*	jay = new TacticalMarine;
=======
	
	std::cout << "----------------------------" << std::endl;
	ISpaceMarine* jay = new TacticalMarine;
>>>>>>> 5ea95cb2a2f2668f717a9c2f384cceb4e675a164
	vlc->push(jay);
	for (int i = 0; i < vlc->getCount(); i++)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << "---------" << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
<<<<<<< HEAD
	delete vlc;
=======
>>>>>>> 5ea95cb2a2f2668f717a9c2f384cceb4e675a164

	delete vlc;
	
	return 0;
}
