#ifndef LIST_REVERSE_ITERATOR_HPP
# define LIST_REVERSE_ITERATOR_HPP

#include "../ft.hpp"

template<class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ListReverseIterator : public ListConstReverseIterator<T>{
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;

		ListReverseIterator() : ListConstReverseIterator<T>(0) {}
		ListReverseIterator(node<T>* const p) : ListConstReverseIterator<T>(p) {}
		ListReverseIterator(ListReverseIterator const &rit) { *this = rit; }
		ListReverseIterator&	operator=(ListReverseIterator const &rit){
			if (&rit == this)
				return *this;
			this->ptr = rit.ptr;
			return *this;
		}
		ListReverseIterator&	operator=(ListConstReverseIterator<T> const &rit){
			if (&rit == this)
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
