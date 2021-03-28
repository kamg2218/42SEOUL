#include "Brain.hpp"

std::string		Brain::identify()
{
	std::string	ch;
	std::string	str;
	long long	address;

	str = "";
	address = (long long)this;
	while (address)
	{
		ch = frontal_lobe[address % 16];
		str = ch + str;
		address /= 16;
	}
	str = "0x" + str;
	return (str);
}

std::string		Brain::getFrontal()
{
	return		frontal_lobe;
}
