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
	else if (end)
		throw Impossible();
	else if (result == 0 && strlen(str) == 1)
	{
		int		ch = static_cast<int>(str[0]);
		if (ch > 31 && ch < 127)
			result = static_cast<double>(ch);
	}	
	if (result <= 31 || result >= 127)
		throw NonDisplayable();
	return static_cast<char>(result);
}
