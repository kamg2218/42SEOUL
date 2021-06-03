#ifndef LIST_CONST_ITERATOR_HPP
# define LIST_CONST_ITERATOR_HPP

#include "../ft.hpp"

template<class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ListConstIterator {
	protected:
		node<T>*			ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	
		ListConstIterator() : ptr(0) {}
		ListConstIterator(node<T>* const p) : ptr(p) {}
		ListConstIterator(ListConstIterator const &it) { *this = it; }
		ListConstIterator&	operator=(ListConstIterator<T> const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
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
bool	operator==(ListConstIterator<T> const &a, ListConstIterator<T> const &b){
	if (a.getPointer() == b.getPointer())
		return true;
	else
		return false;
}

template<class T>
bool	operator!=(ListConstIterator<T> const &a, ListConstIterator<T> const &b){
	if (a.getPointer() != b.getPointer())
		return true;
	else
		return false;
}

#endif
