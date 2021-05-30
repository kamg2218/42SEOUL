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
		/*
		iterator	upper_bound(const Key& key){
			size_t					cnt;
			iterator				it;
			RBTNode<value_type>**	tmp;
			RBTNode<value_type>*	node;
			key_compare				cmp;

			cnt = 1;
			while (cnt <= sz)
				cnt = (cnt + 1) * 2 - 1;
			tmp = make_bfs(cnt);
			tmp[0] = head;
			it = end();
			while (size_bfs(tmp) > 0){
				for (size_t i = 0; i < bfs_size(tmp); i++){
					node = tmp[i];
					if (cmp(key, node->value.first)){
						if (it == end() || cmp(node->value.first, (*it).first))
							it = iterator(node);
					}
					if (node->left != tail)
						i += move_bfs(tmp, i, node->left);
					if (node->right != tail)
						i += move_bfs(tmp, i, node->right);
					del_bfs(tmp, i);
					i--;
				}
			}
			delete [] tmp;
			return (it);
		}
		*/
		iterator		upper_bound(){
		
		}
		MapIterator&	operator++(){
			this->ptr = upper_bound();
			return *this;
		}
		MapIterator		operator++(int){
			this->ptr = upper_bound(ptr->value.first);
			return (MapIterator(this->ptr));
		}
		MapIterator&	operator--(){
			this->ptr = lower_bound(ptr->value.first);
			return *this;
		}
		MapIterator		operator--(int){
			this->ptr = lower_bound(ptr->value.first);
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
