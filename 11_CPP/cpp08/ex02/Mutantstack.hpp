#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class	Mutantstack : public stack<T>
{
	private:
		std::stack<T>	_stk;
	public:
		Mutantstack() {}
		Mutantstack(Mutantstack const &mts) { *this = mts; }
		Mutantstack&	operator=(Mutantstack const &mts)
		{
			if (this == &mts)
				return *this;
			std::copy(mts.begin(), mts.end(), this->_stk);
			return *this;
		}
		~Mutantstack() {} 
};

template<typename T>
class	Iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
	private:
		T*	p;
	public:
		Iterator(T* x) : p(x) {}
		Iterator(const Iterator& it) : p(it.p) {}
		Iterator&	operator++() { ++p; return *this;}
		Iterator	operator++(T) {Iterator tmp(*this); operator++(); return tmp;}
		bool operator==(const Iterator& it) const { return p==it.p; }
		bool operator!=(const Iterator& it) const { return p!=it.p; }
		int& operator*() { return *p; }
};

#endif
