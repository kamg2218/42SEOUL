#ifndef	SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>
#include <string>

typedef struct Data{
	std::string s1;
	int			n;
	std::string s2;
} Data;

class	Serialize
{
	private:
		std::string		num;
		std::string		alpha;
	public:
		Serialize();
		Serialize(Serialize &serial);
		Serialize&	operator=(Serialize &serial);
		~Serialize();
		void*	serialize();
		Data*	deserialize(void* raw);
};

#endif
