#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../ft.hpp"

template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = RBTNode<Key, T>*, class Reference = RBTNode<Key, T>&>
class	MapIterator {
	protected:
		std::pair<Key, T>			*ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	
		ListIterator() : ptr(0) {}
		ListIterator(node<T>* const p) : ptr(p) {}
		ListIterator(ListIterator const &it) { *this = it; }
		ListIterator&	operator=(ListIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
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
		node<T>*	operator->() const { return ptr; }
		reference	getValue() const { return ptr->value; }
		node<T>*	getPointer() const { return ptr; }
};

template<class T>
bool	operator==(ListIterator<T> const &a, ListIterator<T> const &b){
	if (a.getPointer() == b.getPointer())
		return true;
	else
		return false;
}

template<class T>
bool	operator!=(ListIterator<T> const &a, ListIterator<T> const &b){
	if (a.getPointer() != b.getPointer())
		return true;
	else
		return false;
}

#endif
