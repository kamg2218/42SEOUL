#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

template<class T, class Category = std::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ReverseIterator : public std::iterator<Category, T> {
	protected:
		node<T>*				ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;

		ReverseIterator() : ptr(0) {}
		ReverseIterator(node<T>* const p) : ptr(p) {}
		ReverseIterator(ReverseIterator const &rit) { *this = rit; }
		ReverseIterator&	operator=(ReverseIterator const &rit){
			if (&rit == this)
				return *this;
			this->ptr = rit.ptr;
			return *this;
		}
		~ReverseIterator() {}
		ReverseIterator&		operator++(){
			this->ptr = this->ptr->prev;
			return *this;
		}
		ReverseIterator&		operator++(int zero){
			zero = zero;
			this->ptr = this->ptr->prev;
			return *this;
		}
		ReverseIterator&		operator--(){
			this->ptr = this->ptr->next;
			return *this;
		}
		ReverseIterator&		operator--(int zero){
			zero = zero;
			this->ptr = this->ptr->next;
			return *this;
		}
		reference	operator*() const { return ptr->value; }
		reference	operator->() const { return ptr->value; }
		reference	getValue() const { return ptr->value; }
};

template<class T>
bool	operator==(ReverseIterator<T> const &a, ReverseIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(ReverseIterator<T> const &a, ReverseIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

#endif
