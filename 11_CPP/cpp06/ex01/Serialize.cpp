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
	char*	data = new char[20];
	std::string	letter = num + alpha;

	srand(clock());
	//std::cout << "s1 = ";
	for (int i = 0; i < 8; i++)
	{
		data[i] = letter[rand() % letter.size()];
		//std::cout << data[i];
	}
	//std::cout << std::endl;
	int*	num = reinterpret_cast<int*>(data + 8);
	*num = rand();
	//std::cout << "num : " << *num << std::endl;
	//std::cout << "s2 = ";
	for (int i = 12; i < 20; i++)
	{
		data[i] = letter[rand() % letter.size()];
		//std::cout << data[i];
	}
	//std::cout << std::endl;
	return reinterpret_cast<void*>(data);
}

Data*	Serialize::deserialize(void* raw)
{
	char*	ptr;
	Data* data = new Data;

	data->s1 = std::string(reinterpret_cast<char*>(raw), 8);
	ptr = reinterpret_cast<char*>(raw) + 8;
	data->n = *(reinterpret_cast<int*>(ptr));
	data->s2 = std::string(static_cast<char*>(raw) + 12, 8);
	
	return data;
}
