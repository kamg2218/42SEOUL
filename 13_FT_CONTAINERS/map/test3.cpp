#include <iostream>
using namespace std;

enum Color { RED, BLACK };
typedef struct RBTNode{
	int				data;
	enum Color		color;
	struct RBTNode*	parent;
	struct RBTNode*	left;
	struct RBTNode*	right;
}RBTNode;

void	del(RBTNode **head, int data);

RBTNode*	new_node(int data){
	RBTNode*	tmp;

	tmp = new RBTNode;
	tmp->data = data;
	tmp->color = RED;
	tmp->parent = 0;
	tmp->left = 0;
	tmp->right = 0;
	return tmp;
}

void	traverse(RBTNode* head){
	if (head->left)
		traverse(head->left);
	std::cout << head->data << std::endl;
	if (head->right)
		traverse(head->right);
}

void rotateRight(RBTNode** root, RBTNode* parent)
{
	RBTNode* leftChild = parent->left;

	parent->left = leftChild->right;
	
	if (leftChild->right != NULL)
		leftChild->right->parent = parent;

	leftChild->parent = parent->parent;

	if (parent->parent == NULL)
		(*root) = leftChild;
	else
	{
		if (parent == parent->parent->left)
			parent->parent->left = leftChild;
		else
			parent->parent->right = leftChild;
	}
	leftChild->right = parent;
	parent->parent = leftChild;

}

void rotateLeft(RBTNode** root, RBTNode* parent)
{
	RBTNode* rightChild = parent->right;

	parent->right = rightChild->left;

	if (rightChild->left != NULL)
		rightChild->left->parent = parent;

	rightChild->parent = parent->parent;

	if (parent->parent == NULL)
		(*root) = rightChild;
	else
	{
		if (parent == parent->parent->right)
			parent->parent->right = rightChild;
		else
			parent->parent->left = rightChild;
	}
	rightChild->left = parent;
	parent->parent = rightChild;

}

void	rebuild(RBTNode** head, RBTNode* src){
	RBTNode*	tmp;

	while (src != *head && src->parent->color == RED){
		if (src->parent == src->parent->parent->left){
			tmp = src->parent->parent->right;
			if (tmp && tmp->color == RED){
				src->parent->color = BLACK;
				tmp->color = BLACK;
				src->parent->parent->color = RED;
			}
			else{
				if (src == src->parent->right){
					src = src->parent;
					rotateLeft(head, src);
				}
				src->parent->color = BLACK;
				src->parent->parent->color = RED;
				rotateRight(head, src->parent->parent);
			}
		}
		else{
			tmp = src->parent->parent->left;
			if (tmp && tmp->color == RED){
				src->parent->color = BLACK;
				tmp->color = BLACK;
				src->parent->parent->color = RED;
			}
			else{
				if (src == src->parent->left){
					src = src->parent;
					rotateRight(head, src);
				}
				src->parent->color = BLACK;
				src->parent->parent->color = RED;
				rotateLeft(head, src->parent->parent);
			}
		}
	}
	(*head)->color = BLACK;
}

