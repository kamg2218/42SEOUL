#include "./map_insert.hpp"

//void	del(T value);

void	del_one(RBTNode<Key, T> *node, RBTNode<Key, T> *child){
	//cout << "del_one\n";
	if (child != tail)
		child->parent = node->parent;
	if (node->parent != tail && node->parent->left == node)
		node->parent->left = child;
	else if (node->parent != tail)
		node->parent->right = child;
	else
		*head = child;
}

void	del_left(RBTNode<Key, T> *node, RBTNode<Key, T> *child){
	int		col;
	RBTNode<Key, T> *sibling = 0;
	RBTNode<Key, T> *s_left = 0;
	RBTNode<Key, T> *s_right = 0;

	//cout << "del_left\n";
	if (node->parent != tail)
		sibling = node->parent->right;
	if (sibling != tail)
		s_left = sibling->left;
	if (sibling != tail)
		s_right = sibling->right;
	//parent->color == RED
	if (node->parent->color == RED){
		if (s_right != tail && s_right->color == RED){
			node->parent->color = BLACK;
			sibling->color = RED;
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(node->parent);
		}
		else if (s_left != tail && s_left->color == RED){
			sibling->color = RED;
			s_left->color = BLACK;
			rotateRight(node->parent);
		}
		else{
			node->parent->color = BLACK;
			if (sibling)
				sibling->color = RED;
		}
	}
	//parent->color == BLACK
	else{
		if (sibling->color == RED){
			node->parent->color = RED;
			sibling->color = BLACK;
			rotateLeft(node->parent);
			del_left(node, child);
		}
		else if (s_right != tail && s_right->color == RED){
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(node->parent);
		}
		else if (s_left != tail && s_left->color == BLACK){
			sibling->color = RED;
			del(node->parent->data);
		}
		else{
			//cout << "else\n";
			if (sibling != tail)
				sibling->color = RED;
			if (s_left != tail)
				s_left->color = BLACK;
			rotateRight(node->parent);
		}
	}
}

void	del_right(RBTNode<Key, T> *node, RBTNode<Key, T> *child){
	int		col;
	RBTNode<Key, T> *sibling = 0;
	RBTNode<Key, T> *s_left = 0;
	RBTNode<Key, T> *s_right = 0;

	//cout << "del_right\n";
	if (node->parent != tail)
		sibling = node->parent->left;
	if (sibling != tail)
		s_left = sibling->left;
	if (sibling != tail)
		s_right = sibling->right;
	//parent->color == RED
	if (node->parent != tail && node->parent->color == RED){
		if (s_right != tail && s_right->color == RED){
			node->parent->color = BLACK;
			sibling->color = RED;
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(node->parent);
		}
		else if (s_left != tail && s_left->color == BLACK){
			node->parent->color = BLACK;
			sibling->color = RED;
		}
		else if (s_left != tail && s_left->color == RED){
			sibling->color = RED;
			s_left->color = BLACK;
			node->parent->color = BLACK;
			rotateRight(node->parent);
		}
	}
	//parent->color == BLACK	
	else{
		if (sibling != tail && sibling->color == RED){
			node->parent->color = RED;
			sibling->color = BLACK;
			rotateRight(node->parent);
			del_right(node, child);
		}
		else if (s_right != tail && s_right->color == RED){
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(node->parent);
		}
		else if (s_left != tail && s_left->color == BLACK){
			sibling->color = RED;
			del(node->parent->data);
		}
		else{
			sibling->color = RED;
			if (s_left != tail)
				s_left->color = BLACK;
			rotateRight(node->parent);
		}
	}
}

void	one_node(RBTNode<Key, T> *node){
	RBTNode<Key, T> 	*child;
	allocator_type		alloc;

	//cout << "one_node " << node->data << "\n";
	child = NULL;
	if (node->right != tail)
		child = node->right;
	else if (node->left != tail)
		child = node->left;
	if (node->color == RED)
		del_one(node, child);
	else{
		//cout << "node is black\n";
		if (child != tail && child->color == RED)
			child->color = BLACK;
		else if (node->parent != tail && node->parent->left == node)
			del_left(node, child);
		else if (node->parent != tail)
			del_right(node, child);
		else
			*head = NULL;
		del_one(node, child);
	}
	alloc.deallocate(node, 1);
}

void	del(RBTNode<Key, T> *node){
	RBTNode<Key, T>	*tmp;

	if (node == tail)
		return ;
	else if (node->left != tail && node->right != tail){
		tmp = node->right;
		while (tmp->left != tail)
			tmp = tmp->left;
		node->value = tmp->value; //노드 바꾸기
		one_node(tmp);
	}
	else
		one_node(node);
}
