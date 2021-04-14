#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
class	Mutantstack : public std::stack<T>
{
	public:
		Mutantstack() {}
		Mutantstack(Mutantstack const &mts) { *this = mts; }
		Mutantstack&	operator=(Mutantstack const &mts)
		{
			if (this == &mts)
				return *this;
			this->c = mts.c;
			return *this;
		}
		~Mutantstack() {}
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		iterator	begin() { return this->c.begin();}
		const_iterator	begin() const { return this->c.begin();}
		iterator	end() { return this->c.end();}
		const_iterator	end() const { return this->c.end();}
		reverse_iterator	rbegin() { return this->c.rbegin();}
		const_reverse_iterator	rbegin() const { return this->c.rbegin();}
		reverse_iterator	rend() { return this->c.rend();}
		const_reverse_iterator	rend() const { return this->c.rend();}
};

#endif
