#include "Brain.hpp"

std::string		Brain::identify(long long address)
{
	std::string	ch;
	std::string	str;

	str = "";
	while (address)
	{
		ch = frontal_lobe[address % 16];
		str = ch + str;
		address /= 16;
	}
	str = "0x" + str;
	return (str);
}
