#ifndef NON_MEMBER_HPP
# define NON_MEMBER_HPP

#include <algorithm>
#include "ft.hpp"

//list
template<class T, class Alloc>
bool	operator==(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	ListConstIterator<T>		tmp;
	
	if (lhs.sz != rhs.sz)
		return false;
	tmp = rhs.begin();
	for (ListConstIterator<T> i = lhs.begin(); i != lhs.end(); i++){
		if (tmp == rhs.end())
			break ;
		if (*i != *tmp)
			return false;
		tmp++;
	}
	return true;
}

template<class T, class Alloc>
bool	operator!=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	ListConstIterator<T>		tmp;
	
	if (lhs.sz != rhs.sz)
		return true;
	tmp = rhs.begin();
	for (ListConstIterator<T> i = lhs.begin(); i != lhs.end(); i++){
		if (tmp == rhs.end())
			break ;
		if (*i != *tmp)
			return true;
		tmp++;
	}
	return false;
}

template<class T, class Alloc>
bool	operator<(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class T, class Alloc>
bool	operator<=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs)
		return true;
	return false;
}

template<class T, class Alloc>
bool	operator>(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template<class T, class Alloc>
bool	operator>=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	if (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) || lhs == rhs)
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
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class T, class Alloc>
bool	operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs)
		return true;
	return false;
}

template<class T, class Alloc>
bool	operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template<class T, class Alloc>
bool	operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	if (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) || lhs == rhs)
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

//map
template<class Key, class T, class Compare, class Alloc>
bool	operator==(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	MapIterator<Key, T>	i;
	MapIterator<Key, T>	tmp;

	if (lhs.sz != rhs.sz)
		return false;
	tmp = rhs.begin();
	for (i = lhs.begin(); i != lhs.end() && tmp != rhs.end(); i++){
		if (i->first != tmp->first)
			return false;
		else if (i->second != tmp->second)
			return false;
		tmp++;
	}
	return true;
}

template<class Key, class T, class Compare, class Alloc>
bool	operator!=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	MapIterator<Key, T>	i;
	MapIterator<Key, T>	tmp;

	if (lhs.sz != rhs.sz)
		return true;
	tmp = rhs.begin();
	for (i = lhs.begin(); i != lhs.end() && tmp != rhs.end(); i++){
		if (i->first != tmp->first)
			return true;
		else if (i->second != tmp->second)
			return true;
		tmp++;
	}
	return false;
}

template<class Key, class T, class Compare, class Alloc>
bool	operator<(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	MapIterator<Key, T>	i;
	MapIterator<Key, T>	tmp;

	tmp = rhs.begin();
	for (i = lhs.begin(); i != lhs.end() && tmp != rhs.end(); i++){
		if (i->first > tmp->first)
			return false;
		else if (i->first == tmp->first
				&& i->second >= tmp->second)
			return false;
	}
	return true;
}

template<class Key, class T, class Compare, class Alloc>
bool	operator<=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	MapIterator<Key, T>	i;
	MapIterator<Key, T>	tmp;

	tmp = rhs.begin();
	for (i = lhs.begin(); i != lhs.end() && tmp != rhs.end(); i++){
		if (i->first > tmp->first)
			return false;
		else if (i->first == tmp->first
				&& i->second > tmp->second)
			return false;
	}
	return true;
}

template<class Key, class T, class Compare, class Alloc>
bool	operator>(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	MapIterator<Key, T>	i;
	MapIterator<Key, T>	tmp;

	tmp = rhs.begin();
	for (i = lhs.begin(); i != lhs.end() && tmp != rhs.end(); i++){
		if (i->first < tmp->first)
			return false;
		else if (i->first == tmp->first
				&& i->second <= tmp->second)
			return false;
	}
	return true;
}

template<class Key, class T, class Compare, class Alloc>
bool	operator>=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
	MapIterator<Key, T>	i;
	MapIterator<Key, T>	tmp;

	tmp = rhs.begin();
	for (i = lhs.begin(); i != lhs.end() && tmp != rhs.end(); i++){
		if (i->first < tmp->first)
			return false;
		else if (i->first == tmp->first
				&& i->second < tmp->second)
			return false;
	}
	return true;
}

template <class Key, class T, class Compare, class Alloc>
void	swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs){
	typename ft::map<Key, T, Compare, Alloc>::size_type		size;
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
