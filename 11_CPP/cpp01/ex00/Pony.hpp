#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>
#include <string>

class Pony
{
	private:
		std::string	name;
	public:
		Pony() { cry(); }
		void		cry();
		void		run();
		void		ponyOnTheHeap();
		void		ponyOnTheStack();
		~Pony() { run(); }
};

#endif
