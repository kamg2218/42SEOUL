#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

template<class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ListIterator;
#include "list_const_iterator.hpp"

template<class T, class Category, class Distance, class Pointer, class Reference>
class	ListIterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	protected:
		node<T>*			ptr;
	public:
		ListIterator() : ptr(0) {}
		ListIterator(node<T>* const p) : ptr(p) {}
		ListIterator(const ListIterator &it) { *this = it; }
		ListIterator(const ListConstIterator<T> &it) { *this = it; }
		ListIterator&	operator=(const ListIterator &it){
			if (&it == this)
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		ListIterator&	operator=(const ListConstIterator<T> &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		~ListIterator() {}
		ListIterator&		operator++(){
			this->ptr = this->ptr->next;
			return *this;
		}
		ListIterator		operator++(int){
			this->ptr = this->ptr->next;
			return (ListIterator(this->ptr));
		}
		ListIterator&		operator--(){
			this->ptr = this->ptr->prev;
			return *this;
		}
		ListIterator		operator--(int){
			this->ptr = this->ptr->prev;
			return ListIterator(this->ptr);
		}
		reference	operator*() const { return getValue(); }
		node<T>*	operator->() const { return getPointer(); }
		reference	getValue() const { return this->ptr->value; }
		node<T>*	getPointer() const { return this->ptr; }
};

template<class T>
bool	operator==(const ListIterator<T> &a, const ListIterator<T> &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator==(const ListIterator<T> &a, const ListConstIterator<T> &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator!=(const ListIterator<T> &a, const ListIterator<T> &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(const ListIterator<T> &a, const ListConstIterator<T> &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

#endif
