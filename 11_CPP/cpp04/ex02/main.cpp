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
	std::cout << "----------------------------" << std::endl;
	ISpaceMarine* jay = new TacticalMarine;
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

	delete vlc;
	
	return 0;
}
