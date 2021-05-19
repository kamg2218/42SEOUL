#ifndef NON_MEMBER_HPP
# define NON_MEMBER_HPP

#include "../ft.hpp"

template<class T, class Container>
bool	operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	return lhs.getContainer() == rhs.getContainer();
}

template<class T, class Container>
bool	operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	return lhs.getContainer() != rhs.getContainer();
}

template<class T, class Container>
bool	operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	return lhs.getContainer() < rhs.getContainer();
}

template<class T, class Container>
bool	operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	return lhs.getContainer() <= rhs.getContainer();
}

template<class T, class Container>
bool	operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	return lhs.getContainer() > rhs.getContainer();
}

template<class T, class Container>
bool	operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	return lhs.getContainer() >= rhs.getContainer();
}

template <class T, class Container>
void	swap(ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs){
	lhs.swap(rhs);
}

#endif
