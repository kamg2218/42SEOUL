#include "ConvertToFloat.hpp"

ConvertToFloat::ConvertToFloat()
	: Except()
{
}

ConvertToFloat::ConvertToFloat(ConvertToFloat &ctf)
{
	*this = ctf;
}

ConvertToFloat&	ConvertToFloat::operator=(ConvertToFloat &ctf)
{
	if (this == &ctf)
		return *this;
	return *this;
}

ConvertToFloat::~ConvertToFloat()
{
}

float		ConvertToFloat::change(char* str)
{
	char*	end;
	double	result;

	result = std::strtod(str, &end);
	if (result != result)
		throw Nan();
	else if (result == 0 && strlen(str) == 1 && str[0] != '0')
	{
		result = static_cast<double>(str[0]);
		if (result < 32 || result > 127)
			throw Impossible();
	}
	else if (*end == 'f' && *(end + 1) == '\0')
		end = end + 1;
	else if (*end != '\0')
		throw Impossible();
	return static_cast<float>(result);
}
