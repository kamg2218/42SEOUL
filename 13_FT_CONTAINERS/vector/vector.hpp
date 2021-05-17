//constructor
vector() : head(0), tail(0), cap(0) {}

vector(const vector& other) { *this = other; }

vector&		operator=(vector const &v) {
	iterator		it = v.begin();
	allocator_type	al = v.get_allocator();
	
	if (this == &v)
		return *this;
	clear();
	head = al.allocate(v.capacity());
	tail = head;
	for (it; it != end(); it++)
		push_back(*it);
	cap = head + v.capacity();
	return *this;
}

explicit vector(const Allocator& alloc) : head(0), tail(0), cap(0) {}

explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : head(0), tail(0), cap(0) {
	allocator_type	al;

	head = al.allocate(count);
	for (size_type i = 0; i < count; i++)
		head[i] = value;
	tail = head + count;
	cap = head + count;
}

template<class InputIt>
vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) : head(0), tail(0), cap(0) {
	allocator_type	al;

	head = al.allocate(first);
	tail = head;
	cap = head + first;
	for (InputIt i = 0; i < first; i++)
		push_back(last);
}

template<>
vector(iterator first, iterator last, const Allocator& alloc) : head(0), tail(0), cap(0) {
	allocator_type	al;

	head = al.allocate(last - first);
	tail = head;
	cap = head + (last - first);
	for (iterator i = first; i != last; i++)
		push_back(*i);
}

template<>
vector(T* first, T* last, const Allocator& alloc) : head(0), tail(0), cap(0) {
	allocator_type	al;

	head = al.allocate(last - first);
	tail = head;
	cap = head + (last - first);
	for (T*	i = first; i != last; i++)
		push_back(*i);
}

~vector() { clear(); }

//assign
void	assign(size_type count, const T& value){
	clear();
	if (capacity() < count)
		reserve(count);
	for (size_type i = 0; i < count; i++)
		head[i] = value;
	tail += count;
}
	
template<class InputIt>
void	assign(InputIt first, InputIt last){
	clear();
	if (capacity() < first)
		reserve(first);
	for (InputIt i = 0; i < first; i++)
		head[i] = last;
	tail += first;
}

template<>
void	assign(iterator first, iterator last){
	clear();
	if (capacity() < last - first)
		reserve(last - first);
	for (iterator i = first; i != last; i++)
		push_back(*i);
}

template<>
void	assign(T* first, T* last){
	clear();
	if (capacity() < last - first)
		reserve(last - first);
	for (T* i = first; i != last; i++)
		push_back(*i);
	tail += last - first;
}

allocator_type	get_allocator() const { allocator_type al; return al; }

//iterator
iterator			begin() { return iterator(head); }
const_iterator		begin() const { return const_iterator(head); }
iterator			end() { return iterator(tail); }
const_iterator		end() const { return const_iterator(tail); }
reverse_iterator		rbegin() { return reverse_iterator(tail - 1); }
const_reverse_iterator	rbegin() const { return const_reverse_iterator(tail - 1); }
reverse_iterator		rend() { return reverse_iterator(head - 1); }
const_reverse_iterator	rend() const { return const_reverse_iterator(head - 1); }

//access
reference	at(size_type pos){
	if (pos < 0 || pos >= size())
		throw std::out_of_range("vector");
	return head[pos];
}

const_reference	at(size_type pos) const{
	if (pos < 0 || pos >= size())
		throw std::out_of_range("vector");
	return head[pos];
}

reference operator[](size_type pos) { return head[pos]; }
const_reference operator[](size_type pos) const { return head[pos]; }
reference	front() { return *head; }
const_reference	front() const { return *head; }
reference	back() { return *(tail - 1); }
const_reference	back() const { return *(tail - 1); }

//capacity
bool		empty() const { if (head == tail) return true; else return false;}
size_type	size() const { return tail - head; }
size_type	capacity() const { return cap - head; }
size_type	max_size() const { return std::numeric_limits<difference_type>::max(); }

