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

void	rotateLeft(RBTNode **head, RBTNode *node){
	RBTNode *tmp;
	RBTNode *grand;

	cout << "rotateLeft\n";
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

	cout << "rotateRight\n";
	if (node->parent == NULL)
		return ;
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

void	realloc(RBTNode*** node, size_t from, size_t to){
	RBTNode**	tmp;

	tmp = new RBTNode*[to];
	for (size_t i = 0; i < to; i++){
		if (i < from)
			tmp[i] = *node[i];
		else
			tmp[i] = 0;
	}
	delete [] *node;
	*node = tmp;
}

void	bfs(RBTNode **head){
	size_t		size = 8;
	size_t		cnt = 0;
	RBTNode**	tmp = 0;
	RBTNode*	a;

	realloc(&tmp, 0, 8);
	tmp[0] = *head;
	while (bfs_size(tmp) > 0){
		cnt++;
		for (int i = 0; i < bfs_size(tmp); i++){
			if (bfs_size(tmp) >= size - 4){
				realloc(&tmp, size, size * 2);
				size *= 2;
			}
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

void	del_one(RBTNode **head, RBTNode *node, RBTNode *child){
	cout << "del_one\n";
	if (child)
		child->parent = node->parent;
	if (node->parent && node->parent->left == node)
		node->parent->left = child;
	else if (node->parent)
		node->parent->right = child;
	else
		*head = child;
	cout << "del_one\n";
}

void	del_left(RBTNode **head, RBTNode *node, RBTNode *child){
	int		col;
	RBTNode *sibling = 0;
	RBTNode *s_left = 0;
	RBTNode *s_right = 0;

	cout << "del_left\n";
	if (node->parent)
		sibling = node->parent->right;
	if (sibling)
		s_left = sibling->left;
	if (sibling)
		s_right = sibling->right;
	//parent->color == RED
	if (node->parent->color == RED){
		if (s_right && s_right->color == RED){
			node->parent->color = BLACK;
			sibling->color = RED;
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(head, node->parent);
		}
		else if (s_left && s_left->color == RED){
			sibling->color = RED;
			s_left->color = BLACK;
			rotateRight(head, node->parent);
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
			rotateLeft(head, node->parent);
			del_left(head, node, child);
		}
		else if (s_right && s_right->color == RED){
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(head, node->parent);
		}
		else if (s_left && s_left->color == BLACK){
			sibling->color = RED;
			del(head, node->parent->data);
		}
		else{
			cout << "else\n";
			if (sibling)
				sibling->color = RED;
			if (s_left)
				s_left->color = BLACK;
			rotateRight(head, node->parent);
		}
	}
}

void	del_right(RBTNode **head, RBTNode *node, RBTNode *child){
	int		col;
	RBTNode *sibling = 0;
	RBTNode *s_left = 0;
	RBTNode *s_right = 0;

	cout << "del_right\n";
	if (node->parent)
		sibling = node->parent->left;
	if (sibling)
		s_left = sibling->left;
	if (sibling)
		s_right = sibling->right;
	//parent->color == RED
	if (node->parent && node->parent->color == RED){
		if (s_right && s_right->color == RED){
			node->parent->color = BLACK;
			sibling->color = RED;
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(head, node->parent);
		}
		else if (s_left && s_left->color == BLACK){
			node->parent->color = BLACK;
			sibling->color = RED;
		}
		else if (s_left && s_left->color == RED){
			sibling->color = RED;
			s_left->color = BLACK;
			node->parent->color = BLACK;
			rotateRight(head, node->parent);
		}
	}
	//parent->color == BLACK	
	else{
		if (sibling && sibling->color == RED){
			node->parent->color = RED;
			sibling->color = BLACK;
			rotateRight(head, node->parent);
			del_right(head, node, child);
		}
		else if (s_right && s_right->color == RED){
			s_right->color = BLACK;
			if (s_left->color == RED)
				s_left->color = BLACK;
			rotateLeft(head, node->parent);
		}
		else if (s_left && s_left->color == BLACK){
			sibling->color = RED;
			del(head, node->parent->data);
		}
		else{
			sibling->color = RED;
			if (s_left)
				s_left->color = BLACK;
			rotateRight(head, node->parent);
		}
	}
}

void	one_node(RBTNode **head, RBTNode *node){
	RBTNode *child;

	cout << "one_node " << node->data << "\n";
	child = NULL;
	if (node->right)
		child = node->right;
	else if (node->left)
		child = node->left;
	if (node->color == RED)
		del_one(head, node, child);
	else{
		cout << "node is black\n";
		if (child && child->color == RED)
			child->color = BLACK;
		else if (node->parent && node->parent->left == node)
			del_left(head, node, child);
		else if (node->parent)
			del_right(head, node, child);
		else
			*head = NULL;
		del_one(head, node, child);
	}
	delete node;
	cout << "one_node\n";
}

void	two_node(RBTNode **head, RBTNode *node){
	RBTNode *tmp;

	cout << "two_node\n";
	tmp = node->right;
	while (tmp->left)
		tmp = tmp->left;
	node->data = tmp->data; //노드 바꾸기
	one_node(head, tmp);
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

int				count_deep(RBTNode* node){
	int					cnt1;
	int					cnt2;
	RBTNode*			tmp;

	cnt1 = cnt2 = 1;
	if (node->left)
		cnt1 += count_deep(node->left);
	if (node->right)
		cnt2 += count_deep(node->right);
	return cnt1 > cnt2 ? cnt1 : cnt2;
}

int		main(){
	int			data;
	RBTNode*	head = 0;

	data = 1;
	while (data){
		cin >> data;
		if (data == 0)
			break ;
		insert(&head, new_node(data));
		bfs(&head);
		std::cout << std::endl;
	}
	std::cout << "deep = " << count_deep(head) << std::endl;
	std::cout << "deep = " << count_deep(head->left) << std::endl;
	/*
	data = 1;
	while (data && head){
		cin >> data;
		if (data == 0)
			break ;
		del(&head, data);
		if (head)
			bfs(&head);
	}*/
	if (head)
		traverse(head);
	return 0;
}
