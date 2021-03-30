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