void		reserve(size_type new_cap){
	pointer			tmp;
	allocator_type	al;

	if (capacity() >= new_cap)
		return ;
	else if (max_size() < new_cap)
		throw std::length_error("vector");
	tmp = al.allocate(new_cap);
	for (size_type i = 0; i < size(); i++)
		tmp[i] = head[i];
	tail = tmp + size();
	al.deallocate(head, size());
	head = tmp;
	cap = tmp + new_cap;
}

//modifiers
void		clear(){
	while (head != tail)
		pop_back();
}

void		push_back(const T& value){
	if (tail == 0)
		reserve(1);
	else if (cap == tail)
		reserve((cap - head) * 2);
	*tail = value;
	tail++;
}

void		pop_back(){
	allocator_type	al;

	if (head == tail)
		return ;
	al.destroy(tail);
	tail--;
}

iterator	insert(iterator pos, const T& value){
	iterator	i;

	if (cap == tail)
		reserve((cap - head) * 2);
	for (i = end() - 1; i != pos; i--)
		*(i + 1) = *i;
	*(i + 1) = *i;
	*pos = value;
	tail++;
	return (pos);
}

void		insert(iterator pos, size_type count, const T& value){
	size_type	cnt;

	cnt = pos - begin();
	if (cap - tail < count)
		reserve((cap - head) * 2);
	for (size_type i = size(); i != cnt; i--)
		head[i + count - 1] = head[i - 1];
	head[cnt + count] = head[cnt];
	for (size_type i = 0; i < count; i++)
		head[i + cnt] = value;
	tail += count;
}

template<class InputIt>
void		insert(iterator pos, InputIt first, InputIt last){
	size_type	cnt;

	cnt = pos - begin();
	if (cap - tail < first)
		reserve((cap - head) * 2);
	for (size_type i = size(); i != cnt; i--)
		head[i + first - 1] = head[i - 1];
	head[cnt + first] = head[cnt];
	for (size_type i = 0; i < first; i++)
		head[i + cnt] = last;
	tail += first;
}

template<>
void		insert(iterator pos, iterator first, iterator last){
	size_type	cnt;

	cnt = pos - begin();
	if (cap - tail < last - first)
		reserve((cap - head) * 2);
	for (size_type i = size(); i != cnt; i--)
		head[i + last - first] = head[i];
	head[cnt + last - first] = head[cnt];
	for (iterator i = first; i != last; i++)
		head[cnt++] = *i;
	tail += last - first;
}

iterator	erase(iterator pos){
	pointer			ptr;
	allocator_type	al;

	ptr = pos.getPointer();
	for (pointer i = ptr; i != tail; i++)
		*i = *(i + 1);
	al.destroy(tail); //check!
	tail--;
	return (iterator(ptr));
}

iterator	erase(iterator first, iterator last){
	pointer			ptr;
	pointer			ptr_end;
	allocator_type	al;

	ptr = last.getPointer();
	ptr_end = first.getPointer();
	for (pointer i = ptr; i <= tail; i++){
		*ptr_end = *i;
		ptr_end++;
	}
	ptr_end--;
	for (pointer i = tail; i != ptr_end; i--){
		al.destroy(i);
		tail--;
	}
	return (iterator(ptr_end));
}

void		resize(size_type count, T value = T()){
	iterator	it;

	if (size() == count)
		return ;
	else if (count < size()){
		it = this->begin();
		for (size_type i = 0; i < count; i++)
			it++;
		erase(it, end());
	}
	else{
		it = this->begin();
		for (size_type i = 0; i < size(); i++)
			it++;
		//while (size() < count)
		//	push_back(value);
		insert(end(), count - size(), value);
	}
}

void		swap(vector& other){
	T*			_head;
	T*			_tail;
	T*			_cap;

	if (&other == this)
		return ;
	_head = other.head;
	_tail = other.tail;
	_cap = other.cap;
	other.head = this->head;
	other.tail = this->tail;
	other.cap = this->cap;
	this->head = _head;
	this->tail = _tail;
	this->cap = _cap;
}
