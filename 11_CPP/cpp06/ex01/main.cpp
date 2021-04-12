#include "Serialize.hpp"

int		main(void)
{
	Serialize	serial;
	Data*		data;
	void*		dt;

	dt = serial.serialize();
	data = serial.deserialize(dt);
	std::cout << "s1 = " << data->s1 << std::endl;
	std::cout << "n = " << data->n << std::endl;
	std::cout << "s2 = " << data->s2 << std::endl;

	delete data;
	return 0;
}
