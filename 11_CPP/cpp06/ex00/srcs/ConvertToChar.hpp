#ifndef CONVERTTOCHAR_HPP
# define CONVERTTOCHAR_HPP

#include <iostream>
#include "Except.hpp"

class	ConvertToChar : public Except
{
	public:
		ConvertToChar();
		ConvertToChar(ConvertToChar &ctc);
		ConvertToChar&	operator=(ConvertToChar &ctc);
		~ConvertToChar();
		char	change(char* str);
		class	Nan : public std::exception{
			const char* what() const throw(){
				return "impossible\n";
			}
		};
};

#endif
