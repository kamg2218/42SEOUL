#include "Mutantstack.hpp"

int			main(void)
{
	Mutantstack<int>	mts;

	mts.push(10);
	std::cout << mts.size() << std::endl;
	std::cout << mts.top() << std::endl;
	mts.pop();
	if (!mts.empty())
		std::cout << mts.top() << std::endl;
	
	Mutantstack<int>	nmts;

	nmts = mts;
	std::cout << nmts.top() << std::endl;
	nmts.push(10);
	std::cout << nmts.top() << std::endl;
	std::cout << nmts.size() << std::endl;
	std::cout << nmts.top() << std::endl;

	return 0;
}
