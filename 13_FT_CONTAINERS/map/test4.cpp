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

	tmp = node->left;
	grand = node->parent;
	if (tmp)
		tmp->parent = grand;
	grand->right = tmp;
	node->parent = grand->parent;
	if (grand->parent && grand->parent->right == grand)
		grand->parent->right = node;
	else if (grand->parent)
		grand->parent->left = node;
	else
		*head = node;
	node->left = grand;
}

void	rotateRight(RBTNode **head, RBTNode *node){
	RBTNode *tmp;
	RBTNode *grand;
	
	tmp = node->right;
	grand = node->parent;
	if (tmp)
		tmp->parent = grand;
	grand->left = tmp;
	node->parent = grand->parent;
	if (grand->parent && grand->parent->right == grand)
		grand->parent->right = node;
	else if (grand->parent)
		grand->parent->left = node;
	else
		*head = node;
	node->right = grand;
}

void	rebuild(RBTNode **head, RBTNode *node){
	RBTNode *tmp;
	RBTNode *uncle;

	if (node->parent->color == BLACK)
		return ;
	if (node->parent->parent)
		tmp = node->parent->parent;
	if (tmp == NULL)
		uncle = NULL;
	else if (tmp->left == node->parent)
		uncle = node->parent->right;
	else
		uncle = node->parent->left;
	if (uncle && uncle->color == RED){
		node->parent->color = BLACK;
		uncle->color = BLACK;
		tmp->color = RED;
		if (*head == tmp)
			(*head)->color = BLACK;
		else if (tmp->color == RED)
			rebuild(head, tmp);
	}
	else{
		node->parent->color = tmp->color;
		tmp->color = RED;
		if (node->parent->right == node)
			rotateLeft(head, node->parent);
		rotateRight(head, tmp);
		//rebuild(head, node);
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
