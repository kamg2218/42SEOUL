class value_compare{
	protected:
		Compare		comp;
		value_compare(Compare c) { comp = c; }
	public:
		bool	operator()( const value_type& lhs, const value_type& rhs) const{
			return comp(lhs.first, rhs.first);
		}
};

//constructor
map() : head(0) {}

explicit map(const Compare& comp, const Allocator& alloc = Allocator()) : head(0) {}

map(const map& other) { *this = other; }

map&	operator=(map const &m) {
	if (this == &m)
		return *this;
	clear();
	for (iterator it = m.begin(); it != m.end(); it++)
		insert(*it);
	return *this;
}

template<class InputIt>
map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : head(0) {
	for (InputIt i = first; i != last; i++)
		insert(*i);
}

~map() { clear(); }

allocator_type	get_allocator() const { allocator_type alloc; return alloc; }

//iterator
iterator			begin() { return iterator(tail.right); }
const_iterator		begin() const { return const_iterator(tail.right); }
iterator			end() { return iterator(tail); }
const_iterator		end() const { return const_iterator(tail); }
reverse_iterator		rbegin() { return reverse_iterator(tail.prev); }
const_reverse_iterator	rbegin() const { return const_reverse_iterator(tail.prev); }
reverse_iterator		rend() { return reverse_iterator(tail); }
const_reverse_iterator	rend() const { return const_reverse_iterator(tail); }

//access
T&	operator[](const Key& key){
	iterator it;
	
	it = find(key);
	if (it == end())
		return (insert(std::make_pair(key, T())).first->second);
	return (it);
}

//capacity
bool		empty() const { if (begin() == end()) return true; else return false;}
size_type	size() const { return sz; } //std::distance(begin(), end())
size_type	max_size() const { return std::numeric_limits<difference_type>::max(); }

//modifiers
void		clear_node(RBTNode**	node){
	RBTNode*		tmp;
	allocator_type	alloc;

	tmp = *node;
	if (tmp->left)
		clear_node(&tmp->left);
	if (tmp->right)
		clear_node(&tmp->right);
	if (tmp->parent && tmp->parent->left && tmp->parent->left == tmp)
		tmp->parent->left = 0;
	else if (tmp->parent)
		tmp->parent->right = 0;
	else
		head = NULL;
	alloc.deallocate(tmp, 1);
	sz--;
}

void		clear(){
	clear_node(&head);
	//sz = 0;
}

RBTNode*	make_node(const value_type& value){
	RBTNode*		tmp;
	allocator_type	alloc;

	tmp = alloc.allocate(1);
	tmp->parent = 0;
	tmp->left = 0;
	tmp->right = 0;
	tmp->color = RED;
	alloc.construct(&tmp->value, value);
	sz++;
	return tmp;
}

void rotateRight(RBTNode** node, RBTNode* parent)
{
	RBTNode* leftChild = parent->left;

	parent->left = leftChild->right;
	if (leftChild->right != NULL)
		leftChild->right->parent = parent;
	leftChild->parent = parent->parent;
	if (parent->parent == NULL)
		(*node) = leftChild;
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

void rotateLeft(RBTNode** node, RBTNode* parent)
{
	RBTNode* rightChild = parent->right;

	parent->right = rightChild->left;
	if (rightChild->left != NULL)
		rightChild->left->parent = parent;
	rightChild->parent = parent->parent;
	if (parent->parent == NULL)
		(*node) = rightChild;
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

void	rebuild(RBTNode** node, RBTNode* src){
	RBTNode*	tmp;

	while (src != *node && src->parent->color == RED){
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
	(*node)->color = BLACK;
}

void		add_node(RBTNode** node, RBTNode* dst){
	RBTNode*	tmp;

	tmp = *node;
	if (tmp == 0){
		dst->color = BLACK;
		*head = dst;
		return ;
	}
	while (tmp){
		if (dst->value.first < tmp->value.first){
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
	if (dst->value.first < tmp->value.first)
		tmp->left = dst;
	else
		tmp->right = dst;
	dst->parent = tmp;
	sz++;
	tail->right = head;
	tail->left = dst;
	rebuild(&head, dst);
}

std::pair<iterator, bool>	insert(const value_type& value){
	iterator		it;
	RBTNode*		tmp;

	it = find(value.first)
	if (it != end())
		return std::pair<it, false>;
	tmp = make_node(value);
	add_node(&head, tmp);
	return std::pair<iterator(tmp), true>;
}

RBTNode*	check_hint(iterator hint, RBTNode* node){
	RBTNode*		tmp;
	key_compare		comp;

	if (comp(head->value.first, *hint.first)){
		if (comp(value.first, head->value.first))
			return head;
		else{
			tmp = hint.getPointer();
			while (comp(value.first, tmp->value.first))
				tmp = tmp->parent;
			return tmp;
		}
	}
	else{
		if (comp(head->value.first, value.first))
			return head;
		else{
			tmp = hint.getPointer();
			while (comp(tmp->value.first, value.first))
				tmp = tmp->parent;
			return tmp;
		}
	}
}

iterator	insert(iterator hint, const value_type& value){
	RBTNode*		tmp;
	RBTNode*		node;
	iterator		it;

	it = find(value.first)
	if (it != end())
		return it;
	node = make_node(value);
	tmp = check_hint(hint, node);
	add_node(&tmp, node);
	return iterator(node);
}

template<class InputIt>
void		insert(InputIt first, InputIt last){
	for (InputIt i = first; i != last; i++){
		if (find(i->first) != end())
			continue ;
		add_node(&head, make_node(*i));
	}
}

template<>
void		insert(iterator first, iterator last){
	for (iterator i = first; i != last; i++){
		if (find(*i.first) != end())
			continue ;
		add_node(&head, make_node(*i));
	}
}

iterator	erase(iterator pos){
	RBTNode*	tmp;
	iterator	it;

	it = pos;
	it++;
	tmp = pos.getPointer();

	return (it);
}

void		erase(iterator first, iterator last){
}

size_type	erase(const key_type& key){
}

void		swap(map& other){
	size_type	cnt;
	RBTNode*	tmp1;
	RBTNode		tmp2;

	if (&other == this)
		return ;
	tmp1 = other.head;
	tmp2 = other.tail;
	cnt = other.sz;
	other.head = this->head;
	other.tail = this->tail;
	other.sz = this->sz;
	this->head = tmp1;
	this->tail = tmp2;
	this->sz = cnt;
}

//lookup
size_type	count(const Key& key){
	if (find(key) != end())
		return 1;
	return 0;
}

iterator	find(const Key& key){
	RBTNode*	tmp;

	tmp = head;
	while (tmp && tmp->value.first != key){
		if (comp(key, tmp->value.first))
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if (tmp)
		return iterator(tmp);
	return (end());
}

const_iterator	find(const Key& key) const {
	RBTNode*	tmp;

	tmp = head;
	while (tmp && tmp->value.first != key){
		if (comp(key, tmp->value.first))
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if (tmp)
		return const_iterator(tmp);
	return (end());
}

std::pair<iterator, iterator>	equal_range(const Key& key){
	RBTNode*	tmp;

	tmp = head;
	while (tmp && tmp->value.first != key){
		if ()
	}
}
