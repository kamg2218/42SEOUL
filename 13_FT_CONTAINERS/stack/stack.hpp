//constructor
stack() {}

explicit stack(const Container& cont = Conatiner()) {}

stack(const stack& other) { *this = other; }

stack&		operator=(stack const &st) {
	if (&st == this)
		return *this;
	this->c = st.c;
	return *this;
}

~vector() {}

//access


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
