#include "ConvertToDouble.hpp"

ConvertToDouble::ConvertToDouble()
	: Except()
{
}

ConvertToDouble::ConvertToDouble(ConvertToDouble &ctd)
{
	*this = ctd;
}

ConvertToDouble&	ConvertToDouble::operator=(ConvertToDouble &ctd)
{
	if (this == &ctd)
		return *this;
	return *this;
}

ConvertToDouble::~ConvertToDouble()
{
}

double		ConvertToDouble::change(char* str)
{
	char*	end;
	double	result;

	result = std::strtod(str, &end);
	if (result != result)
		throw Nan();
	return static_cast<double>(result);
}
