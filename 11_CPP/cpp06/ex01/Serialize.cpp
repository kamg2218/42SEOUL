#include "Serialize.hpp"

Serialize::Serialize()
{
	num = "0123456789";
	alpha = "abcdefghijklmnopqrstuvwxyz";
}

Serialize::Serialize(Serialize &serial)
{
	*this = serial;
}

Serialize&	Serialize::operator=(Serialize &serial)
{
	if (this == &serial)
		return *this;
	return *this;
}

Serialize::~Serialize()
{
}

void*	Serialize::serialize()
{
	Data* data = new Data;
	std::string	letter = num + alpha;

	srand(clock());
	data->s1.clear();
	for (int i = 0; i < 8; i++)
		data->s1 += letter[rand() % letter.size()];
	data->n = rand() % 100000;
	data->s2.clear();
	for (int i = 0; i < 8; i++)
		data->s2 += letter[rand() % letter.size()];
	return static_cast<void*>(data);
}

Data*	Serialize::deserialize(void* raw)
{
	Data* data = new Data;

	data->s1 = std::string(static_cast<char*>(raw), 9);
	data->n = *(static_cast<int*>(raw) + 24);
	data->s2 = std::string(static_cast<char*>(raw) + 32, 9);
	
	std::cout << data << std::endl;
	std::cout << &data->s1 << std::endl;
	std::cout << &data->n << std::endl;
	std::cout << &data->s2 << std::endl;
	std::cout << sizeof(char) << std::endl;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(*data) << std::endl;
	std::cout << sizeof(std::string) << std::endl;
	
	return data;
}
