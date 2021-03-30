#include "Human.hpp"

std::string		Human::identify()
{
	long long			address;
	std::string			str;
	std::stringstream	ss;

	address = (long long)this;
	ss << "0x" << std::uppercase << std::hex << address;
	ss >> str;
	return (str);
}

Brain			&Human::getBrain()
{
	return brn;
}
