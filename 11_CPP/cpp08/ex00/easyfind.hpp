#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class	NotFound : public std::exception
{
	public:
		virtual const char* what() const throw(){
			return "Not Found\n";
		}
};

template<typename T>
typename T::iterator	easyfind(T first, int second)
{
	typename T::iterator	ptr;

	ptr = std::find(first.begin(), first.end(), second);
	if (ptr == first.end())
		throw NotFound();
	return ptr;
}

#endif
