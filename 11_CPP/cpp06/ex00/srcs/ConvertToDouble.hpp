#ifndef CONVERTTODOUBLE_HPP
# define CONVERTTODOUBLE_HPP

#include <iostream>
#include "Except.hpp"

class	ConvertToDouble : public Except
{
	public:
		ConvertToDouble();
		ConvertToDouble(ConvertToDouble &ctd);
		ConvertToDouble&	operator=(ConvertToDouble &ctd);
		~ConvertToDouble();
		double	change(char* str);
		class	Nan : public std::exception{
			const char* what() const throw(){
				return "nan\n";
			}
		};
};

#endif
