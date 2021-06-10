#ifndef MAP_BFS_HPP
# define MAP_BFS_HPP

#include "map.hpp"

template <class Key, class T>
int		size_bfs(RBTNode<Key, T>** tmp){
	int		len;

	len = 0;
	while (tmp[len])
		len++;
	return len;
}

template <class Key, class T>
int		move_bfs(RBTNode<Key, T>** tmp, int location, RBTNode<Key, T>* node){
	for (size_t i = size_bfs(tmp); i > location; i--)
		tmp[i] = tmp[i - 1];
	tmp[location] = node;
	return 1;
}

template <class Key, class T>
void	del_bfs(RBTNode<Key, T>** tmp, int location){
	for (size_t i = location; i < size_bfs(tmp); i++)
		tmp[i] = tmp[i + 1];
}

template <class Key, class T>
void	realloc(RBTNode<Key, T>*** node, size_t from, size_t to){
	RBTNode<Key, T>**	tmp;

	tmp = new RBTNode<Key, T>*[to];
	for (size_t i = 0; i < to; i++){
		if (i < from)
			tmp[i] = *node[i];
		else
			tmp[i] = 0;
	}
	if (from > 0)
		delete [] *node;
	*node = tmp;
}

template <class Key, class T>
size_t		bfs(RBTNode<Key, T> **head){
	size_t					size = 8;
	size_t					cnt = 0;
	RBTNode<Key, T>**		tmp = 0;
	RBTNode<Key, T>*		a;

	realloc(&tmp, 0, 8);
	tmp[0] = *head;
	while (size_bfs(tmp) > 0){
		cnt++;
		for (int i = 0; i < size_bfs(tmp); i++){
			if (size_bfs(tmp) >= size - 4){
				realloc(&tmp, size, size * 2);
				size *= 2;
			}
			a = tmp[i];
			if (a->left)
				i += move_tmp(tmp, i, a->left);
			if (a->right)
				i += move_tmp(tmp, i, a->right);
			del_tmp(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return cnt;
}

#endif
