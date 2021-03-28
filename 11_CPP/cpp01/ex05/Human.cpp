#include "Human.hpp"

std::string		Human::identify()
{
	std::string	ch;
	std::string	str;
	long long	address;

	str = "";
	address = (long long)this;
	while (address)
	{
		ch = brn.getFrontal()[address % 16];
		str = ch + str;
		address /= 16;
	}
	str = "0x" + str;
	return (str);
}

Brain			&Human::getBrain()
{
	return brn;
}
