#ifndef MAP_REVERSE_ITERATOR_HPP
# define MAP_REVERSE_ITERATOR_HPP

#include "map_bfs.hpp"
template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = pair<Key, T>*, class Reference = pair<Key, T>&>
class	MapReverseIterator;
#include "map_const_reverse_iterator.hpp"

template<class Key, class T, class Category, class Distance, class Pointer, class Reference>
class	MapReverseIterator {
		typedef Category				iterator_category;
		typedef pair<Key, T>			value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;
	protected:
		RBTNode<Key, T>					*ptr;
	public:
		MapReverseIterator() : ptr(0) {}
		MapReverseIterator(RBTNode<Key, T>* const p) : ptr(p) {}
		MapReverseIterator(const MapReverseIterator &it) { *this = it; }
		MapReverseIterator(const MapConstReverseIterator<Key, T> &it) { *this = it; }
		MapReverseIterator&	operator=(const MapReverseIterator &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		MapReverseIterator&	operator=(const MapConstReverseIterator<Key, T> &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~MapReverseIterator() {}
		RBTNode<Key, T>*	upper(RBTNode<Key, T>* head){
			size_t				size;
			RBTNode<Key, T>**	tmp;
			RBTNode<Key, T>*	node;
			RBTNode<Key, T>*	rst;

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
		RBTNode<Key, T>*	lower(RBTNode<Key, T>* head){
			size_t				size;
			RBTNode<Key, T>**	tmp;
			RBTNode<Key, T>*	node;
			RBTNode<Key, T>*	rst;

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
		RBTNode<Key, T>*	find_head(){
			RBTNode<Key, T>* tmp;

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
		RBTNode<Key,T>*		getPointer() const { return ptr; }
};

template<class Key, class T>
bool	operator==(const MapReverseIterator<Key, T> &a, const MapReverseIterator<Key, T> &b){
	if (a->first == b->first && a->second == b->second)
		return true;
	return false;
}

template<class Key, class T>
bool	operator==(const MapReverseIterator<Key, T> &a, const MapConstReverseIterator<Key, T> &b){
	if (a->first == b->first && a->second == b->second)
		return true;
	return false;
}

template<class Key, class T>
bool	operator!=(const MapReverseIterator<Key, T> &a, const MapReverseIterator<Key, T> &b){
	if (a->first == b->first && a->second == b->second)
		return false;
	return true;
}

template<class Key, class T>
bool	operator!=(const MapReverseIterator<Key, T> &a, const MapConstReverseIterator<Key, T> &b){
	if (a->first == b->first && a->second == b->second)
		return false;
	return true;
}

#endif
