#include "../../ft.hpp"

template <class T, class Container>
ft::stack<T, Container>::stack(const Container& cont) { }

template <class T, class Container>
ft::stack<T, Container>::stack(const ft::stack<T, Container>& other) { *this = other; }

template <class T, class Container>
ft::stack<T, Container>&		ft::stack<T, Container>::operator=(ft::stack<T, Container> const &st) {
	if (st == *this)
		return *this;
	this->c = st.c;
	return *this;
}

template <class T, class Container>
ft::stack<T, Container>::~stack() {}

template <class T, class Container>
const Container	ft::stack<T, Container>::getContainer() const { return this->c; }

template <class T, class Container>
typename ft::stack<T, Container>::reference	ft::stack<T, Container>::top() { return this->c.back(); }

template <class T, class Container>
bool		ft::stack<T, Container>::empty() const { if (c.empty()) return true; else return false;}

template <class T, class Container>
typename ft::stack<T, Container>::size_type	ft::stack<T, Container>::size() const { return this->c.size(); }

template <class T, class Container>
void		ft::stack<T, Container>::push(const value_type& value) { this->c.push_back(value); }

template <class T, class Container>
void		ft::stack<T, Container>::pop() { this->c.pop_back(); }

template <class T, class Container>
void		ft::stack<T, Container>::swap(ft::stack<T, Container>& other) { c.swap(other.c); }
