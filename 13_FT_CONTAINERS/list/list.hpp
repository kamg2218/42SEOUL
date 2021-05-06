node*		malloc(){
	node*	tmp;

	tmp = al.allocate(1);
	tmp->prev = 0;
	tmp->next = 0;
	return tmp;
}

void		add_back(const T& value){
	node*	tmp;

	tmp = malloc();
	tmp->value = value;
	if (head == 0) {
		head = tmp;
		tail = tmp;
	}
	else {
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
}

//constructor
list() : sz(0), head(0), tail(0) {
	add_back(0);
	add_back(0);
}

list(const list& other) { *this = other; }

list&	operator=(list const &lst) {
	if (this == &lst)
		return *this;
	node*		tmp;
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
	al = alloc;
}
	
explicit list(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : sz(0), head(0), tail(0) {
	al = alloc;
	add_back(0);
	for (size_type i = 0; i < count; i++)
		add_back(value);
	add_back(0);
	sz = count;
}

template<class InputIt>
list(InputIt first, InputIt last, const Allocator& alloc = Allocator()) : sz(0), head(0), tail(0) {
	al = alloc;
	add_back(0);
	for (InputIt i = 0; i < first; i++)
		add_back(last);
	add_back(0);
	sz = first;
}

template<>
list(iterator first, iterator last, const Allocator& alloc) : sz(0), head(0), tail(0) {
	al = alloc;
	add_back(0);
	for (iterator i = first; i != last; i++){
		sz++;
		add_back(*i);
	}
	add_back(0);
}

template<>
list(T* first, T* last, const Allocator& alloc) : sz(0), head(0), tail(0) {
	al = alloc;
	add_back(0);
	for (T* i = first; i != last; i++) {
		sz++;
		add_back(*i);
	}
	add_back(0);
}

~list() {
	clear();
	//al.deallocate(head, 1);
	//al.deallocate(tail, 1);
	al.destroy(head);
	al.destroy(tail);
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

allocator_type	get_allocator() const { return this->al; }

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
	node*	tmp;
	node*	pre;

	if (sz == 0)
		return ;
	pre = head->next;
	if (pre == tail)
		return ;
	while (pre != tail){
		tmp = pre;
		pre = tmp->next;
		//al.deallocate(tmp, 1);
		al.destroy(tmp);
	}
	head->next = tail;
	tail->prev = head;
	sz = 0;
}

void		push_front(const T& value){
	node*	tmp;

	tmp = malloc();
	tmp->value = value;
	tmp->next = head->next;
	head->next->prev = tmp;
	head->next = tmp;
	tmp->prev = head;
	sz++;
}

void		pop_front(){
	node*	tmp;

	tmp = head->next;
	if (tmp == tail)
		return ;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	al.deallocate(tmp, 1);
	sz--;
}

void		push_back(const T& value){
	node*	tmp;

	tmp = malloc();
	tmp->value = value;
	tmp->prev = tail->prev;
	tail->prev->next = tmp;
	tmp->next = tail;
	tail->prev = tmp;
	sz++;
}

void		pop_back(){
	node*	tmp;

	tmp = tail->prev;
	if (tmp == head)
		return ;
	tmp->prev->next = tail;
	tail->prev = tmp->prev;
	//al.destroy(tmp);
	al.deallocate(tmp, 1);
	sz--;
}

iterator	insert(iterator pos, const T& value){
	node*	tmp;

	tmp = malloc();
	tmp->value = value;
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

	pre = pos.getPointer();
	for (size_type i = 0; i < count; i++){
		tmp = malloc();
		tmp->value = value;
		tmp->prev = pre->prev;
		pre->prev->next = tmp;
		tmp->next = pre;
		pre->prev = tmp;
		pre = tmp;
		sz++;
	}
}

template<class InputIt>
void		insert(iterator pos, InputIt first, InputIt last){
	node*		pre;
	node*		tmp;

	pre = pos.getPointer();
	for (InputIt i = first; i < last; i++){
		tmp = malloc();
		tmp->value = i;
		tmp->prev = pre->prev;
		pre->prev->next = tmp;
		tmp->next = pre;
		pre->prev = tmp;
		pre = tmp;
		sz++;
	}
}

iterator	erase(iterator pos){
	node*		tmp;
	iterator	it;

	if (pos == end())
		return end();
	tmp = pos.getPointer();
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	it = iterator(tmp->next);
	al.deallocate(tmp, 1);
	sz--;
	return (it);
}

iterator	erase(iterator first, iterator last){
	node*	tmp;
	node*	next;

	next = last.getPointer();
	for (iterator i = first; i != last; i++){
		if (i == end())
			return (end());
		tmp = i.getPointer();
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		next = tmp->next;
		al.deallocate(tmp, 1);
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
