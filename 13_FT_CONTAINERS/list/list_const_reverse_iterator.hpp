#ifndef LIST_CONST_REVERSE_ITERATOR_HPP
# define LIST_CONST_REVERSE_ITERATOR_HPP

#include "../ft.hpp"

template<class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ListConstReverseIterator {
	protected:
		node<T>*			ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;

		ListConstReverseIterator() : ptr(0) {}
		ListConstReverseIterator(node<T>* const p) : ptr(p) {}
		ListConstReverseIterator(ListConstReverseIterator const &rit) { *this = rit; }
		ListConstReverseIterator&	operator=(ListConstReverseIterator const &rit){
			if (&rit == this)
				return *this;
			this->ptr = rit.ptr;
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
		const reference	operator*() const { return this->ptr->value; }
		const node<T>*	operator->() const { return this->ptr; }
		const reference	getValue() const { return this->ptr->value; }
		const node<T>*	getPointer() const { return this->ptr; }
};

template<class T>
bool	operator==(ListConstReverseIterator<T> const &a, ListConstReverseIterator<T> const &b){
	if (a.getPoniter() == b.getPointer())
		return true;
	return false;
}

template<class T>
bool	operator!=(ListConstReverseIterator<T> const &a, ListConstReverseIterator<T> const &b){
	if (a.getPinter() != b.getPointer())
		return true;
	return false;
}

#endif
