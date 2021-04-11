#include "ConvertToInt.hpp"

ConvertToInt::ConvertToInt()
	: Except()
{
}

ConvertToInt::ConvertToInt(ConvertToInt &cti)
{
	*this = cti;
}

ConvertToInt&	ConvertToInt::operator=(ConvertToInt &cti)
{
	if (this == &cti)
		return *this;
	return *this;
}

ConvertToInt::~ConvertToInt()
{
}

int		ConvertToInt::change(char* str)
{
	char*	end;
	double	result;

	result = std::strtod(str, &end);
	if (result != result)
		throw Nan();
	return static_cast<int>(result);
}
