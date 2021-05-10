#ifndef LIST_REVERSE_ITERATOR_HPP
# define LIST_REVERSE_ITERATOR_HPP

#include "list_iterator.hpp"

template<class T, class Category = std::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ListReverseIterator : public std::iterator<Category, T> {
	protected:
		node<T>*				ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;

		ListReverseIterator() : ptr(0) {}
		ListReverseIterator(node<T>* const p) : ptr(p) {}
		ListReverseIterator(ListReverseIterator const &rit) { *this = rit; }
		ListReverseIterator&	operator=(ListReverseIterator const &rit){
			if (&rit == this)
				return *this;
			this->ptr = rit.ptr;
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
		reference	operator*() const { return ptr->value; }
		node<T>*	operator->() const { return ptr; }
		reference	getValue() const { return ptr->value; }
		node<T>*	getPointer() const { return ptr; }
};

template<class T>
bool	operator==(ListReverseIterator<T> const &a, ListReverseIterator<T> const &b){
	if (a.getPoniter() == b.getPointer())
		return true;
	return false;
}

template<class T>
bool	operator!=(ListReverseIterator<T> const &a, ListReverseIterator<T> const &b){
	if (a.getPinter() != b.getPointer())
		return true;
	return false;
}

#endif
