#include "Fixed.class.hpp"

Fixed::Fixed()
	: ivalue(0)
	, fvalue(0.0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	ivalue = num;
	fvalue = static_cast<float>(num);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	ivalue = static_cast<int>(roundf(num));
	fvalue = num;
}

Fixed::Fixed(const Fixed& fx)
	: ivalue(0)
	, fvalue(0.0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fx; //call operator=
}

Fixed&	Fixed::operator=(const Fixed& fx)
{
	std::cout << "Assignation operator called" << std::endl;
	ivalue = fx.toInt();
	fvalue = fx.toFloat();
	return *this;
}

/*
std::ostream&	operator<<(std::ostream& os, const Fixed& fx)
{
	os << fx.toFloat();
	return os;
}
*/

float	Fixed::toFloat(void) const
{
	return fvalue;
}

int		Fixed::toInt(void) const
{
	return ivalue;
}
