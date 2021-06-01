//#include "./map_bfs.hpp"
//#include "./map_insert.hpp"
#include "./map_delete.hpp"

class value_compare{
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
map() : head(&tail) { tail.left = &tail; tail.right = &tail; }

explicit map(const Compare& comp, const Allocator& alloc = Allocator()) : head(&tail) { tail.left = &tail; tail.right = &tail; }

map(const map& other) { *this = other; }

map&	operator=(map const &m) {
	if (this == &m)
		return *this;
	clear();
	for (iterator it = m.begin(); it != m.end(); it++)
		insert(it.getValue());
	return *this;
}

template<class InputIt>
map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : head(&tail) {
	tail.left = &tail;
	tail.right = &tail;
	for (InputIt i = first; i != last; i++)
		insert(*i);
}

template<>
map(iterator first, iterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : head(&tail) {
	tail.left = &tail;
	tail.right = &tail;
	for (iterator i = first; i != last; i++)
		insert(i.getValue());
}

~map() { clear(); }

allocator_type	get_allocator() const { allocator_type alloc; return alloc; }

//iterator
iterator			begin() { return iterator(tail.right); }
const_iterator		begin() const { return const_iterator(tail.right); }
iterator			end() { return iterator(&tail); }
const_iterator		end() const { return const_iterator(&tail); }
reverse_iterator		rbegin() { return reverse_iterator(tail.prev); }
const_reverse_iterator	rbegin() const { return const_reverse_iterator(tail.prev); }
reverse_iterator		rend() { return reverse_iterator(&tail); }
const_reverse_iterator	rend() const { return const_reverse_iterator(&tail); }

//access
T&	operator[](const Key& key){
	iterator it;
	
	it = find(key);
	if (it == end())
		return (insert(std::make_pair(key, T())).first->second);
	return (it->second);
}

//capacity
bool		empty() const { if (begin() == end()) return true; else return false;}
size_type	size() const { return sz; } //std::distance(begin(), end())
size_type	max_size() const { return std::numeric_limits<difference_type>::max(); }

//modifiers
void		clear_node(RBTNode<Key, T>**	node){
	RBTNode<Key, T>*	tmp;
	al					alloc;

	tmp = *node;
	if (tmp == &tail)
		return ;
	if (tmp->left != &tail)
		clear_node(&(tmp->left));
	if (tmp->right != &tail)
		clear_node(&(tmp->right));
	if (tmp->parent != &tail && tmp->parent->left != &tail
			&& tmp->parent->left == tmp)
		tmp->parent->left = &tail;
	else if (tmp->parent != &tail)
		tmp->parent->right = &tail;
	else
		head = &tail;
	alloc.deallocate(tmp, 1);
	sz--;
}

void		clear(){ clear_node(&head); }

RBTNode<Key, T>*	make_node(const value_type& value){
	RBTNode<Key, T>*	tmp;
	al					alloc;

	tmp = alloc.allocate(1);
	tmp->parent = &tail;
	tmp->left = &tail;
	tmp->right = &tail;
	tmp->color = RED;
	alloc.construct(&tmp->value, value);
	sz++;
	return tmp;
}

std::pair<iterator, bool>	insert(const value_type& value){
	iterator			it;
	RBTNode<Key, T>*	tmp;

	it = find(value.first);
	if (it != end()){
		std::pair<iterator, bool>	n(it, false);
		return n;
	}
	tmp = make_node(value);
	add_node(&head, tmp);
	std::pair<iterator, bool>	n(tmp, true);
	return n;
}
//tail 확인 필요
RBTNode<Key, T>*	check_hint(iterator hint, RBTNode<Key, T>* node){
	RBTNode<Key, T>*	tmp;
	key_compare			comp;

	if (comp(head->value.second, *hint.second)){
		if (comp(node->value.second, head->value.second))
			return head;
		else{
			tmp = hint.getPointer();
			while (comp(node->value.second, tmp->value.second))
				tmp = tmp->parent;
			return tmp;
		}
	}
	else{
		if (comp(head->value.second, node->value.second))
			return head;
		else{
			tmp = hint.getPointer();
			while (comp(tmp->value.second, node->value.second))
				tmp = tmp->parent;
			return tmp;
		}
	}
}

iterator	insert(iterator hint, const value_type& value){
	RBTNode<Key, T>*	tmp;
	RBTNode<Key, T>*	node;
	iterator			it;

	it = find(value.first);
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
		add_node(make_node(i.getValue()));
	}
}

template<>
void		insert(iterator first, iterator last){
	for (iterator i = first; i != last; i++){
		if (find(i->first) != end())
			continue ;
		add_node(make_node(i.getValue()));
	}
}

iterator	erase(iterator pos){
	iterator	it;

	it = pos;
	it++;
	del(pos.getPointer());
	return (it);
}

void		erase(iterator first, iterator last){
	for (iterator it = first; it != last; it++)
		erase(it);
}

size_type	erase(const key_type& key){
	iterator	it;

	it = find(key);
	if (it == end())
		return 0;
	erase(it);
	return 1;
}

void		swap(map& other){
	size_type			cnt;
	RBTNode<Key, T>*	tmp1;
	RBTNode<Key, T>		tmp2;

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
	size_t				size;
	size_t				cnt;
	RBTNode<Key, T>**	tmp;
	RBTNode<Key, T>*	node;

	size = 4;
	cnt = 0;
	realloc(&tmp, 0, 8);
	tmp[0] = head;
	while (size_bfs(tmp) > 0){
		cnt++;
		for (size_type i = 0; i < bfs_size(tmp); i++){
			if (bfs_size(tmp) >= size - 4){
				realloc(&tmp, size, size * 2);
				size *= 2;
			}
			node = tmp[i];
			if (node->value.first == key){
				delete [] tmp;
				return iterator(node);
			}
			if (node->left != &tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != &tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return (end());
}

const_iterator	find(const Key& key) const {
	size_t				size;
	size_t				cnt;
	RBTNode<Key, T>**	tmp;
	RBTNode<Key, T>*	node;

	size = 4;
	cnt = 0;
	realloc(&tmp, 0, 8);
	tmp[0] = head;
	while (size_bfs(tmp) > 0){
		cnt++;
		for (size_type i = 0; i < bfs_size(tmp); i++){
			if (bfs_size(tmp) >= size - 4){
				realloc(&tmp, size, size * 2);
				size *= 2;
			}
			node = tmp[i];
			if (node->value.first == key){
				delete [] tmp;
				return const_iterator(node);
			}
			if (node->left != &tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != &tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return (end());
}

std::pair<iterator, iterator>	equal_range(const Key& key){
	iterator	it;

	it = find(key);
	if (it != end())
		return std::make_pair(it, ++it);
	return std::make_pair(it, end());
}

std::pair<const_iterator, const_iterator>	equal_range (const Key& key) const {
	const_iterator	it;

	it = find(key);
	if (it != end())
		return std::make_pair(it, ++it);
	return std::make_pair(it, end());
}

iterator	lower_bound(const Key& key){
	size_type			size;
	iterator			it;
	RBTNode<Key, T>**	tmp;
	RBTNode<Key, T>*	node;
	key_compare			cmp;

	size = 8;
	realloc(&tmp, 0, size);
	tmp[0] = head;
	it = end();
	while (size_bfs(tmp) > 0){
		if (bfs_size(tmp) > size - 4){
			realloc(&tmp, size, size * 2);
			size *= 2;
		}
		for (size_type i = 0; i < bfs_size(tmp); i++){
			node = tmp[i];
			if (!(cmp(key, node->value.first))){
				if (it == end() || cmp((*it).first, node->value.first))
					it = iterator(node);
			}
			if (node->left != &tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != &tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return it;
}

const_iterator	lower_bound(const Key& key) const {
	size_type			size;
	const_iterator		it;
	RBTNode<Key, T>**	tmp;
	RBTNode<Key, T>*	node;
	key_compare			cmp;

	size = 8;
	realloc(&tmp, 0, size);
	tmp[0] = head;
	it = end();
	while (size_bfs(tmp) > 0){
		if (bfs_size(tmp) > size - 4){
			realloc(&tmp, size, size * 2);
			size *= 2;
		}
		for (size_type i = 0; i < bfs_size(tmp); i++){
			node = tmp[i];
			if (!(cmp(key, node->value.first))){
				if (it == end() || cmp((*it).first, node->value.first))
					it = const_iterator(node);
			}
			if (node->left != &tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != &tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return it;
}

iterator	upper_bound(const Key& key){
	size_type			size;
	iterator			it;
	RBTNode<Key, T>**	tmp;
	RBTNode<Key, T>*	node;
	key_compare			cmp;

	size = 8;
	realloc(&tmp, 0, size);
	tmp[0] = head;
	it = end();
	while (size_bfs(tmp) > 0){
		if (bfs_size(tmp) > size - 4){
			realloc(&tmp, size, size * 2);
			size *= 2;
		}
		for (size_type i = 0; i < bfs_size(tmp); i++){
			node = tmp[i];
			if (cmp(key, node->value.first)){
				if (it == end() || cmp(node->value.first, (*it).first))
					it = iterator(node);
			}
			if (node->left != &tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != &tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return it;
}

const_iterator	upper_bound(const Key& key) const {
	size_type			size;
	const_iterator		it;
	RBTNode<Key, T>**	tmp;
	RBTNode<Key, T>*	node;
	key_compare			cmp;

	size = 8;
	realloc(&tmp, 0, size);
	tmp[0] = head;
	it = end();
	while (size_bfs(tmp) > 0){
		if (bfs_size(tmp) > size - 4){
			realloc(&tmp, size, size * 2);
			size *= 2;
		}
		for (size_type i = 0; i < bfs_size(tmp); i++){
			node = tmp[i];
			if (cmp(key, node->value.first)){
				if (it == end() || cmp(node->value.first, (*it).first))
					it = const_iterator(node);
			}
			if (node->left != &tail)
				i += move_bfs(tmp, i, node->left);
			if (node->right != &tail)
				i += move_bfs(tmp, i, node->right);
			del_bfs(tmp, i);
			i--;
		}
	}
	delete [] tmp;
	return it;
}

key_compare		key_comp() const {
	key_compare	comp;
	return comp;
}

typename ft::map<Key, T>::value_compare		value_comp() const {
	value_compare	comp(key_compare);
	return comp;
}
