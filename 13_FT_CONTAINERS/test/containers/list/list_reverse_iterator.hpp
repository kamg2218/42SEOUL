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
		ListReverseIterator(const ListReverseIterator &rit) { *this = rit; }
		ListReverseIterator(const ListConstReverseIterator<T> &rit) { *this = rit; }
		ListReverseIterator&	operator=(const ListReverseIterator &rit){
			if (&rit == this)
				return *this;
			this->ptr = rit.ptr;
			return *this;
		}
		ListReverseIterator&	operator=(const ListConstReverseIterator<T> &rit){
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
bool	operator==(const ListReverseIterator<T> &a, const ListReverseIterator<T> &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator==(const ListReverseIterator<T> &a, const ListConstReverseIterator<T> &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator!=(const ListReverseIterator<T> &a, const ListReverseIterator<T> &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(const ListReverseIterator<T> &a, const ListConstReverseIterator<T> &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

#endif
