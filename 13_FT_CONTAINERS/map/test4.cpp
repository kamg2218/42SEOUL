#include <iostream>

enum Color { RED, BLACK };
typedef struct RBTNode{
	int				data;
	enum Color		color;
	struct RBTNode*	parent;
	struct RBTNode*	left;
	struct RBTNode*	right;
}RBTNode;

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

void	rotateLeft(RBTNode **head, RBTNode *node){
	RBTNode *tmp;
	RBTNode *grand;

	grand = node->parent;
	tmp = node->right;
	if (node->parent->left == node){
		tmp->parent = grand;
		grand->left = tmp;
		node->right = tmp->left;
		if (tmp->left)
			tmp->left->parent = node;
		node->parent = tmp;
		tmp->left = node;
	}
	else{
		node->parent = grand->parent;
		if (grand->parent)
			grand->parent->right = node;
		grand->right = node->left;
		if (node->left)
			node->left->parent = grand;
		node->left = grand;
		grand->parent = node;
		if (*head == grand)
			*head = node;
	}
}

void	rotateRight(RBTNode **head, RBTNode *node){
	RBTNode *tmp;
	RBTNode *grand;

	grand = node->parent;
	tmp = node->left;
	if (node->parent->right == node){
		tmp->parent = grand;
		grand->right = tmp;
		node->left = tmp->right;
		if (tmp->right)
			tmp->right->parent = node;
		node->parent = tmp;
		tmp->right = node;
	}
	else{
		node->parent = grand->parent;
		if (grand->parent)
			grand->parent->left = node;
		grand->left = node->right;
		if (node->right)
			node->right->parent = grand;
		node->right = grand;
		grand->parent = node;
		if (*head == grand)
			*head = node;
	}
}

void	rebuild(RBTNode **head, RBTNode *node){
	RBTNode *tmp;
	RBTNode *uncle;

	tmp = NULL;
	if (node->parent && node->parent->color == BLACK)
		return ;
	if (node->parent && node->parent->parent)
		tmp = node->parent->parent;
	if (tmp == NULL)
		uncle = NULL;
	else if (tmp->left == node->parent)
		uncle = tmp->right;
	else
		uncle = tmp->left;
	if (uncle && uncle->color == RED){
		node->parent->color = BLACK;
		uncle->color = BLACK;
		tmp->color = RED;
		if (*head == tmp)
			(*head)->color = BLACK;
		else if ((*head)->color == RED)
			rebuild(head, tmp);
	}
	else{
		if (node->parent->right == node && node->parent == tmp->left){
			rotateLeft(head, node->parent);
			node = node->left;
		}
		else if (node->parent->left == node && node->parent == tmp->right){
			rotateRight(head, node->parent);
			node = node->right;
		}
		node->parent->color = BLACK;
		tmp->color = RED;
		if (node->parent->right == node)
			rotateLeft(head, node->parent);
		else
			rotateRight(head, node->parent);
	}
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

int		main(){
	int			data;
	RBTNode*	head = 0;

	while (std::cin >> data){
		insert(&head, new_node(data));
		bfs(&head);
		std::cout << std::endl;
	}
	traverse(head);
	return 0;
}
