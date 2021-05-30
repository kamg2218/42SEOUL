#ifndef NON_MEMBER_HPP
# define NON_MEMBER_HPP

#include "../ft.hpp"

template<class Key, class T, class Compare, class Alloc>
bool	operator==(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	MapIterator<Key, T, Compare, Alloc>	tmp;
	
	if (lhs.sz != rhs.sz)
		return false;
	tmp = rhs.begin();
	for (MapIterator<Key, T> i = lhs.begin(); i != lhs.end(); i++){
		if (i->first != tmp->first)
			return false;
		tmp++;
	}
	return true;
}

template<class Key, class T, class Compare, class Alloc>
bool	operator!=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	MapIterator<Key,T,Compare,Alloc>	tmp;
	
	if (lhs.sz != rhs.sz)
		return true;
	tmp = rhs.begin();
	for (MapIterator<Key,T,Compare,Alloc> i = lhs.begin(); i != lhs.end(); i++){
		if (i->first != tmp->first)
			return true;
		tmp++;
	}
	return false;
}

template<class Key, class T, class Compare, class Alloc>
bool	operator<(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class Key, class T, class Compare, class Alloc>
bool	operator<=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs)
		return true;
	return false;
}

template<class Key, class T, class Compare, class Alloc>
bool	operator>(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template<class Key, class T, class Compare, class Alloc>
bool	operator>=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	if (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) || lhs == rhs)
		return true;
	return false;
}

template <class Key, class T, class Compare, class Alloc>
void	swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs){
	size_type		size;
	RBTNode<Key, T>	tmp_tail;
	RBTNode<Key, T>	*tmp_head;

	size = lhs.sz;
	tmp_tail = lhs.tail;
	tmp_head = lhs.head;
	lhs.sz = rhs.sz;
	lhs.tail = rhs.tail;
	lhs.head = rhs.head;
	rhs.sz = size;
	rhs.tail = tmp_tail;
	rhs.head = tmp_head;
}

#endif
