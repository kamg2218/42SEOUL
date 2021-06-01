#ifndef MAP_REVERSE_ITERATOR_HPP
# define MAP_REVERSE_ITERATOR_HPP

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
		RBTNode<Key, T>*	upper(RBTNode<Key, T>* head){
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
					if (cmp(ptr->value.first, node->value.first)){
						if (rst == head || (node->value.first < rst->value.first))
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
			while (tmp->parent != tmp->parent->left)
				tmp = tmp->parent;
			return tmp;
		}
		MapReverseIterator&		operator++(){
			this->ptr = lower(find_head());
			return *this;
		}
		MapReverseIterator		operator++(int){
			this->ptr = lower(find_head());
			return (MapReverseIterator(this->ptr));
		}
		MapReverseIterator&		operator--(){
			this->ptr = upper(find_head());
			return *this;
		}
		MapReverseIterator		operator--(int){
			this->ptr = upper(find_head());
			return MapReverseIterator(this->ptr);
		}
		reference	operator*() const { return getValue(); }
		pointer		operator->() const { return getPointer(); }
		reference	getValue() const { return ptr->value; }
		pointer		getPointer() const { return &(ptr->value); }
};

template<class Key, class T>
bool	operator==(MapReverseIterator<Key, T> const &a, MapReverseIterator<Key, T> const &b){
	if (a->first == b->first)
		return true;
	else
		return false;
}

template<class Key, class T>
bool	operator!=(MapReverseIterator<Key, T> const &a, MapReverseIterator<Key, T> const &b){
	if (a->first != b->first)
		return true;
	else
		return false;
}

#endif
