#ifndef LIST_REVERSE_ITERATOR_HPP
# define LIST_REVERSE_ITERATOR_HPP

template<class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ListReverseIterator;
#include "list_const_reverse_iterator.hpp"

template<class T, class Category, class Distance, class Pointer, class Reference>
class	ListReverseIterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	protected:
		node<T>*			ptr;
	public:
		ListReverseIterator() : ptr(0) {}
		ListReverseIterator(node<T>* const p) : ptr(p) {}
		ListReverseIterator(ListReverseIterator const &rit) { *this = rit; }
		ListReverseIterator(ListConstReverseIterator<T> const &rit) { *this = rit; }
		ListReverseIterator&	operator=(ListReverseIterator const &rit){
			if (&rit == this)
				return *this;
			this->ptr = rit.ptr;
			return *this;
		}
		ListReverseIterator&	operator=(ListConstReverseIterator<T> const &rit){
			if (rit.getPointer() == this->ptr)
				return *this;
			this->ptr = rit.getPointer();
			return *this;
		}
		~ListReverseIterator() {}
		ListReverseIterator&		operator++(){
			this->ptr = this->ptr->prev;
			return *this;
		}
		ListReverseIterator&		operator++(int){
			this->ptr = this->ptr->prev;
			return *this;
		}
		ListReverseIterator&		operator--(){
			this->ptr = this->ptr->next;
			return *this;
		}
		ListReverseIterator&		operator--(int){
			this->ptr = this->ptr->next;
			return *this;
		}
		reference	operator*() const { return getValue(); }
		node<T>*	operator->() const { return getPointer(); }
		reference	getValue() const { return this->ptr->value; }
		node<T>*	getPointer() const { return this->ptr; }
};

template<class T>
bool	operator==(ListReverseIterator<T> const &a, ListReverseIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator==(ListReverseIterator<T> const &a, ListConstReverseIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(ListReverseIterator<T> const &a, ListReverseIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(ListReverseIterator<T> const &a, ListConstReverseIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

#endif
