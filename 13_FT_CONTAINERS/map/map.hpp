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
list() : sz(0), head(0), tail(0) {
	add_back(0);
	add_back(0);
}

list(const list& other) { *this = other; }

list&	operator=(list const &lst) {
	if (this == &lst)
		return *this;
	iterator	l_it = lst.begin();
	clear();
	sz = lst.sz;
	add_back(0);
	for (size_type i = 0; i < lst.sz; i++){
		add_back(*l_it);
		l_it++;
	}
	add_back(0);
	return *this;
}

explicit list(const Allocator& alloc) : sz(0), head(0), tail(0) { 
}
	
explicit list(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : sz(0), head(0), tail(0) {
	add_back(0);
	for (size_type i = 0; i < count; i++)
		add_back(value);
	add_back(0);
	sz = count;
}

template<class InputIt>
list(InputIt first, InputIt last, const Allocator& alloc = Allocator()) : sz(0), head(0), tail(0) {
	add_back(0);
	for (InputIt i = 0; i < first; i++)
		add_back(last);
	add_back(0);
	sz = first;
}

template<>
list(iterator first, iterator last, const Allocator& alloc) : sz(0), head(0), tail(0) {
	add_back(0);
	for (iterator i = first; i != last; i++){
		sz++;
		add_back(*i);
	}
	add_back(0);
}

template<>
list(T* first, T* last, const Allocator& alloc) : sz(0), head(0), tail(0) {
	add_back(0);
	for (T* i = first; i != last; i++) {
		sz++;
		add_back(*i);
	}
	add_back(0);
}

~list() {
	allocator_type	alloc;
	al				re_al;

	clear();
	alloc.destroy(&head->value);
	alloc.destroy(&tail->value);
	re_al.deallocate(head, 1);
	re_al.deallocate(tail, 1);
}

//assign
void	assign(size_type count, const T& value){
	clear();
	for (size_type i = 0; i < count; i++)
		push_back(value);
}
	
template<class InputIt>
void	assign(InputIt first, InputIt last){
	clear();
	for (InputIt i = 0; i < first; i++)
		push_back(last);
}
	
template<>
void	assign(iterator first, iterator last){
	clear();
	for (iterator i = first; i != last; i++)
		push_back(*i);
}

template<>
void	assign(T* first, T* last){
	clear();
	for (T* i = first; i != last; i++)
		push_back(*i);
}

allocator_type	get_allocator() const { allocator_type alloc; return alloc; }

//iterator
iterator			begin() { return iterator(head->next); }
const_iterator		begin() const { return const_iterator(head->next); }
iterator			end() { return iterator(tail); }
const_iterator		end() const { return const_iterator(tail); }
reverse_iterator		rbegin() { return reverse_iterator(tail->prev); }
const_reverse_iterator	rbegin() const { return const_reverse_iterator(tail->prev); }
reverse_iterator		rend() { return reverse_iterator(head); }
const_reverse_iterator	rend() const { return const_reverse_iterator(head); }
		
//access
reference	front() { return *(begin()); }
const_reference	front() const { return *(begin()); }
reference	back() { return tail->prev->value; } //if (sz > 0) return *(tail->prev->value); else return *(end()); }
const_reference	back() const { if (sz > 0) return tail->prev->value; else return *(end()); }
		
//capacity
bool		empty() const { if (begin() == end()) return true; else return false;}
size_type	size() const { return sz; } //std::distance(begin(), end())
size_type	max_size() const { return std::numeric_limits<difference_type>::max(); }

//modifiers
void		clear(){
	while (begin() != end())
		pop_front();
	sz = 0;
}

void		push_front(const T& value){
	node*	tmp;
	allocator_type	alloc;

	tmp = malloc();
	alloc.construct(&tmp->value, value);
	tmp->next = head->next;
	head->next->prev = tmp;
	head->next = tmp;
	tmp->prev = head;
	sz++;
}

void		pop_front(){
	node*	tmp;
	allocator_type	alloc;
	al				re_al;

	tmp = head->next;
	if (tmp == tail)
		return ;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	alloc.destroy(&tmp->value);
	re_al.deallocate(tmp, 1);
	sz--;
}

void		push_back(const T& value){
	node*	tmp;
	allocator_type	alloc;

	tmp = malloc();
	alloc.construct(&tmp->value, value);
	tmp->prev = tail->prev;
	tail->prev->next = tmp;
	tmp->next = tail;
	tail->prev = tmp;
	sz++;
}

void		pop_back(){
	node*	tmp;
	allocator_type	alloc;
	al				re_al;

	tmp = tail->prev;
	if (tmp == head)
		return ;
	tmp->prev->next = tail;
	tail->prev = tmp->prev;
	alloc.destroy(&tmp->value);
	re_al.deallocate(tmp, 1);
	sz--;
}

iterator	insert(iterator pos, const T& value){
	node*	tmp;
	allocator_type	alloc;

	tmp = malloc();
	alloc.construct(&tmp->value, value);
	tmp->prev = pos.getPointer()->prev;
	pos.getPointer()->prev->next = tmp;
	tmp->next = pos.getPointer();
	pos.getPointer()->prev = tmp;
	sz++;
	return tmp;
}

void		insert(iterator pos, size_type count, const T& value){
	node*		pre;
	node*		tmp;
	allocator_type	alloc;

	pre = pos.getPointer();
	for (size_type i = 0; i < count; i++){
		tmp = malloc();
		alloc.construct(&tmp->value, value);
		tmp->prev = pre->prev;
		pre->prev->next = tmp;
		tmp->next = pre;
		pre->prev = tmp;
		pre = tmp->next;
		sz++;
	}
}

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
