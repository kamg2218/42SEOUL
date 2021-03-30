#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class	Fixed
{
	private:
		int					value;
		static const int	fraction;
	public:
		Fixed();
		Fixed(const Fixed& fx);
		Fixed& operator=(const Fixed& fx);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
