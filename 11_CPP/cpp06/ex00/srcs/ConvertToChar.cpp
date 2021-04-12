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
	char*	end = NULL;
	double	result;

	result = std::strtod(str, &end);
	if (result != result)
		throw Nan();
	else if (result == 0 && strlen(str) == 1 && str[0] != '0')
		result = static_cast<double>(str[0]);
	else if (*end == 'f' && *(end + 1) == '\0')
		end = end + 1;
	else if (*end != '\0')
		throw Impossible();
	if (result >= 0 && result <= 31)
		throw NonDisplayable();
	else if (result < 0 || result > 127)
		throw Impossible();
	return static_cast<char>(result);
}
