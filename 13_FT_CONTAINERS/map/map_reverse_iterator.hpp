#ifndef LIST_REVERSE_ITERATOR_HPP
# define LIST_REVERSE_ITERATOR_HPP

#include "../ft.hpp"

template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = std::pair<Key, T>*, class Reference = std::pair<Key, T>&>
class	MapReverseIterator {
	protected:
		RBTNode<Key, T>					*ptr;
	public:
		typedef Category				iterator_category;
		typedef std::pair<Key, T>		value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;

		MapReverseIterator() : ptr(0) {}
		MapReverseIterator(RBTNode<Key, T>* const p) : ptr(p) {}
		MapReverseIterator(MapReverseIterator const &it) { *this = it; }
		MapReverseIterator&	operator=(MapReverseIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~MapReverseIterator() {}
		MapReverseIterator&		operator++(){
			this->ptr = lower_bound(ptr->value.first);
			return *this;
		}
		MapReverseIterator		operator++(int){
			this->ptr = lower_bound(ptr->value.first);
			return (MapReverseIterator(this->ptr));
		}
		MapReverseIterator&		operator--(){
			this->ptr = upper_bound(ptr->value.first);
			return *this;
		}
		MapReverseIterator		operator--(int){
			this->ptr = upper_bound(ptr->value.first);
			return MapReverseIterator(this->ptr);
		}
		reference	operator*() const { return getValue(); }
		pointer		operator->() const { return getPointer(); }
		reference	getValue() const { return ptr->value; }
		pointer		getPointer() const { return &(ptr->value); }
};

template<class Key, class T>
bool	operator==(MapReverseIterator<Key, T> const &a, MapReverseIterator<Key, T> const &b){
	if (a.getValue().first == b.getValue().first)
		return true;
	else
		return false;
}

template<class Key, class T>
bool	operator!=(MapReverseIterator<Key, T> const &a, MapReverseIterator<Key, T> const &b){
	if (a.getValue().first != b.getValue().first)
		return true;
	else
		return false;
}

#endif
