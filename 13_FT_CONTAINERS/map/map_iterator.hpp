#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../ft.hpp"
#include "test_bfs.hpp"

template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = std::pair<Key, T>*, class Reference = std::pair<Key, T>&>
class	MapIterator {
	protected:
		ft::RBTNode<Key, T>				*ptr;
	public:
		typedef Category				iterator_category;
		typedef std::pair<Key, T>		value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;

		MapIterator() : ptr(0) {}
		MapIterator(ft::RBTNode<Key, T>* const p) : ptr(p) {}
		MapIterator(MapIterator const &it) { *this = it; }
		MapIterator&	operator=(MapIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~MapIterator() {}
		ft::RBTNode<Key, T>*	upper(ft::RBTNode<Key, T>* h){
			size_t					size;
			ft::RBTNode<Key, T>**	tmp;
			ft::RBTNode<Key, T>*	n;
			ft::RBTNode<Key, T>*	rst;
			//key_compare			cmp;

			std::cout << "upper = " << h->value.first << std::endl;
			size = 8;
			realloc(&tmp, 0, size);
			tmp[0] = h;
			rst = h;
			while (size_bfs(tmp) > 0){
				if (size_bfs(tmp) > size - 4){
					realloc(&tmp, size, size * 2);
					size *= 2;
				}
				for (size_t i = 0; i < size_bfs(tmp); i++){
					n = tmp[i];
					//if (cmp(ptr->value.first, n->value.first)){
					if ((ptr->value.first < n->value.first)){
						if (rst == h || (n->value.first < rst->value.first))
							rst = n;
					}
					if (n->left->right != h)
						i += move_bfs(tmp, i, n->left);
					if (n->right->right != h)
						i += move_bfs(tmp, i, n->right);
					del_bfs(tmp, i);
					i--;
				}
			}
			delete [] tmp;
			if (rst == h){
				while (rst->right != h)
					rst = rst->right;
			}
			return rst;
		}
		ft::RBTNode<Key, T>*	lower(ft::RBTNode<Key, T>* h){
			size_t					size;
			ft::RBTNode<Key, T>**	tmp;
			ft::RBTNode<Key, T>*	n;
			ft::RBTNode<Key, T>*	rst;
			//key_compare			cmp;

			size = 8;
			realloc(&tmp, 0, size);
			tmp[0] = h;
			rst = h;
			while (size_bfs(tmp) > 0){
				if (size_bfs(tmp) > size - 4){
					realloc(&tmp, size, size * 2);
					size *= 2;
				}
				for (size_t i = 0; i < size_bfs(tmp); i++){
					n = tmp[i];
					if ((ptr->value.first > n->value.first)){
						if (rst == h || (n->value.first > rst->value.first))
							rst = n;
					}
					if (n->left->right != h)
						i += move_bfs(tmp, i, n->left);
					if (n->right->right != h)
						i += move_bfs(tmp, i, n->right);
					del_bfs(tmp, i);
					i--;
				}
			}
			delete [] tmp;
			if (rst == h){
				while (rst->right != h)
					rst = rst->right;
			}
			return rst;
		}
		ft::RBTNode<Key, T>*	find_head(){
			ft::RBTNode<Key, T>* tmp;
			
			std::cout << "find_head\n";
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
		pointer		getPointer() const { return &(ptr->value); }
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
