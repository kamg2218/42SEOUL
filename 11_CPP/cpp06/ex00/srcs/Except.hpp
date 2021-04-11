#ifndef EXCEPT_HPP
# define EXCEPT_HPP

#include <exception>
#include <string>
#include <cstdlib>

class	Except
{
	public:
		Except() {}
		~Except() {}
		class	Impossible : public std::exception{
			const char* what() const throw(){
				return "impossible\n";
			}
		};
		class	NonDisplayable : public std::exception{
			const char* what() const throw(){
				return "Non displayable\n";
			}
		};
		class	Nan : public std::exception{
			const char* what() const throw() = 0;
		};
};

#endif
