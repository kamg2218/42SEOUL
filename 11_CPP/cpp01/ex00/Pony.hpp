#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>
#include <string>

class Pony
{
	private:
		std::string	name;
	public:
		void		ponyOnTheHeap(void);
		void		ponyOnTheStack(void);
};

#endif
