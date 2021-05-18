#ifndef NON_MEMBER_HPP
# define NON_MEMBER_HPP

#include <algorithm>
#include "ft.hpp"
//#include "./list/non_member.hpp"
//#include "./vector/non_member.hpp"

//list
template<class T, class Alloc>
bool	operator==(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	ListIterator<T>	tmp;
	
	if (lhs.sz != rhs.sz)
		return false;
	tmp = rhs.begin();
	for (ListIterator<T> i = lhs.begin(); i != lhs.end(); i++){
		if (*i != *tmp)
			return false;
		tmp++;
	}
	return true;
}

template<class T, class Alloc>
bool	operator!=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	ListIterator<T>	tmp;
	
	if (lhs.sz != rhs.sz)
		return true;
	tmp = rhs.begin();
	for (ListIterator<T> i = lhs.begin(); i != lhs.end(); i++){
		if (*i != *tmp)
			return true;
		tmp++;
	}
	return false;
}

template<class T, class Alloc>
bool	operator<(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class T, class Alloc>
bool	operator<=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	if (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs)
		return true;
	return false;
}

template<class T, class Alloc>
bool	operator>(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template<class T, class Alloc>
bool	operator>=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	if (std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) || lhs == rhs)
		return true;
	return false;
}

template <class T, class Alloc>
void	swap(ft::list<T, Alloc>& lhs, ft::list<T, Alloc>& rhs){
	lhs.swap(rhs);
}

//vector
template<class T, class Alloc>
bool	operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class T, class Alloc>
bool	operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	if (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs)
		return true;
	return false;
}

template<class T, class Alloc>
bool	operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template<class T, class Alloc>
bool	operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	if (std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) || lhs == rhs)
		return true;
	return false;
}

template <class T, class Alloc>
void	swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs){
	lhs.swap(rhs);
}

//stack
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

//queue
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
