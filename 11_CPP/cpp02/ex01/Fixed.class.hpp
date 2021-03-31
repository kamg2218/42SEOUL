#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		static const int	fraction = 8;
		int					ivalue;
		float				fvalue;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& fx);
		Fixed& operator=(const Fixed& fx);
		//friend std::ostream& operator<<(std::ostream& os, const Fixed& fx);
		operator float(void) const { return fvalue; } //형변환 연산자
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif
