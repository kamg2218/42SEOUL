#include "../../ft.hpp"
#include "map_bfs.hpp"

template <class Key, class T, class Compare, class Allocator>
class ft::map<Key, T, Compare, Allocator>::value_compare{
	protected:
		key_compare		comp;
		value_compare(key_compare c) { comp = c; }
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
	public:
		bool	operator()( const value_type& lhs, const value_type& rhs) const{
			return comp(lhs.first, rhs.first);
		}
};

//constructor
template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map() : head(0), tail(0), sz(0) {
	tail = make_node(std::make_pair(0, 0));
	head = tail;
	tail->left = tail;
	tail->right = tail;
	tail->last = tail;
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map(const Compare& comp, const Allocator& alloc) : head(0), tail(0), sz(0) {
	tail = make_node(std::make_pair(0, 0));
	head = tail;
	tail->left = tail;
	tail->right = tail;
	tail->last = tail;
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map(const ft::map<Key, T, Compare, Allocator>& other) : head(0), tail(0), sz(0) {
	tail = make_node(std::make_pair(0, 0));
	head = tail;
	tail->left = tail;
	tail->right = tail;
	tail->last = tail;
	*this = other;
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>&	ft::map<Key, T, Compare, Allocator>::operator=(map const &m) {
	size_type	cnt;
	iterator	it;

	if (this == &m)
		return *this;
	clear();
	cnt = m.size();
	it = m.begin();
	for (size_type i = 0; i < cnt; i++){
		insert(*it);
		it++;
	}
	return *this;
}

template <class Key, class T, class Compare, class Allocator>
template<class InputIt>
ft::map<Key, T, Compare, Allocator>::map(InputIt first, InputIt last, const Compare& comp, const Allocator& alloc) : head(0), tail(0), sz(0) {
	tail = make_node(std::make_pair(0, 0));
	head = tail;
	tail->left = tail;
	tail->right = tail;
	tail->last = tail;
	for (InputIt i = first; i != last; i++)
		insert(*i);
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::~map() {
	al		alloc;

	clear();
	alloc.deallocate(tail, 1);
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::allocator_type	ft::map<Key, T, Compare, Allocator>::get_allocator() const { allocator_type alloc; return alloc; }

//iterator
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator		ft::map<Key, T, Compare, Allocator>::begin() { return iterator(tail->right); }
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::begin() const { return const_iterator(tail->right); }
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator		ft::map<Key, T, Compare, Allocator>::end() { return iterator(tail); }
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::end() const { return const_iterator(tail); }//{ return const_iterator(&tail); }
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator		ft::map<Key, T, Compare, Allocator>::rbegin() { return reverse_iterator(tail->prev); }
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator	ft::map<Key, T, Compare, Allocator>::rbegin() const { return const_reverse_iterator(tail->prev); }
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator		ft::map<Key, T, Compare, Allocator>::rend() { return reverse_iterator(tail); }
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator	ft::map<Key, T, Compare, Allocator>::rend() const { return const_reverse_iterator(tail); }

//access
template <class Key, class T, class Compare, class Allocator>
T&	ft::map<Key, T, Compare, Allocator>::operator[](const Key& key){
	iterator it;
	
	it = find(key);
	if (it == end())
		return (insert(std::make_pair(key, T())).first->second);
	return (it->second);
}

//capacity
template <class Key, class T, class Compare, class Allocator>
bool	ft::map<Key, T, Compare, Allocator>::empty() const { if (!sz) return true; else return false;}
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type		ft::map<Key, T, Compare, Allocator>::size() const { return sz; }
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type		ft::map<Key, T, Compare, Allocator>::max_size() const { return std::numeric_limits<difference_type>::max(); }

//modifiers
template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::clear_node(RBTNode<Key, T>**	node){
	ft::RBTNode<Key, T>*	tmp;
	al					alloc;

	tmp = *node;
	if (tmp == tail)
		return ;
	if (tmp->left != tail)
		clear_node(&(tmp->left));
	if (tmp->right != tail)
		clear_node(&(tmp->right));
	if (tmp->parent != tail && tmp->parent->left == tmp)
		tmp->parent->left = tail;
	else if (tmp->parent != tail)
		tmp->parent->right = tail;
	else
		head = tail;
	alloc.deallocate(tmp, 1);
	sz--;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::clear(){
	clear_node(&head);
	tail->left = tail;
	tail->right = tail;
}

template <class Key, class T, class Compare, class Allocator>
ft::RBTNode<Key, T>*	ft::map<Key, T, Compare, Allocator>::make_node(const value_type& value){
	ft::RBTNode<Key, T>*	tmp;
	al						alloc;

	tmp = alloc.allocate(1);
	tmp->parent = tail;
	tmp->left = tail;
	tmp->right = tail;
	tmp->last = tail;
	tmp->color = RED;
	tmp->value = value;
	return tmp;
}

template <class Key, class T, class Compare, class Allocator>
std::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>	ft::map<Key, T, Compare, Allocator>::insert(const value_type& value){
	iterator				it;
	ft::RBTNode<Key, T>*	tmp;

	it = find(value.first);
	if (it != end()){
		std::pair<iterator, bool>	n(it, false);
		return n;
	}
	tmp = make_node(value);
	add_node(head, tmp);
	std::pair<iterator, bool>	n(tmp, true);
	return n;
}

template <class Key, class T, class Compare, class Allocator>
ft::RBTNode<Key, T>*	ft::map<Key, T, Compare, Allocator>::check_hint(iterator hint, ft::RBTNode<Key, T>* node){
	ft::RBTNode<Key, T>*	tmp;
	key_compare				comp;

	if (comp(head->value.first, hint->first)){
		if (comp(node->value.first, head->value.first))
			return head;
		else{
			tmp = hint.getPointer();
			while (comp(node->value.first, tmp->value.first))
				tmp = tmp->parent;	
			return tmp;
		}
	}
	else{
		if (comp(head->value.first, node->value.first))
			return head;
		else{
			tmp = hint.getPointer();
			while (comp(tmp->value.first, node->value.first))
				tmp = tmp->parent;
			return tmp;
		}
	}
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::insert(iterator hint, const value_type& value){
	ft::RBTNode<Key, T>*	tmp;
	ft::RBTNode<Key, T>*	node;
	iterator			it;

	it = find(value.first);
	if (it != end())
		return it;
	node = make_node(value);
	tmp = check_hint(hint, node);
	add_node(tmp, node);
	return iterator(node);
}

template <class Key, class T, class Compare, class Allocator>
template<class InputIt>
void	ft::map<Key, T, Compare, Allocator>::insert(InputIt first, InputIt last){
	for (InputIt i = first; i != last; i++){
		if (find(i->first) != end())
			continue ;
		add_node(head, make_node(*i));
	}
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::erase(iterator pos){
	iterator	it;

	it = pos;
	it++;
	del(pos.getPointer());
	return (it);
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::erase(iterator first, iterator last){
	Key			k;
	iterator	it;

	it = first;
	while (it != last){
		k = it->first;
		erase(it);
		it = upper_bound(k);
	}
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type		ft::map<Key, T, Compare, Allocator>::erase(const key_type& key){
	iterator	it;

	it = find(key);
	if (it == end())
		return 0;
	erase(it);
	return 1;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::swap(map& other){
	size_type				cnt;
	ft::RBTNode<Key, T>*	tmp1;
	ft::RBTNode<Key, T>*	tmp2;

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

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type		ft::map<Key, T, Compare, Allocator>::count(const Key& key){
	if (find(key) != end())
		return 1;
	return 0;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::find(const Key& key){
	size_t					size;
	size_t					cnt;
	ft::RBTNode<Key, T>**	tmp;
	ft::RBTNode<Key, T>*	node;

	if (head == tail)
		return (end());
	size = 8;
	cnt = 0;
	realloc(&tmp, 0, 8);
	tmp[0] = head;
	while (size_bfs(tmp) > 0){
		cnt++;
		for (size_type i = 0; i < size_bfs(tmp); i++){
			if (size_bfs(tmp) >= size - 4){
				realloc(&tmp, size, size * 2);
				size *= 2;
			}
			node = tmp[i];
			if (node->value.first == key){
				delete [] tmp;
				return iterator(node);
			}
			if (node->left != tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return (end());
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::find(const Key& key) const {
	size_t					size;
	size_t					cnt;
	ft::RBTNode<Key, T>**	tmp;
	ft::RBTNode<Key, T>*	node;

	size = 8;
	cnt = 0;
	realloc(&tmp, 0, 8);
	tmp[0] = head;
	while (size_bfs(tmp) > 0){
		cnt++;
		for (size_type i = 0; i < size_bfs(tmp); i++){
			if (size_bfs(tmp) >= size - 4){
				realloc(&tmp, size, size * 2);
				size *= 2;
			}
			node = tmp[i];
			if (node->value.first == key){
				delete [] tmp;
				return const_iterator(node);
			}
			if (node->left != tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return (end());
}

template <class Key, class T, class Compare, class Allocator>
std::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, typename ft::map<Key, T, Compare, Allocator>::iterator>	ft::map<Key, T, Compare, Allocator>::equal_range(const Key& key){
	iterator	it;

	it = find(key);
	if (it != end())
		return std::make_pair(it, ++it);
	return std::make_pair(it, end());
}

template <class Key, class T, class Compare, class Allocator>
std::pair<typename ft::map<Key, T, Compare, Allocator>::const_iterator, typename ft::map<Key, T, Compare, Allocator>::const_iterator>	ft::map<Key, T, Compare, Allocator>::equal_range (const Key& key) const {
	const_iterator	it;

	it = find(key);
	if (it != end())
		return std::make_pair(it, ++it);
	return std::make_pair(it, end());
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator		ft::map<Key, T, Compare, Allocator>::lower_bound(const Key& key){
	size_type				size;
	iterator				it;
	ft::RBTNode<Key, T>**	tmp;
	ft::RBTNode<Key, T>*	node;
	key_compare				cmp;

	size = 8;
	realloc(&tmp, 0, size);
	tmp[0] = head;
	it = end();
	while (size_bfs(tmp) > 0){
		if (size_bfs(tmp) > size - 4){
			realloc(&tmp, size, size * 2);
			size *= 2;
		}
		for (size_type i = 0; i < size_bfs(tmp); i++){
			node = tmp[i];
			if (!(cmp(node->value.first, key))){
				if (it == end() || cmp(node->value.first, it->first))
					it = iterator(node);
			}
			if (node->left != tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;

	return it;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::lower_bound(const Key& key) const {
	size_type				size;
	const_iterator			it;
	ft::RBTNode<Key, T>**	tmp;
	ft::RBTNode<Key, T>*	node;
	key_compare				cmp;

	size = 8;
	realloc(&tmp, 0, size);
	tmp[0] = head;
	it = end();
	while (size_bfs(tmp) > 0){
		if (size_bfs(tmp) > size - 4){
			realloc(&tmp, size, size * 2);
			size *= 2;
		}
		for (size_type i = 0; i < size_bfs(tmp); i++){
			node = tmp[i];
			if (!(cmp(node->value.first, key))){
				if (it == end() || cmp(node->value.first, it->first))
					it = const_iterator(node);
			}
			if (node->left != tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return it;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::upper_bound(const Key& key){
	size_type				size;
	iterator				it;
	ft::RBTNode<Key, T>**	tmp;
	ft::RBTNode<Key, T>*	node;
	key_compare				cmp;

	size = 8;
	realloc(&tmp, 0, size);
	tmp[0] = head;
	it = end();
	while (size_bfs(tmp) > 0){
		if (size_bfs(tmp) > size - 4){
			realloc(&tmp, size, size * 2);
			size *= 2;
		}
		for (size_type i = 0; i < size_bfs(tmp); i++){
			node = tmp[i];
			if (cmp(key, node->value.first)){
				if (it == end() || cmp(node->value.first, it->first))
					it = iterator(node);
			}
			if (node->left != tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return it;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::upper_bound(const Key& key) const {
	size_type				size;
	const_iterator			it;
	ft::RBTNode<Key, T>**	tmp;
	ft::RBTNode<Key, T>*	node;
	key_compare				cmp;

	size = 8;
	realloc(&tmp, 0, size);
	tmp[0] = head;
	it = end();
	while (size_bfs(tmp) > 0){
		if (size_bfs(tmp) > size - 4){
			realloc(&tmp, size, size * 2);
			size *= 2;
		}
		for (size_type i = 0; i < size_bfs(tmp); i++){
			node = tmp[i];
			if (cmp(key, node->value.first)){
				if (it == end() || cmp(node->value.first, it->first))
					it = const_iterator(node);
			}
			if (node->left != tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return it;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::key_compare	ft::map<Key, T, Compare, Allocator>::key_comp() const {
	key_compare	comp;
	return comp;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T>::value_compare		ft::map<Key, T, Compare, Allocator>::value_comp() const {
	value_compare	comp(key_compare);
	return comp;
}

//map_insert
template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::rotateRight(ft::RBTNode<Key, T> *n){
	RBTNode<Key, T>*	leftChild = n->left;

	n->left = leftChild->right;
	if (leftChild->right != tail)
		leftChild->right->parent = n;
	leftChild->parent = n->parent;
	if (n->parent == tail)
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
	if (rightChild->left != tail)
		rightChild->left->parent = n;
	rightChild->parent = n->parent;
	if (n->parent == tail)
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
			if (tmp != tail && tmp->color == RED){
				n->parent->color = BLACK;
				tmp->color = BLACK;
				n->parent->parent->color = RED;
				n = n->parent->parent;
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
			if (tmp != tail && tmp->color == RED){
				n->parent->color = BLACK;
				tmp->color = BLACK;
				n->parent->parent->color = RED;
				n = n->parent->parent;
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
	if (head != tail)
		head->color = BLACK;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::add_node(ft::RBTNode<Key, T>* h, ft::RBTNode<Key, T>*	node){
	ft::RBTNode<Key, T>*	tmp;
	key_compare				cmp;

	tmp = h;
	if (tmp == tail){
		node->color = BLACK;
		this->head = node;
	}
	else{
		while (tmp != tail){
			if (cmp(node->value.first, tmp->value.first)){
				if (tmp->left == tail)
					break ;
				tmp = tmp->left;
			}
			else{
				if (tmp->right == tail)
					break ;
				tmp = tmp->right;
			}
		}
		if (cmp(node->value.first, tmp->value.first))
			tmp->left = node;
		else
			tmp->right = node;
		node->parent = tmp;
		rebuild(node);
	}
	if (tail->right == tail || cmp(node->value.first, tail->right->value.first))
		tail->right = node;
	if (tail->left == tail || cmp(tail->left->value.first, node->value.first))
		tail->left = node;
	sz++;
}

//map_delete
template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::del_one(ft::RBTNode<Key, T> *node, ft::RBTNode<Key, T> *child){
	if (child != tail)
		child->parent = node->parent;
	if (node->parent != tail && node->parent->left == node)
		node->parent->left = child;
	else if (node->parent != tail)
		node->parent->right = child;
	else
		head = child;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::del_left(ft::RBTNode<Key, T> *node){
	int		col;
	RBTNode<Key, T> *sibling = tail;
	RBTNode<Key, T> *s_left = tail;
	RBTNode<Key, T> *s_right = tail;

	if (node->parent != tail)
		sibling = node->parent->right;
	if (sibling != tail)
		s_left = sibling->left;
	if (sibling != tail)
		s_right = sibling->right;
	if (s_right != tail && s_right->color == RED){
		if (node->parent->color == RED){
			sibling->color = RED;
			node->parent->color = BLACK;
		}
		s_right->color = BLACK;
		rotateLeft(node->parent);
	}
	else if (s_left != tail && s_left->color == RED){
		if (node->parent->color == RED){
			sibling->color = RED;
			node->parent->color = BLACK;
		}
		rotateRight(sibling);
	}
	else if (node->parent != tail && node->parent->color == RED){
		if (sibling != tail)
			sibling->color = RED;
		node->parent->color = BLACK;
	}
	else if (sibling != tail && sibling->color == RED){
		node->parent->color = RED;
		sibling->color = BLACK;
		rotateLeft(node->parent);
		del_left(node);
	}
	//2-1
	else if (sibling != tail && (s_left != tail || s_right != tail)){
		sibling->color = RED;
		rotateRight(sibling);
	}
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::del_right(ft::RBTNode<Key, T> *node){
	int		col;
	RBTNode<Key, T> *sibling = tail;
	RBTNode<Key, T> *s_left = tail;
	RBTNode<Key, T> *s_right = tail;

	if (node->parent != tail)
		sibling = node->parent->left;
	if (sibling != tail)
		s_left = sibling->left;
	if (sibling != tail)
		s_right = sibling->right;
	if (s_left != tail && s_left->color == RED){
		if (node->parent->color == RED){
			sibling->color = RED;
			node->parent->color = BLACK;
		}
		s_left->color = BLACK;
		rotateRight(node->parent);
	}
	else if (s_right != tail && s_right->color == RED){
		if (node->parent->color == RED){
			sibling->color = RED;
			node->parent->color = BLACK;
		}
		rotateLeft(sibling);
	}
	else if (node->parent != tail && node->parent->color == RED){
		if (sibling != tail)
			sibling->color = RED;
		node->parent->color = BLACK;
	}
	else if (sibling != tail && sibling->color == RED){
		node->parent->color = RED;
		sibling->color = BLACK;
		rotateRight(node->parent);
		del_right(node);
	}
	else if (sibling != tail && (s_right != tail || s_left != tail)){
		sibling->color = RED;
		rotateLeft(sibling);
	}
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::one_node(ft::RBTNode<Key, T> *node){
	RBTNode<Key, T>	*child;

	child = tail;
	if (node->right != tail)
		child = node->right;
	else if (node->left != tail)
		child = node->left;
	if (node->color == RED)
		del_one(node, child);
	else{
		if (child != tail && child->color == RED)
			child->color = BLACK;
		else if (node->parent != tail && node->parent->left == node)
			del_left(node);
		else if (node->parent != tail)
			del_right(node);
		else
			head = tail;
		del_one(node, child);
	}
	if (head != tail)
		head->color = BLACK;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::del(ft::RBTNode<Key, T> *node){
	Key				k;
	RBTNode<Key, T> *tmp;
	iterator		it;
	al				alloc;
	
	if (node == tail)
		return ;
	k = node->value.first;
	if (tail->left->value.first == k)
		it = iterator(find(k))--;
	if (node->left != tail && node->right != tail){
		tmp = node->right;
		while (tmp->left != tail)
			tmp = tmp->left;
		node->value = tmp->value;
		one_node(tmp);
	}
	else {
		tmp = node;
		one_node(node);
	}
	alloc.deallocate(tmp, 1);
	sz--;
	if (tail->left->value.first == k)
		tail->left = it.getPointer();
	if (tail->right->value.first == k)
		tail->right = upper_bound(k).getPointer();
}
