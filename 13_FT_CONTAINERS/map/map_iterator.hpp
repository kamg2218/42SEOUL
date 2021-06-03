#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../ft.hpp"
#include "test_bfs.hpp"

template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = std::pair<Key, T>*, class Reference = std::pair<Key, T>&>
class	MapIterator : public MapConstIterator<Key, T>{
	public:
		typedef Category				iterator_category;
		typedef std::pair<Key, T>		value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;

		MapIterator() : MapConstIterator<Key, T>(0) {}
		MapIterator(ft::RBTNode<Key, T>* const p) : MapConstIterator<Key, T>(p) {}
		MapIterator(MapIterator const &it) { *this = it; }
		MapIterator&	operator=(MapIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		MapIterator&	operator=(MapConstIterator<Key, T> const &it){
			if (&it == this)
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		~MapIterator() {}
		MapIterator&	operator++(){
			this->ptr = this->upper(this->find_head());
			return *this;
		}
		MapIterator		operator++(int){
			this->ptr = this->upper(this->find_head());
			return (MapIterator(this->ptr));
		}
		MapIterator&	operator--(){
			this->ptr = this->lower(this->find_head());
			return *this;
		}
		MapIterator		operator--(int){
			this->ptr = this->lower(this->find_head());
			return MapIterator(this->ptr);
		}
		reference	operator*() const { return getValue(); }
		pointer		operator->() const { return getPointer(); }
		reference	getValue() const { return this->ptr->value; }
		pointer		getPointer() const { return &(this->ptr->value); }
};

template<class Key, class T>
bool	operator==(MapIterator<Key, T> const &a, MapIterator<Key, T> const &b){
	if (a->first == b->first)
		return true;
	else
		return false;
}

template<class Key, class T>
bool	operator!=(MapIterator<Key, T> const &a, MapIterator<Key, T> const &b){
	if (a->first != b->first)
		return true;
	else
		return false;
}

#endif
