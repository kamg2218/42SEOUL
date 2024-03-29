#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "map_bfs.hpp"
template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = std::pair<Key, T>*, class Reference = std::pair<Key, T>&>
class	MapIterator;
#include "map_const_iterator.hpp"

template<class Key, class T, class Category, class Distance, class Pointer, class Reference>
class	MapIterator {
		typedef Category				iterator_category;
		typedef std::pair<Key, T>		value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;
	protected:
		ft::RBTNode<Key, T>				*ptr;
	public:
		MapIterator() : ptr(0) {}
		MapIterator(ft::RBTNode<Key, T>* const p) : ptr(p) {}
		MapIterator(MapIterator const &it) { *this = it; }
		MapIterator(MapConstIterator<Key, T> const &it) { *this = it; }
		MapIterator&	operator=(MapIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		MapIterator&	operator=(MapConstIterator<Key, T> const &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		~MapIterator() {}
		ft::RBTNode<Key, T>*	upper(ft::RBTNode<Key, T>* h){
			size_t					size;
			ft::RBTNode<Key, T>**	tmp;
			ft::RBTNode<Key, T>*	n;
			ft::RBTNode<Key, T>*	rst;

			size = 8;
			realloc(&tmp, 0, size);
			tmp[0] = h;
			rst = ptr;
			while (size_bfs(tmp) > 0){
				if (size_bfs(tmp) > size - 4){
					realloc(&tmp, size, size * 2);
					size *= 2;
				}
				for (size_t i = 0; i < size_bfs(tmp); i++){
					n = tmp[i];
					if ((ptr->value.first < n->value.first)){
						if (rst == ptr || (n->value.first < rst->value.first))
							rst = n;
					}
					if (n->left != n->last)
						i += move_bfs(tmp, i, n->left);
					if (n->right != n->last)
						i += move_bfs(tmp, i, n->right);
					del_bfs(tmp, i);
					i--;
				}
			}
			delete [] tmp;
			if (rst == ptr)
				rst = n->last;
			return rst;
		}
		ft::RBTNode<Key, T>*	lower(ft::RBTNode<Key, T>* h){
			size_t					size;
			ft::RBTNode<Key, T>**	tmp;
			ft::RBTNode<Key, T>*	n;
			ft::RBTNode<Key, T>*	rst;

			size = 8;
			realloc(&tmp, 0, size);
			tmp[0] = h;
			rst = ptr;
			while (size_bfs(tmp) > 0){
				if (size_bfs(tmp) > size - 4){
					realloc(&tmp, size, size * 2);
					size *= 2;
				}
				for (size_t i = 0; i < size_bfs(tmp); i++){
					n = tmp[i];
					if ((ptr->value.first > n->value.first)){
						if (rst == ptr || (n->value.first > rst->value.first))
							rst = n;
					}
					if (n->left != n->last)
						i += move_bfs(tmp, i, n->left);
					if (n->right != n->last)
						i += move_bfs(tmp, i, n->right);
					del_bfs(tmp, i);
					i--;
				}
			}
			delete [] tmp;
			if (rst == ptr)
				rst = n->last;
			return rst;
		}
		ft::RBTNode<Key, T>*	find_head(){
			ft::RBTNode<Key, T>* tmp;

			tmp = ptr;
			while (tmp && tmp->parent != tmp->last)
				tmp = tmp->parent;
			return tmp;
		}
		MapIterator&	operator++(){
			if (this->ptr)
				this->ptr = this->upper(this->find_head());
			return *this;
		}
		MapIterator		operator++(int){
			if (this->ptr)
				this->ptr = this->upper(this->find_head());
			return (MapIterator(this->ptr));
		}
		MapIterator&	operator--(){
			if (this->ptr && this->ptr == this->ptr->last)
				this->ptr = this->ptr->left;
			else if (this->ptr)
				this->ptr = this->lower(this->find_head());
			return *this;
		}
		MapIterator		operator--(int){
			if (this->ptr && this->ptr == this->ptr->last)
				this->ptr = this->ptr->left;
			else if (this->ptr)
				this->ptr = this->lower(this->find_head());
			return MapIterator(this->ptr);
		}
		reference				operator*() const { return getValue(); }
		pointer					operator->() const { return &getValue(); }
		reference				getValue() const { return this->ptr->value; }
		ft::RBTNode<Key,T>*		getPointer() const { return this->ptr; }
};

template<class Key, class T>
bool	operator==(MapIterator<Key, T> const &a, MapIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return true;
	return false;
}

template<class Key, class T>
bool	operator==(MapIterator<Key, T> const &a, MapConstIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return true;
	return false;
}

template<class Key, class T>
bool	operator!=(MapIterator<Key, T> const &a, MapIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return false;
	return true;
}

template<class Key, class T>
bool	operator!=(MapIterator<Key, T> const &a, MapConstIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return false;
	return true;
}

#endif
