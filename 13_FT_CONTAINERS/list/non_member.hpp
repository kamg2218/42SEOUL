#ifndef NON_MEMBER_HPP
# define NON_MEMBER_HPP

#include <algorithm>
#include "../ft.hpp"

template<class T, class Alloc>
bool	operator==(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	Iterator<T>	tmp;
	
	if (lhs.sz != rhs.sz)
		return false;
	tmp = rhs.begin();
	for (Iterator<T> i = lhs.begin(); i != lhs.end(); i++){
		if (*i != *tmp)
			return false;
		tmp++;
	}
	return true;
}

template<class T, class Alloc>
bool	operator!=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	Iterator<T>	tmp;
	
	if (lhs.sz != rhs.sz)
		return true;
	tmp = rhs.begin();
	for (Iterator<T> i = lhs.begin(); i != lhs.end(); i++){
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

#endif