void	insert(RBTNode** head, RBTNode*	node){
	RBTNode*	tmp;

	tmp = *head;
	if (tmp == 0){
		node->color = BLACK;
		*head = node;
		return ;
	}
	while (tmp){
		if (tmp->data > node->data){
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
	if (tmp->data > node->data)
		tmp->left = node;
	else
		tmp->right = node;
	node->parent = tmp;
	rebuild(head, node);
}

int		bfs_size(RBTNode** tmp){
	int		len;

	len = 0;
	while (tmp[len])
		len++;
	return len;
}

int		move_tmp(RBTNode** tmp, int location, RBTNode* node){
	for (int i = bfs_size(tmp); i > location; i--)
		tmp[i] = tmp[i - 1];
	tmp[location] = node;
	return 1;
}

void	del_tmp(RBTNode **tmp, int location){
	for (int i = location; i < bfs_size(tmp); i++)
		tmp[i] = tmp[i + 1];
}

void	bfs(RBTNode **head){
	RBTNode*	tmp[100] = {0, };
	RBTNode*	a;

	tmp[0] = *head;
	while (bfs_size(tmp) > 0){
		for (int i = 0; i < bfs_size(tmp); i++){
			a = tmp[i];
			std::cout << "[" << a->data << ", " << a->color << "] ";
			if (a->left)
				i += move_tmp(tmp, i, a->left);
			if (a->right)
				i += move_tmp(tmp, i, a->right);
			del_tmp(tmp, i);
			i--;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	del_one(RBTNode *node, RBTNode *child){
	child->parent = node->parent;
	if (node->parent->left == node)
		node->parent->left = child;
	else
		node->parent->right = child;
}

void	del_left(RBTNode **head, RBTNode *node, RBTNode *child){
	int		col;
	RBTNode *sibling = 0;
	RBTNode *s_left = 0;
	RBTNode *s_right = 0;

	sibling = node->parent->right;
	if (sibling)
		s_left = sibling->left;
	if (sibling)
		s_right = sibling->right;
	//parent->color == RED
	if (node->parent->color == RED){
		if (s_right->color == RED){
			node->parent->color = BLACK;
			sibling->color = RED;
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(head, node->parent);
		}
		else if (s_left->color == BLACK){
			node->parent->color = BLACK;
			sibling->color = RED;
		}
		else if (s_left->color == RED){
			sibling->color = RED;
			s_left->color = BLACK;
			rotateRight(head, sibling);
		}
	}
	//parent->color == BLACK
	else{
		if (sibling->color == RED){
			node->parent->color = RED;
			sibling->color = BLACK;
			rotateLeft(head, node->parent);
			del_left(head, node, child);
		}
		else if (s_right->color == RED){
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(head, node->parent);
		}
		else if (s_left->color == BLACK){
			sibling->color = RED;
			del(head, node->parent->data);
		}
		else{
			sibling->color = RED;
			s_left->color = BLACK;
			rotateRight(head, sibling);
		}
	}
}

void	del_right(RBTNode **head, RBTNode *node, RBTNode *child){
	int		col;
	RBTNode *sibling = 0;
	RBTNode *s_left = 0;
	RBTNode *s_right = 0;

	sibling = node->parent->right;
	if (sibling)
		s_left = sibling->left;
	if (sibling)
		s_right = sibling->right;
	//parent->color == RED
	if (node->parent->color == RED){
		if (s_right->color == RED){
			node->parent->color = BLACK;
			sibling->color = RED;
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateRight(head, node->parent);
		}
		else if (s_left->color == BLACK){
			node->parent->color = BLACK;
			sibling->color = RED;
		}
		else if (s_left->color == RED){
			sibling->color = RED;
			s_left->color = BLACK;
			rotateLeft(head, sibling);
		}
	}
	//parent->color == BLACK
	else{
		if (sibling->color == RED){
			node->parent->color = RED;
			sibling->color = BLACK;
			rotateRight(head, node->parent);
			del_right(head, node, child);
		}
		else if (s_right->color == RED){
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateRight(head, node->parent);
		}
		else if (s_left->color == BLACK){
			sibling->color = RED;
			del(head, node->parent->data);
		}
		else{
			sibling->color = RED;
			s_left->color = BLACK;
			rotateLeft(head, sibling);
		}
	}
}

void	one_node(RBTNode **head, RBTNode *node){
	RBTNode *child;

	if (node->right)
		child = node->right;
	else if (node->left)
		child = node->left;
	if (node->color == RED)
		del_one(node, child);
	else{
		if (child->color == RED){
			child->color = BLACK;
			del_one(node, child);
		}
		else if (node->parent->left == node)
			del_left(head, node, child);
		else
			del_right(head, node, child);
	}
	delete child;
}

void	two_node(RBTNode **head, RBTNode *node){
	RBTNode *tmp;

	tmp = node->right;
	while (tmp->left)
		tmp = tmp->left;
	node->data = tmp->data;
	if (tmp == node->right)
		node->right = tmp->right;
	else
		tmp->parent->left = tmp->right;
	if (tmp->right)
		tmp->right->parent = tmp->parent;
	delete tmp;
}

void	del(RBTNode **head, int data){
	RBTNode	*tmp;

	tmp = *head;
	while (tmp){
		if (tmp->data < data)
			tmp = tmp->right;
		else if (tmp->data > data)
			tmp = tmp->left;
		else
			break ;
	}
	if (tmp == NULL)
		return ;
	else if (tmp->left && tmp->right)
		return two_node(head, tmp);
	else
		return one_node(head, tmp);
}

int		main(){
	int			data;
	RBTNode*	head = 0;

	data = 1;
	while (data){
		cin >> data;
		insert(&head, new_node(data));
		bfs(&head);
		std::cout << std::endl;
	}
	data = 1;
	while (data){
		cin >> data;
		del(&head, data);
		bfs(&head);
	}
	traverse(head);
	return 0;
}
