#ifndef MAP_CONST_ITERATOR_HPP
# define MAP_CONST_ITERATOR_HPP

#include "../ft.hpp"
#include "test_bfs.hpp"
template<class Key, class T, class Category = ft::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = std::pair<Key, T>*, class Reference = std::pair<Key, T>&>
class MapConstIterator;
#include "map_iterator.hpp"

template<class Key, class T, class Category, class Distance, class Pointer, class Reference>
class	MapConstIterator {
	protected:
		ft::RBTNode<Key, T>				*ptr;
	public:
		typedef Category				iterator_category;
		typedef std::pair<Key, T>		value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;

		MapConstIterator() : ptr(0) {}
		MapConstIterator(ft::RBTNode<Key, T>* p) : ptr(p) {}
		MapConstIterator(MapConstIterator const &it) { *this = it; }
		MapConstIterator(MapIterator<Key, T> const &it) { *this = it; }
		MapConstIterator&	operator=(MapConstIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		MapConstIterator&	operator=(MapIterator<Key, T> const &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		~MapConstIterator() {}
		ft::RBTNode<Key, T>*	upper(ft::RBTNode<Key, T>* h){
			size_t					size;
			ft::RBTNode<Key, T>**	tmp;
			ft::RBTNode<Key, T>*	n;
			ft::RBTNode<Key, T>*	rst;
			std::less<Key>			cmp;

			//std::cout << "upper = " << h->value.first << std::endl;
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
					if (cmp(ptr->value.first, n->value.first)){
						if (rst == ptr || cmp(n->value.first, rst->value.first))
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
			//key_compare			cmp;

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
					if (n->left->right != n->last)
						i += move_bfs(tmp, i, n->left);
					if (n->right->right != n->last)
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
			
			//std::cout << "find_head\n";
			tmp = ptr;
			while (tmp->parent != tmp->last)
				tmp = tmp->parent;
			return tmp;
		}
		
		MapConstIterator&	operator++(){
			this->ptr = upper(find_head());
			return *this;
		}
		MapConstIterator		operator++(int){
			this->ptr = upper(find_head());
			return (MapConstIterator(this->ptr));
		}
		MapConstIterator&	operator--(){
			this->ptr = lower(find_head());
			return *this;
		}
		MapConstIterator		operator--(int){
			this->ptr = lower(find_head());
			return MapConstIterator(this->ptr);
		}
		const reference			operator*() const { return getValue(); }
		const pointer			operator->() const { return &getValue(); }
		reference				getValue() const { return ptr->value; }
		ft::RBTNode<Key,T>*		getPointer() const { return ptr; }
};

template<class Key, class T>
bool	operator==(MapConstIterator<Key, T> const &a, MapConstIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return true;
	else
		return false;
}

template<class Key, class T>
bool	operator==(MapConstIterator<Key, T> const &a, MapIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return true;
	else
		return false;
}

template<class Key, class T>
bool	operator!=(MapConstIterator<Key, T> const &a, MapConstIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return false;
	else
		return true;
}

template<class Key, class T>
bool	operator!=(MapConstIterator<Key, T> const &a, MapIterator<Key, T> const &b){
	if (a->first == b->first && a->second == b->second)
		return false;
	else
		return true;
}

#endif
