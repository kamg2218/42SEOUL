#ifndef NON_MEMBER_HPP
# define NON_MEMBER_HPP

#include <algorithm>
#include "../ft.hpp"

template<class T, class Container>
bool	operator==(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	return lhs.getContainer() == rhs.getContainer();
}

template<class T, class Container>
bool	operator!=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	return lhs.getContainer() != rhs.getContainer();
}

template<class T, class Container>
bool	operator<(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	return lhs.getContainer() < rhs.getContainer();
}

template<class T, class Container>
bool	operator<=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	return lhs.getContainer() <= rhs.getContainer();
}

template<class T, class Container>
bool	operator>(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	return lhs.getContainer() > rhs.getContainer();
}

template<class T, class Container>
bool	operator>=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	return lhs.getContainer() >= rhs.getContainer();
}

template <class T, class Container>
void	swap(ft::queue<T, Container>& lhs, ft::queue<T, Container>& rhs){
	lhs.swap(rhs);
}

#endif
