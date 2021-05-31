#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../ft.hpp"

template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = std::pair<Key, T>*, class Reference = std::pair<Key, T>&>
class	MapIterator {
	protected:
		RBTNode<Key, T>					*ptr;
	public:
		typedef Category				iterator_category;
		typedef std::pair<Key, T>		value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;

		MapIterator() : ptr(0) {}
		MapIterator(RBTNode<Key, T>* const p) : ptr(p) {}
		MapIterator(MapIterator const &it) { *this = it; }
		MapIterator&	operator=(MapIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~MapIterator() {}
		RBTNode<Key, T>*	upper(RBTNode<Key, T>* head){
			size_t				size;
			RBTNode<Key, T>**	tmp;
			RBTNode<Key, T>*	node;
			RBTNode<Key, T>*	rst;
			key_compare			cmp;

			size = 8;
			realloc(&tmp, 0, size);
			tmp[0] = head;
			rst = head;
			while (size_bfs(tmp) > 0){
				if (bfs_size(tmp) > size - 4){
					realloc(&tmp, size, size * 2);
					size *= 2;
				}
				for (size_t i = 0; i < bfs_size(tmp); i++){
					node = tmp[i];
					if (cmp(ptr->value.first, node->value.first)){
						if (rst == head || cmp(node->value.first, rst->value.first))
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
			if (rst == head){
				while (rst->right != head)
					rst = rst->right;
			}
			return rst;
		}
		RBTNode<Key, T>*	lower(RBTNode<Key, T>* head){
			size_t				size;
			RBTNode<Key, T>**	tmp;
			RBTNode<Key, T>*	node;
			RBTNode<Key, T>*	rst;
			//key_compare			cmp;

			size = 8;
			realloc(&tmp, 0, size);
			tmp[0] = head;
			rst = head;
			while (size_bfs(tmp) > 0){
				if (bfs_size(tmp) > size - 4){
					realloc(&tmp, size, size * 2);
					size *= 2;
				}
				for (size_t i = 0; i < bfs_size(tmp); i++){
					node = tmp[i];
					if ((ptr->value.first > node->value.first)){
						if (rst == head || (node->value.first > rst->value.first))
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
			if (rst == head){
				while (rst->right != head)
					rst = rst->right;
			}
			return rst;
		}
		RBTNode<Key, T>*	find_head(){
			RBTNode<Key, T>* tmp;

			tmp = ptr;
			while (tmp->parent)
				tmp = tmp->parent;
			return tmp;
		}
		
		MapIterator&	operator++(){
			this->ptr = upper(find_head());
			return *this;
		}
		MapIterator		operator++(int){
			this->ptr = upper(find_head());
			return (MapIterator(this->ptr));
		}
		MapIterator&	operator--(){
			this->ptr = lower(find_head());
			return *this;
		}
		MapIterator		operator--(int){
			this->ptr = lower(find_head());
			return MapIterator(this->ptr);
		}
		reference	operator*() const { return getValue(); }
		pointer		operator->() const { return getPointer(); }
		reference	getValue() const { return ptr->value; }
		pointer		getPointer() const { return ptr; }
};

template<class Key, class T>
bool	operator==(MapIterator<Key, T> const &a, MapIterator<Key, T> const &b){
	if (a.getValue().first == b.getValue().first)
		return true;
	else
		return false;
}

template<class Key, class T>
bool	operator!=(MapIterator<Key, T> const &a, MapIterator<Key, T> const &b){
	if (a.getValue().first != b.getValue().first)
		return true;
	else
		return false;
}

#endif
