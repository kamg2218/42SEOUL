#include "Mutantstack.hpp"

int			main(void)
{
	Mutantstack<int>	mts;

	mts.push(10);
	mts.push(18);
	mts.push(28);

	Mutantstack<int>::iterator it1 = mts.begin(); 
	std::cout << *it1 << std::endl;
	std::cout << *(it1 + 1) << std::endl;
	std::cout << "-------------------\n";
	Mutantstack<int>::reverse_iterator it2 = mts.rbegin(); 
	std::cout << *it2 << std::endl;
	std::cout << *(it2 + 1) << std::endl;
	std::cout << "-------------------\n";
	std::cout << mts.size() << std::endl;
	std::cout << mts.top() << std::endl;
	mts.pop();
	if (!mts.empty())
		std::cout << mts.top() << std::endl;
	std::cout << "-------------------\n";

	Mutantstack<int>	nmts;

	nmts = mts;
	std::cout << "----------\n";
	if (!nmts.empty())
		std::cout << "top1 = " << nmts.top() << std::endl;
	nmts.push(10);
	if (!nmts.empty())
		std::cout << "top2 = " << nmts.top() << std::endl;
	std::cout << nmts.size() << std::endl;
	if (!nmts.empty())
		std::cout << "top3 = " << nmts.top() << std::endl;

	return 0;
}
