#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "map_bfs.hpp"
template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = pair<Key, T>*, class Reference = pair<Key, T>&>
class	MapIterator;
#include "map_const_iterator.hpp"

template<class Key, class T, class Category, class Distance, class Pointer, class Reference>
class	MapIterator {
		typedef Category				iterator_category;
		typedef pair<Key, T>			value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;
	protected:
		RBTNode<Key, T>					*ptr;
	public:
		MapIterator() : ptr(0) {}
		MapIterator(RBTNode<Key, T>* const p) : ptr(p) {}
		MapIterator(const MapIterator &it) { *this = it; }
		MapIterator(const MapConstIterator<Key, T> &it) { *this = it; }
		MapIterator&	operator=(const MapIterator &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		MapIterator&	operator=(const MapConstIterator<Key, T> &it){
			if (this->ptr == it.getPointer())
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		~MapIterator() {}
		RBTNode<Key, T>*	upper(RBTNode<Key, T>* h){
			size_t				size;
			RBTNode<Key, T>**	tmp;
			RBTNode<Key, T>*	n;
			RBTNode<Key, T>*	rst;

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
		RBTNode<Key, T>*	lower(RBTNode<Key, T>* h){
			size_t				size;
			RBTNode<Key, T>**	tmp;
			RBTNode<Key, T>*	n;
			RBTNode<Key, T>*	rst;

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
		RBTNode<Key, T>*	find_head(){
			RBTNode<Key, T>* tmp;

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
		reference				operator*() { return getValue(); }
		pointer					operator->() { return &getValue(); }
		reference				getValue() const { return ptr->value; }
		RBTNode<Key,T>*			getPointer() const { return ptr; }
};

template<class Key, class T>
bool	operator==(const MapIterator<Key, T> &a, const MapIterator<Key, T> &b){
	return a.getValue() == b.getValue();
}

template<class Key, class T>
bool	operator==(const MapIterator<Key, T> &a, const MapConstIterator<Key, T> &b){
	return a.getValue() == b.getValue();
}

template<class Key, class T>
bool	operator!=(const MapIterator<Key, T> &a, const MapIterator<Key, T> &b){
	return a.getValue() != b.getValue();
}

template<class Key, class T>
bool	operator!=(const MapIterator<Key, T> &a, const MapConstIterator<Key, T> &b){
	return a.getValue() != b.getValue();
}

#endif
