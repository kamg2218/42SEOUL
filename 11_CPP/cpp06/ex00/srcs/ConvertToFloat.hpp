#ifndef CONVERTTOFLOAT_HPP
# define CONVERTTOFLOAT_HPP

#include <iostream>
#include "Except.hpp"

class	ConvertToFloat : public Except
{
	public:
		ConvertToFloat();
		ConvertToFloat(ConvertToFloat &ctf);
		ConvertToFloat&	operator=(ConvertToFloat &ctf);
		~ConvertToFloat();
		float	change(char* str);
		class	Nan : public std::exception{
			const char* what() const throw(){
				return "nanf\n";
			}
		};
};

#endif
