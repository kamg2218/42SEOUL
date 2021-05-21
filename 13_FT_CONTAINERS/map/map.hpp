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

std::pair<iterator, bool>	insert(const value_type& value){
	RBTNode*		tmp;
	allocator_type	alloc;

	if (find(value.first) != end())
		return std::pair<iterator(value), false>;
	tmp = alloc.allocate(1);
	tmp->parent = 0;
	tmp->left = 0;
	tmp->right = 0;
	alloc.construct(&tmp->value, value);
	sz++;
	return std::pair<iterator(tmp), true>;
}

iterator	insert(iterator hint, const value_type& value){
	RBTNode*		tmp;
	allocator_type	alloc;

	if (find(value.first))
}
/*
template<class InputIt>
void		insert(iterator pos, InputIt first, InputIt last){
	node*		pre;
	node*		tmp;
	allocator_type	alloc;

	pre = pos.getPointer();
	for (InputIt i = 0; i < first; i++){
		tmp = malloc();
		alloc.construct(&tmp->value, last);
		tmp->prev = pre->prev;
		pre->prev->next = tmp;
		tmp->next = pre;
		pre->prev = tmp;
		pre = tmp->next;
		sz++;
	}
}

template<>
void		insert(iterator pos, iterator first, iterator last){
	node*		pre;
	node*		tmp;
	allocator_type	alloc;

	pre = pos.getPointer();
	for (iterator i = first; i != last; i++){
		tmp = malloc();
		alloc.construct(&tmp->value, *i);
		tmp->prev = pre->prev;
		pre->prev->next = tmp;
		tmp->next = pre;
		pre->prev = tmp;
		pre = tmp->next;
		sz++;
	}
}

iterator	erase(iterator pos){
	node*		tmp;
	iterator	it;
	allocator_type	alloc;
	al				re_al;

	if (pos == end())
		return end();
	tmp = pos.getPointer();
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	it = iterator(tmp->next);
	alloc.destroy(&tmp->value);
	re_al.deallocate(tmp, 1);
	sz--;
	return (it);
}

iterator	erase(iterator first, iterator last){
	node*	tmp;
	node*	next;
	allocator_type	alloc;
	al				re_al;

	next = first.getPointer();
	while (next != last.getPointer()){
		tmp = next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		next = tmp->next;
		alloc.destroy(&tmp->value);
		re_al.deallocate(tmp, 1);
		sz--;
	}
	return (iterator(next));
}

void		resize(size_type count, T value = T()){
	iterator	it;

	if (this->sz == count)
		return ;
	else if (count < sz){
		it = this->begin();
		for (size_type i = 0; i < count; i++)
			it++;
		while (sz > count)
			it = erase(it);
	}
	else{
		it = this->begin();
		for (size_type i = 0; i < sz; i++)
			it++;
		while (sz < count)
			push_back(value);
	}
}

void		swap(list& other){
	size_type	cnt;
	node*	head;
	node*	tail;

	if (&other == this)
		return ;
	head = other.head;
	tail = other.tail;
	cnt = other.sz;
	other.head = this->head;
	other.tail = this->tail;
	other.sz = this->sz;
	this->head = head;
	this->tail = tail;
	this->sz = cnt;
}

//operations
void		move_node(node* src, node* dst){
	src->prev->next = src->next;
	src->next->prev = src->prev;
	
	src->prev = dst->prev;
	src->next = dst;

	src->prev->next = src;
	dst->prev = src;
}

void		sort(){
	node*	tmp;

	for (node* i = head->next; i != tail; i = i->next){
		for (node* j = i->next; j != tail; j = j->next){
			if (i->value > j->value){
				tmp = j->next;
				move_node(j, i);
				move_node(i, tmp);
				tmp = i;
				i = j;
				j = i;
			}
		}
	}
}

template<class Compare>
void		sort(Compare cmp){
	node*	tmp;

	for (node* i = head->next; i != tail; i = i->next){
		for (node* j = i->next; j != tail; j = j->next){
			if (cmp(i->value, j->value) > 0){
				tmp = j->next;
				move_node(j, i);
				move_node(i, tmp);
				tmp = i;
				i = j;
				j = i;
			}
		}
	}
}

void		merge(list& other){
	node*	i;
	node*	tmp;

	if (this == &other)
		return ;
	else if (get_allocator() != other.get_allocator())
		return ;
	tmp = head->next;
	i = other.head->next;
	while (i != other.tail){
		if (tmp->value > i->value || tmp == tail){
			move_node(i, tmp);
			other.sz--;
			sz++;
			i = other.head->next;
		}
		else
			tmp = tmp->next;
	}
}

template <class Compare>
void		merge(list& other, Compare comp){
	node*	i;
	node*	tmp;

	if (this == &other)
		return ;
	sort();
	other.sort();
	tmp = head->next;
	i = other.head->next;
	while (i != other.tail){
		if (comp(tmp->value, i->value) > 0 || tmp == tail){
			move_node(i, tmp);
			other.sz--;
			sz++;
			i = other.head->next;
		}
		else
			tmp = tmp->next;
	}
}

void		splice(const_iterator pos, list& other){
	iterator	tmp;

	tmp = other.begin();
	while (tmp != other.end()){
		move_node(tmp.getPointer(), pos.getPointer());
		other.sz--;
		sz++;
		tmp = other.begin();
	}
}

void		splice(const_iterator pos, list& other, const_iterator it){
	move_node(it.getPointer(), pos.getPointer());
	other.sz--;
	sz++;
}

void		splice(const_iterator pos, list& other, const_iterator first, const_iterator last){
	iterator	tmp;
	iterator	next;

	tmp = first;
	while (tmp != last){
		next = tmp++;
		tmp--;
		move_node(tmp.getPointer(), pos.getPointer());
		other.sz--;
		sz++;
		tmp = next;
	}
}

void		remove(const T& value){
	iterator	i;

	i = begin();
	while (i != end()){
		if (*i == value){
			i = erase(i);
		}
		else
			i++;
	}
}

template<class UnaryPredicate>
void		remove_if(UnaryPredicate p){
	for (iterator i = begin(); i != end(); i++){
		if (p(*i) == true){
			i = erase(i);
			i--;
		}
	}
}

void		reverse(){
	iterator	first;
	iterator	last;

	first = begin();
	last = end()--;
	while (first != last){
		move_node(last.getPointer(), first.getPointer());
		last = end()--;
	}
}

void		unique(){
	iterator	tmp;

	for (iterator i = begin(); i != end(); i++){
		tmp = i++;
		i--;
		while (*i == *tmp)
			tmp = erase(tmp);
	}
}

template<class BinaryPredicate>
void		unique(BinaryPredicate p){
	iterator	tmp;

	for (iterator i = begin(); i != end(); i++){
		tmp = i++;
		i--;
		while (p(*i, *tmp))
			tmp = erase(tmp);
	}
}
*/
