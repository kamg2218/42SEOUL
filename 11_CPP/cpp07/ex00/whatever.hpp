#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template<typename T>
class	whatever
{
	public:
		whatever();
		whatever(whatever& wt);
		whatever&	operator=(whatever& wt);
		~whatever();
};

#endif
