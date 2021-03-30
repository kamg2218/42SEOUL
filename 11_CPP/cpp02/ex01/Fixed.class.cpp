#include "Fixed.class.hpp"

Fixed::Fixed()
	: value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num) { value = num; }
Fixed::Fixed(const float num) { value = static_cast<int>(num); }

Fixed::Fixed(const Fixed& fx)
	: value(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fx;
}

Fixed&	Fixed::operator=(const Fixed& fx)
{
	std::cout << "Assignation operator called" << std::endl;
	value = fx.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float	Fixed::toFloat(void) const
{
	float	num;

	num += static_cast<float>(value);
	
}

int		Fixed::toInt(void) const
{
	int		num;

		
}
