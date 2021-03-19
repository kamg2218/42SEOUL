#include <iostream>
#include <string>
#include <iomanip>

int			main(void)
{
	std::string	ch;

	std::cin >> ch;
	//ch = ch.substr(0, 9);
	if (ch.size() < 10)
		std::cout << std::setw(10);
	std::cout << ch.substr(0, 9);
	if (ch.size() > 10)
		std::cout << ".";
	std::cout << std::endl;
	return (0);
}
