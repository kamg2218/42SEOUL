#ifndef LIST_CONST_REVERSE_ITERATOR_HPP
# define LIST_CONST_REVERSE_ITERATOR_HPP

#include "../ft.hpp"
template<class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ListConstReverseIterator;
#include "list_reverse_iterator.hpp"

template<class T, class Category, class Distance, class Pointer, class Reference>
class	ListConstReverseIterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	protected:
		node<T>*			ptr;
	public:
		ListConstReverseIterator() : ptr(0) {}
		ListConstReverseIterator(node<T>* const p) : ptr(p) {}
		ListConstReverseIterator(ListConstReverseIterator const &rit) { *this = rit; }
		ListConstReverseIterator(ListReverseIterator<T> const &rit) { *this = rit; }
		ListConstReverseIterator&	operator=(ListConstReverseIterator const &rit){
			if (&rit == this)
				return *this;
			this->ptr = rit.ptr;
			return *this;
		}
		ListConstReverseIterator&	operator=(ListReverseIterator<T> const &rit){
			if (rit.getPointer() == this->ptr)
				return *this;
			this->ptr = rit.getPointer();
			return *this;
		}
		~ListConstReverseIterator() {}
		ListConstReverseIterator&		operator++(){
			this->ptr = this->ptr->prev;
			return *this;
		}
		ListConstReverseIterator&		operator++(int){
			this->ptr = this->ptr->prev;
			return *this;
		}
		ListConstReverseIterator&		operator--(){
			this->ptr = this->ptr->next;
			return *this;
		}
		ListConstReverseIterator&		operator--(int){
			this->ptr = this->ptr->next;
			return *this;
		}
		const reference	operator*() const { return getValue(); }
		const node<T>*	operator->() const { return getPointer(); }
		reference	getValue() const { return this->ptr->value; }
		node<T>*	getPointer() const { return this->ptr; }
};

template<class T>
bool	operator==(ListConstReverseIterator<T> const &a, ListConstReverseIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator==(ListConstReverseIterator<T> const &a, ListReverseIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(ListConstReverseIterator<T> const &a, ListConstReverseIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(ListConstReverseIterator<T> const &a, ListReverseIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

#endif
