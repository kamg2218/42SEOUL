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
	return static_cast<float>(result);
}
