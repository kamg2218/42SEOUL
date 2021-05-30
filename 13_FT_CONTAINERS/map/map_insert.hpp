#include "../ft.hpp"

void	rotateLeft(RBTNode<Key, T> *node){
	RBTNode<Key, T> *tmp;
	RBTNode<Key, T> *grand;

	//cout << "rotateLeft\n";
	grand = node->parent;
	tmp = node->right;
	if (node->parent->left == node){
		tmp->parent = grand;
		grand->left = tmp;
		node->right = tmp->left;
		if (tmp->left != tail)
			tmp->left->parent = node;
		node->parent = tmp;
		tmp->left = node;
	}
	else{
		node->parent = grand->parent;
		if (grand->parent != tail)
			grand->parent->right = node;
		grand->right = node->left;
		if (node->left != tail)
			node->left->parent = grand;
		node->left = grand;
		grand->parent = node;
		if (head == grand)
			head = node;
	}
}

void	rotateRight(RBTNode<Key, T> *node){
	RBTNode<Key, T> *tmp;
	RBTNode<Key, T> *grand;

	//cout << "rotateRight\n";
	if (node->parent == tail)
		return ;
	grand = node->parent;
	tmp = node->left;
	if (node->parent->right == node){
		tmp->parent = grand;
		grand->right = tmp;
		node->left = tmp->right;
		if (tmp->right != tail)
			tmp->right->parent = node;
		node->parent = tmp;
		tmp->right = node;
	}
	else{
		node->parent = grand->parent;
		if (grand->parent != tail)
			grand->parent->left = node;
		grand->left = node->right;
		if (node->right != tail)
			node->right->parent = grand;
		node->right = grand;
		grand->parent = node;
		if (head == grand)
			head = node;
	}
}

void	rebuild(RBTNode<Key, T> *node){
	RBTNode<Key, T> *tmp;
	RBTNode<Key, T> *uncle;

	tmp = NULL;
	if (node->parent != tail && node->parent->color == BLACK)
		return ;
	if (node->parent != tail && node->parent->parent)
		tmp = node->parent->parent;
	if (tmp == tail)
		uncle = NULL;
	else if (tmp->left == node->parent)
		uncle = tmp->right;
	else
		uncle = tmp->left;
	if (uncle != tail && uncle->color == RED){
		node->parent->color = BLACK;
		uncle->color = BLACK;
		tmp->color = RED;
		if (head == tmp)
			head->color = BLACK;
		else if (head->color == RED)
			rebuild(tmp);
	}
	else{
		if (node->parent->right == node && node->parent == tmp->left){
			rotateLeft(node->parent);
			node = node->left;
		}
		else if (node->parent->left == node && node->parent == tmp->right){
			rotateRight(node->parent);
			node = node->right;
		}
		node->parent->color = BLACK;
		tmp->color = RED;
		if (node->parent->right == node)
			rotateLeft(node->parent);
		else
			rotateRight(node->parent);
	}
}

void	add_node(RBTNode<Key, T>*	node){
	RBTNode<Key, T>*	tmp;
	key_compare			cmp;

	tmp = head;
	if (tmp == tail){
		node->color = BLACK;
		*head = node;
	}
	else{
		while (tmp != tail){
			if (cmp(node->value.second, tmp->value.second)){
				if (tmp->left == NULL)
					break ;
				tmp = tmp->left;
			}
			else{
				if (tmp->right == NULL)
					break ;
				tmp = tmp->right;
			}
		}
		if (cmp(node->value.second, tmp->value.second))
			tmp->left = node;
		else
			tmp->right = node;
		node->parent = tmp;
		rebuild(node);
	}
	sz++;
	tail->right = head;
	if (!tail->left || cmp(tail->left->value.first, node->value.first))
		tail->left = node;
}
