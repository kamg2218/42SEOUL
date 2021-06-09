#ifndef LIST_CONST_ITERATOR_HPP
# define LIST_CONST_ITERATOR_HPP

template<class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ListConstIterator;
#include "list_iterator.hpp"

template<class T, class Category, class Distance, class Pointer, class Reference>
class	ListConstIterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	protected:
		node<T>*			ptr;
	public:
		ListConstIterator() : ptr(0) {}
		ListConstIterator(node<T>* const p) : ptr(p) {}
		ListConstIterator(const ListConstIterator &it) { *this = it; }
		ListConstIterator(const ListIterator<T> &it) { *this = it; }
		ListConstIterator&	operator=(const ListConstIterator &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		ListConstIterator&	operator=(const ListIterator<T> &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		~ListConstIterator() {}
		ListConstIterator&		operator++(){
			this->ptr = this->ptr->next;
			return *this;
		}
		ListConstIterator		operator++(int){
			this->ptr = this->ptr->next;
			return (ListConstIterator(this->ptr));
		}
		ListConstIterator&		operator--(){
			this->ptr = this->ptr->prev;
			return *this;
		}
		ListConstIterator		operator--(int){
			this->ptr = this->ptr->prev;
			return ListConstIterator(this->ptr);
		}
		const reference	operator*() const { return getValue(); }
		const node<T>*	operator->() const { return getPointer(); }
		reference	getValue() const { return this->ptr->value; }
		node<T>*	getPointer() const { return this->ptr; }
};

template<class T>
bool	operator==(const ListConstIterator<T> &a, const ListConstIterator<T> &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator==(const ListConstIterator<T> &a, const ListIterator<T> &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator!=(const ListConstIterator<T> &a, const ListConstIterator<T> &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(const ListConstIterator<T> &a, const ListIterator<T> &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

#endif
