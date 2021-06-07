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
RBTNode*	two_node(RBTNode** head, RBTNode* node);

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

	std::cout << "rotateRight\n";
	if (leftChild == NULL)
		return ;
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

	if (rightChild == NULL)
		return ;
	std::cout << "rotateLeft\n";
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
				src = src->parent->parent;
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
				src = src->parent->parent;
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
		std::cout << "node->parent is red\n";
		if (s_right && s_right->color == RED){//1-2
			std::cout << "s_right\n";
			node->parent->color = BLACK;
			sibling->color = RED;
			s_right->color = BLACK;
			rotateLeft(head, node->parent);
		}
		else if (s_left && s_left->color == RED){ //1-3
			std::cout << "s_left\n";
			sibling->color = RED;
			s_left->color = BLACK;
			rotateRight(head, sibling);
			rotateLeft(head, s_left);
		}
		else{	//1-1
			std::cout << "else\n";
			node->parent->color = BLACK;
			if (sibling)
				sibling->color = RED;
		}
	}
	//parent->color == BLACK
	else{
		if (sibling && sibling->color == RED){ //2-4
			node->parent->color = RED;
			sibling->color = BLACK;
			rotateLeft(head, node->parent);
			del_left(head, node, child);
		}
		else if (s_right && s_right->color == RED){ //2-2
			s_right->color = BLACK;
			rotateLeft(head, node->parent);
		}
		else if (s_left && s_left->color == BLACK){ //2-1
			sibling->color = RED;
			two_node(head, node->parent);
		}
		else if (sibling){	//2-3
			sibling->color = RED;
			if (s_left)
				s_left->color = BLACK;
			rotateRight(head, sibling);
			if (s_left)
				rotateLeft(head, s_left);
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
		if (s_left && s_left->color == RED){
			node->parent->color = BLACK;
			sibling->color = RED;
			s_left->color = BLACK;
			rotateRight(head, node->parent);
		}
		else if (s_right && s_right->color == RED){
			s_left->color = BLACK;
			sibling->color = RED;
			rotateLeft(head, sibling);
			rotateRight(head, s_right);
		}
		else {
			node->parent->color = BLACK;
			if (sibling)
				sibling->color = RED;
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
		else if (s_left && s_left->color == RED){
			s_left->color = BLACK;
			rotateRight(head, node->parent);
		}
		else if (s_right && s_right->color == BLACK){
			sibling->color = RED;
			two_node(head, node->parent);
		}
		else if (sibling){
			sibling->color = RED;
			if (s_right)
				s_right->color = BLACK;
			if (s_right)
				rotateRight(head, s_right);
		}
	}
}

RBTNode*	one_node(RBTNode **head, RBTNode *node){
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
	//delete node;
	if (*head)
		(*head)->color = BLACK;
	return node;
}

RBTNode*	two_node(RBTNode **head, RBTNode *node){
	RBTNode *tmp;

	cout << "two_node\n";
	tmp = node->right;
	while (tmp->left)
		tmp = tmp->left;
	node->data = tmp->data; //노드 바꾸기
	return (one_node(head, tmp));
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
		tmp = two_node(head, tmp);
	else
		tmp = one_node(head, tmp);
	delete tmp;
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
	data = 1;
	while (data && head){
		cin >> data;
		if (data == 0)
			break ;
		del(&head, data);
		bfs(&head);
	}
	if (head)
		traverse(head);
	return 0;
}
