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
	else if (result > INT_MAX || result < INT_MIN)
		throw Impossible();
	else if (result == 0 && strlen(str) == 1 && str[0] != '0')
	{
		result = static_cast<int>(str[0]);
		if (result < 32 || result > 127)
			throw Impossible();
	}
	else if (*end == 'f' && *(end + 1) == '\0')
		end = end + 1;
	else if (*end != '\0')
		throw Impossible();
	return static_cast<int>(result);
}
