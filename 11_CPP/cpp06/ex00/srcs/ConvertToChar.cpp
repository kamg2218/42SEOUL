#include "ConvertToChar.hpp"

ConvertToChar::ConvertToChar()
	: Except()
{
}

ConvertToChar::ConvertToChar(ConvertToChar &ctc)
{
	*this = ctc;
}

ConvertToChar&	ConvertToChar::operator=(ConvertToChar &ctc)
{
	if (this == &ctc)
		return *this;
	return *this;
}

ConvertToChar::~ConvertToChar()
{
}

char	ConvertToChar::change(char* str)
{
	char*	end;
	double	result;

	result = std::strtod(str, &end);
	if (result != result)
		throw Nan();
	else if (result <= 0 || result >= 127)
		throw NonDisplayable();
	return static_cast<char>(result);
}
