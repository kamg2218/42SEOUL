#ifndef MAP_REVERSE_ITERATOR_HPP
# define MAP_REVERSE_ITERATOR_HPP

#include "map_bfs.hpp"
template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = std::pair<Key, T>*, class Reference = std::pair<Key, T>&>
class	MapReverseIterator;
#include "map_const_reverse_iterator.hpp"

template<class Key, class T, class Category, class Distance, class Pointer, class Reference>
class	MapReverseIterator {
		typedef Category				iterator_category;
		typedef std::pair<Key, T>		value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;
	protected:
		ft::RBTNode<Key, T>				*ptr;
	public:
		MapReverseIterator() : ptr(0) {}
		MapReverseIterator(ft::RBTNode<Key, T>* const p) : ptr(p) {}
		MapReverseIterator(MapReverseIterator const &it) { *this = it; }
		MapReverseIterator(MapConstReverseIterator<Key, T> const &it) { *this = it; }
		MapReverseIterator&	operator=(MapReverseIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		MapReverseIterator&	operator=(MapConstReverseIterator<Key, T> const &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~MapReverseIterator() {}
		ft::RBTNode<Key, T>*	upper(ft::RBTNode<Key, T>* head){
			size_t					size;
			ft::RBTNode<Key, T>**	tmp;
			ft::RBTNode<Key, T>*	node;
			ft::RBTNode<Key, T>*	rst;

			size = 8;
			realloc(&tmp, 0, size);
			tmp[0] = head;
			rst = ptr;
			while (size_bfs(tmp) > 0){
				if (bfs_size(tmp) > size - 4){
					realloc(&tmp, size, size * 2);
					size *= 2;
				}
				for (size_t i = 0; i < bfs_size(tmp); i++){
					node = tmp[i];
					if (ptr->value.first < node->value.first){
						if (rst == ptr || (node->value.first < rst->value.first))
							rst = node;
					}
					if (node->left != head)
						i += move_bfs(tmp, i, node->left);
					if (node->right != head)
						i += move_bfs(tmp, i, node->right);
					del_bfs(tmp, i);
					i--;
				}
			}
			delete [] tmp;
			if (rst == ptr)
				rst = node->last;
			return rst;
		}
		ft::RBTNode<Key, T>*	lower(ft::RBTNode<Key, T>* head){
			size_t					size;
			ft::RBTNode<Key, T>**	tmp;
			ft::RBTNode<Key, T>*	node;
			ft::RBTNode<Key, T>*	rst;

			size = 8;
			realloc(&tmp, 0, size);
			tmp[0] = head;
			rst = ptr;
			while (size_bfs(tmp) > 0){
				if (size_bfs(tmp) > size - 4){
					realloc(&tmp, size, size * 2);
					size *= 2;
				}
				for (size_t i = 0; i < bfs_size(tmp); i++){
					node = tmp[i];
					if ((ptr->value.first > node->value.first)){
						if (rst == ptr || (node->value.first > rst->value.first))
							rst = node;
					}
					if (node->left->right != head)
						i += move_bfs(tmp, i, node->left);
					if (node->right->right != head)
						i += move_bfs(tmp, i, node->right);
					del_bfs(tmp, i);
					i--;
				}
			}
			delete [] tmp;
			if (rst == ptr)
				rst = node->last;
			return rst;
		}
		ft::RBTNode<Key, T>*	find_head(){
			ft::RBTNode<Key, T>* tmp;

			tmp = ptr;
			while (tmp->parent != tmp->last)
				tmp = tmp->parent;
			return tmp;
		}
		MapReverseIterator&		operator++(){
			if (this->ptr)
				this->ptr = lower(find_head());
			return *this;
		}
		MapReverseIterator		operator++(int){
			if (this->ptr)
				this->ptr = lower(find_head());
			return (MapReverseIterator(this->ptr));
		}
		MapReverseIterator&		operator--(){
			if (this->ptr)
				this->ptr = upper(find_head());
			return *this;
		}
		MapReverseIterator		operator--(int){
			if (this->ptr)
				this->ptr = upper(find_head());
			return MapReverseIterator(this->ptr);
		}
		reference			operator*() const { return getValue(); }
		pointer				operator->() const { return &getValue(); }
		reference			getValue() const { return ptr->value; }
		ft::RBTNode<Key,T>*	getPointer() const { return ptr; }
};

template<class Key, class T>
bool	operator==(MapReverseIterator<Key, T> const &a, MapReverseIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return true;
	return false;
}

template<class Key, class T>
bool	operator==(MapReverseIterator<Key, T> const &a, MapConstReverseIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return true;
	return false;
}

template<class Key, class T>
bool	operator!=(MapReverseIterator<Key, T> const &a, MapReverseIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return false;
	return true;
}

template<class Key, class T>
bool	operator!=(MapReverseIterator<Key, T> const &a, MapConstReverseIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return false;
	return true;
}

#endif
