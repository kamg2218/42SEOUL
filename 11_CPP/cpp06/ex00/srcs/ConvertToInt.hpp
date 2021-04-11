#ifndef CONVERTTOINT_HPP
# define CONVERTTOINT_HPP

#include <iostream>
#include "Except.hpp"

class	ConvertToInt : public Except
{
	public:
		ConvertToInt();
		ConvertToInt(ConvertToInt &cti);
		ConvertToInt&	operator=(ConvertToInt &cti);
		~ConvertToInt();
		int		change(char* str);
		class	Nan : public std::exception{
			const char* what() const throw(){
				return "impossible\n";
			}
		};
};

#endif
