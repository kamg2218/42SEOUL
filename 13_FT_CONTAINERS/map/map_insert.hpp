#include "../ft.hpp"

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::rotateLeft(ft::RBTNode<Key, T> *n){
	ft::RBTNode<Key, T> *tmp;
	ft::RBTNode<Key, T> *grand;

	//cout << "rotateLeft\n";
	grand = n->parent;
	tmp = n->right;
	if (n->parent->left == n){
		tmp->parent = grand;
		grand->left = tmp;
		n->right = tmp->left;
		if (tmp->left != &this->tail)
			tmp->left->parent = n;
		n->parent = tmp;
		tmp->left = n;
	}
	else{
		n->parent = grand->parent;
		if (grand->parent != &this->tail)
			grand->parent->right = n;
		grand->right = n->left;
		if (n->left != &this->tail)
			n->left->parent = grand;
		n->left = grand;
		grand->parent = n;
		if (head == grand)
			head = n;
	}
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::rotateRight(ft::RBTNode<Key, T> *n){
	ft::RBTNode<Key, T> *tmp;
	ft::RBTNode<Key, T> *grand;

	//cout << "rotateRight\n";
	if (n->parent == &this->tail)
		return ;
	grand = n->parent;
	tmp = n->left;
	if (n->parent->right == n){
		tmp->parent = grand;
		grand->right = tmp;
		n->left = tmp->right;
		if (tmp->right != &this->tail)
			tmp->right->parent = n;
		n->parent = tmp;
		tmp->right = n;
	}
	else{
		n->parent = grand->parent;
		if (grand->parent != &this->tail)
			grand->parent->left = n;
		grand->left = n->right;
		if (n->right != &this->tail)
			n->right->parent = grand;
		n->right = grand;
		grand->parent = n;
		if (head == grand)
			head = n;
	}
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::rebuild(ft::RBTNode<Key, T> *n){
	ft::RBTNode<Key, T> *tmp;
	ft::RBTNode<Key, T> *uncle;

	tmp = NULL;
	if (n->parent != &this->tail && n->parent->color == BLACK)
		return ;
	if (n->parent != &this->tail && n->parent->parent != &this->tail)
		tmp = n->parent->parent;
	if (tmp == &this->tail)
		uncle = NULL;
	else if (tmp->left == n->parent)
		uncle = tmp->right;
	else
		uncle = tmp->left;
	if (uncle != &this->tail && uncle->color == RED){
		n->parent->color = BLACK;
		uncle->color = BLACK;
		tmp->color = RED;
		if (this->head == tmp)
			this->head->color = BLACK;
		else if (this->head->color == RED)
			rebuild(tmp);
	}
	else{
		if (n->parent->right == n && n->parent == tmp->left){
			rotateLeft(n->parent);
			n = n->left;
		}
		else if (n->parent->left == n && n->parent == tmp->right){
			rotateRight(n->parent);
			n = n->right;
		}
		n->parent->color = BLACK;
		tmp->color = RED;
		if (n->parent->right == n)
			rotateLeft(n->parent);
		else
			rotateRight(n->parent);
	}
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::add_node(ft::RBTNode<Key, T>*	n){
	ft::RBTNode<Key, T>*	tmp;
	key_compare				cmp;

	tmp = this->head;
	if (tmp == &this->tail){
		n->color = BLACK;
		this->head = n;
	}
	else{
		while (tmp != &this->tail){
			if (cmp(n->value.second, tmp->value.second)){
				if (tmp->left == &this->tail)
					break ;
				tmp = tmp->left;
			}
			else{
				if (tmp->right == &this->tail)
					break ;
				tmp = tmp->right;
			}
		}
		if (cmp(n->value.second, tmp->value.second))
			tmp->left = n;
		else
			tmp->right = n;
		n->parent = tmp;
		rebuild(n);
	}
	sz++;
	this->tail.right = this->head;
	if (this->tail.left == &this->tail || cmp(this->tail.left->value.first, n->value.first))
		this->tail.left = n;
}
