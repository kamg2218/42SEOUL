#include "../ft.hpp"

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::rotateRight(ft::RBTNode<Key, T> *n){
	RBTNode<Key, T>*	leftChild = n->left;

	n->left = leftChild->right;
	if (leftChild->right != leftChild->last)
		leftChild->right->parent = n;
	leftChild->parent = n->parent;
	if (n->parent == n->last)
		this->head = leftChild;
	else
	{
		if (n == n->parent->left)
			n->parent->left = leftChild;
		else
			n->parent->right = leftChild;
	}
	leftChild->right = n;
	n->parent = leftChild;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::rotateLeft(ft::RBTNode<Key, T> *n){
	ft::RBTNode<Key, T>*	rightChild = n->right;

	n->right = rightChild->left;
	if (rightChild->left != rightChild->last)
		rightChild->left->parent = n;
	rightChild->parent = n->parent;
	if (n->parent == n->last)
		this->head = rightChild;
	else
	{
		if (n == n->parent->right)
			n->parent->right = rightChild;
		else
			n->parent->left = rightChild;
	}
	rightChild->left = n;
	n->parent = rightChild;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::rebuild(ft::RBTNode<Key, T> *n){
	RBTNode<Key, T>*	tmp;

	while (n != this->head && n->parent->color == RED){
		if (n->parent == n->parent->parent->left){
			tmp = n->parent->parent->right;
			if (tmp && tmp->color == RED){
				n->parent->color = BLACK;
				tmp->color = BLACK;
				n->parent->parent->color = RED;
			}
			else{
				if (n == n->parent->right){
					n = n->parent;
					rotateLeft(n);
				}
				n->parent->color = BLACK;
				n->parent->parent->color = RED;
				rotateRight(n->parent->parent);
			}
		}
		else{
			tmp = n->parent->parent->left;
			if (tmp && tmp->color == RED){
				n->parent->color = BLACK;
				tmp->color = BLACK;
				n->parent->parent->color = RED;
			}
			else{
				if (n == n->parent->left){
					n = n->parent;
					rotateRight(n);
				}
				n->parent->color = BLACK;
				n->parent->parent->color = RED;
				rotateLeft(n->parent->parent);
			}
		}
	}
	(*head)->color = BLACK;
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
	if (this->tail.right == &this->tail || cmp(n->value.first, this->tail.right->value.first))
		this->tail.right = this->head;
	if (this->tail.left == &this->tail || cmp(this->tail.left->value.first, n->value.first))
		this->tail.left = n;
}
