#include "../ft.hpp"

template <class T, class Container>
ft::queue<T, Container>::queue(const Container& cont) {}

template <class T, class Container>
ft::queue<T, Container>::queue(const ft::queue<T, Container>& other) { *this = other; }

template <class T, class Container>
ft::queue<T, Container>&		ft::queue<T, Container>::operator=(ft::queue<T, Container> const &st) {
	if (&st == this)
		return *this;
	this->c = st.c;
	return *this;
}

template <class T, class Container>
ft::queue<T, Container>::~queue() {}

template <class T, class Container>
const Container	ft::queue<T, Container>::getContainer() const { return this->c; }

//access
template <class T, class Container>
typename ft::queue<T, Container>::reference	ft::queue<T, Container>::front() { return this->c.front(); }
template <class T, class Container>
typename ft::queue<T, Container>::reference	ft::queue<T, Container>::back() { return this->c.back(); }

//capacity
template <class T, class Container>
bool		ft::queue<T, Container>::empty() const { if (this->c.empty()) return true; else return false;}
template <class T, class Container>
typename ft::queue<T, Container>::size_type	ft::queue<T, Container>::size() const { return this->c.size(); }

//modifiers
template <class T, class Container>
void		ft::queue<T, Container>::push(const ft::queue<T, Container>::value_type& value) { this->c.push_back(value); }
template <class T, class Container>
void		ft::queue<T, Container>::pop() { this->c.pop_front(); }
template <class T, class Container>
void		ft::queue<T, Container>::swap(ft::queue<T, Container>& other) { this->c.swap(other.c); }
