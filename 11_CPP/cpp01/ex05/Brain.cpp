#include "Brain.hpp"

std::string		Brain::identify()
{
	long long			address;
	std::string			str;
	std::stringstream	ss;

	str = "";
	address = (long long)this;
	ss << "0x" << std::uppercase << std::hex << address;
	ss >> str;
	return (str);
}

std::string		Brain::getFrontal()
{
	return		frontal_lobe;
}
