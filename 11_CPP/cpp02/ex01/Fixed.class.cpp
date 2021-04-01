#include "Fixed.class.hpp"

Fixed::Fixed()
	: sign(1)
	, ivalue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num)
	: sign(1)
	, ivalue(0)
{
	std::cout << "Int constructor called" << std::endl;
	if (num < 0)
		sign = -1;
	ivalue = num << fraction;
	ivalue *= sign;
}

Fixed::Fixed(const float num)
	: sign(1)
	, ivalue(0)
{
	std::cout << "Float constructor called" << std::endl;
	if (num < 0)
		sign = -1;
	ivalue = static_cast<int>(roundf(num * (1 << fraction))) * sign;
}

Fixed::Fixed(const Fixed& fx)
	: sign(1)
	, ivalue(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fx; //call operator=
}

Fixed&	Fixed::operator=(const Fixed& fx)
{
	std::cout << "Assignation operator called" << std::endl;
	sign = fx.getSign();
	ivalue = fx.getIvalue();
	return *this;
}

float	Fixed::toFloat(void) const
{
	float	flt;

	flt = static_cast<float>(ivalue);
	flt = flt / (1 << fraction);
   	return sign * flt;
}

int		Fixed::toInt(void) const
{
	return static_cast<int>(roundf(toFloat()));
}
int		Fixed::getFraction(void) const { return fraction; }
int		Fixed::getSign(void) const { return sign; }
int		Fixed::getIvalue(void) const { return ivalue; }

std::ostream&	operator<<(std::ostream& os, const Fixed& fx)
{
	os << fx.toFloat();
	return os;
}
