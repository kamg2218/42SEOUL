#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		static const int	fraction = 8;
		int					sign;
		int					ivalue;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& fx);
		Fixed& operator=(const Fixed& fx);
		//operator float(void) const { return fvalue; } //형변환 연산자
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getSign(void) const;
		int		getIvalue(void) const;
		int		getFraction(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);

#endif
