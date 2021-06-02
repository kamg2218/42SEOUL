#include "../ft.hpp"

template <class T, class Allocator>
ft::node<T>*		ft::list<T, Allocator>::malloc(){
	ft::node<T>		*tmp;
	al				re_al;

	tmp = re_al.allocate(1);
	tmp->prev = 0;
	tmp->next = 0;
	return tmp;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::add_back(const T& value){
	ft::node<T>*		tmp;
	allocator_type		alloc;

	tmp = malloc();
	alloc.construct(&tmp->value, value);
	if (this->head == 0) {
		this->head = tmp;
		this->tail = tmp;
	}
	else {
		tmp->prev = this->tail;
		this->tail->next = tmp;
		this->tail = tmp;
	}
}

//constructor
template <class T, class Allocator>
ft::list<T, Allocator>::list() : sz(0), head(0), tail(0) {
	add_back(0);
	add_back(0);
}

template <class T, class Allocator>
ft::list<T, Allocator>::list(const ft::list<T, Allocator>& other) { *this = other; }

template <class T, class Allocator>
ft::list<T, Allocator>&	ft::list<T, Allocator>::operator=(ft::list<T, Allocator> const &lst) {
	if (this == &lst)
		return *this;
	iterator	l_it = lst.begin();
	clear();
	this->sz = lst.sz;
	add_back(0);
	for (size_type i = 0; i < lst.sz; i++){
		add_back(*l_it);
		l_it++;
	}
	add_back(0);
	return *this;
}

template <class T, class Allocator>
ft::list<T, Allocator>::list(const Allocator& alloc) : sz(0), head(0), tail(0) { }

template <class T, class Allocator>
ft::list<T, Allocator>::list(size_type count, const T& value, const Allocator& alloc) : sz(0), head(0), tail(0) {
	add_back(0);
	for (size_type i = 0; i < count; i++)
		add_back(value);
	add_back(0);
	this->sz = count;
}

template <class T, class Allocator>
template <class InputIt>
ft::list<T, Allocator>::list(InputIt first, InputIt last, const Allocator& alloc) : sz(0), head(0), tail(0) {
	add_back(0);
	for (InputIt i = 0; i < first; i++)
		add_back(last);
	add_back(0);
	this->sz = first;
}
/*
template <class T, class Allocator>
template <>
ft::list<T, Allocator>::list(iterator first, iterator last, const Allocator& alloc) : sz(0), head(0), tail(0) {
	add_back(0);
	for (iterator i = first; i != last; i++){
		this->sz++;
		add_back(*i);
	}
	add_back(0);
}

template <class T, class Allocator>
template <>
ft::list<T, Allocator>::list(T* first, T* last, const Allocator& alloc) : sz(0), head(0), tail(0) {
	add_back(0);
	for (T* i = first; i != last; i++) {
		this->sz++;
		add_back(*i);
	}
	add_back(0);
}
*/
template <class T, class Allocator>
ft::list<T, Allocator>::~list() {
	allocator_type	alloc;
	al				re_al;

	clear();
	alloc.destroy(&this->head->value);
	alloc.destroy(&this->tail->value);
	re_al.deallocate(this->head, 1);
	re_al.deallocate(this->tail, 1);
}

//assign
template <class T, class Allocator>
void	ft::list<T, Allocator>::assign(size_type count, const T& value){
	clear();
	for (size_type i = 0; i < count; i++)
		push_back(value);
}

template <class T, class Allocator>
template <class InputIt>
void	ft::list<T, Allocator>::assign(InputIt first, InputIt last){
	clear();
	for (InputIt i = 0; i < first; i++)
		push_back(last);
}
/*	
template <class T, class Allocator>
template<>
void	ft::list<T, Allocator>::assign(typename ft::list<T, Allocator>::iterator first, typename ft::list<T, Allocator>::iterator last){
	ft::list<T, Allocator>::clear();
	for (typename ft::list<T, Allocator>::iterator i = first; i != last; i++)
		ft::list<T, Allocator>::push_back(*i);
}

template <class T, class Allocator>
template<>
void	ft::list<T, Allocator>::assign(T* first, T* last){
	ft::list<T, Allocator>::clear();
	for (T* i = first; i != last; i++)
		ft::list<T, Allocator>::push_back(*i);
}
*/
template <class T, class Allocator>
typename ft::list<T, Allocator>::allocator_type	ft::list<T, Allocator>::get_allocator() const { allocator_type alloc; return alloc; }

//iterator
template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::begin() { return iterator(this->head->next); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_iterator		ft::list<T, Allocator>::begin() const { return const_iterator(this->head->next); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::end() { return iterator(this->tail); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_iterator		ft::list<T, Allocator>::end() const { return const_iterator(this->tail); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::reverse_iterator	ft::list<T, Allocator>::rbegin() { return reverse_iterator(this->tail->prev); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_reverse_iterator	ft::list<T, Allocator>::rbegin() const { return const_reverse_iterator(this->tail->prev); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::reverse_iterator	ft::list<T, Allocator>::rend() { return reverse_iterator(this->head); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_reverse_iterator	ft::list<T, Allocator>::rend() const { return const_reverse_iterator(this->head); }

//access
template <class T, class Allocator>
typename ft::list<T, Allocator>::reference	ft::list<T, Allocator>::front() { return *(begin()); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_reference	ft::list<T, Allocator>::front() const { return *(begin()); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::reference	ft::list<T, Allocator>::back() { return this->tail->prev->value; }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_reference	ft::list<T, Allocator>::back() const { if (this->sz > 0) return this->tail->prev->value; else return *(end()); }

//capacity
template <class T, class Allocator>
bool	ft::list<T, Allocator>::empty() const { if (begin() == end()) return true; else return false;}
template <class T, class Allocator>
typename ft::list<T, Allocator>::size_type	ft::list<T, Allocator>::size() const { return this->sz; }
template <class T, class Allocator>
typename ft::list<T, Allocator>::size_type	ft::list<T, Allocator>::max_size() const { return std::numeric_limits<difference_type>::max(); }

//modifiers
template <class T, class Allocator>
void		ft::list<T, Allocator>::clear(){
	while (begin() != end())
		pop_front();
	this->sz = 0;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::push_front(const T& value){
	ft::node<T>*	tmp;
	allocator_type	alloc;

	tmp = malloc();
	alloc.construct(&tmp->value, value);
	tmp->next = this->head->next;
	this->head->next->prev = tmp;
	this->head->next = tmp;
	tmp->prev = this->head;
	this->sz++;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::pop_front(){
	ft::node<T>*	tmp;
	allocator_type	alloc;
	al				re_al;

	tmp = this->head->next;
	if (tmp == this->tail)
		return ;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	alloc.destroy(&tmp->value);
	re_al.deallocate(tmp, 1);
	this->sz--;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::push_back(const T& value){
	ft::node<T>*	tmp;
	allocator_type	alloc;

	tmp = malloc();
	alloc.construct(&tmp->value, value);
	tmp->prev = this->tail->prev;
	this->tail->prev->next = tmp;
	tmp->next = this->tail;
	this->tail->prev = tmp;
	this->sz++;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::pop_back(){
	ft::node<T>*	tmp;
	allocator_type	alloc;
	al				re_al;

	tmp = this->tail->prev;
	if (tmp == this->head)
		return ;
	tmp->prev->next = this->tail;
	this->tail->prev = tmp->prev;
	alloc.destroy(&tmp->value);
	re_al.deallocate(tmp, 1);
	this->sz--;
}

template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::insert(ft::list<T, Allocator>::iterator pos, const T& value){
	ft::node<T>*	tmp;
	allocator_type	alloc;

	tmp = malloc();
	alloc.construct(&tmp->value, value);
	tmp->prev = pos.getPointer()->prev;
	pos.getPointer()->prev->next = tmp;
	tmp->next = pos.getPointer();
	pos.getPointer()->prev = tmp;
	this->sz++;
	return tmp;
}

template <class T, class Allocator>
void	ft::list<T, Allocator>::insert(ft::list<T, Allocator>::iterator pos, ft::list<T, Allocator>::size_type count, const T& value){
	ft::node<T>*		pre;
	ft::node<T>*		tmp;
	allocator_type		alloc;

	pre = pos.getPointer();
	for (size_type i = 0; i < count; i++){
		tmp = malloc();
		alloc.construct(&tmp->value, value);
		tmp->prev = pre->prev;
		pre->prev->next = tmp;
		tmp->next = pre;
		pre->prev = tmp;
		pre = tmp->next;
		this->sz++;
	}
}

template <class T, class Allocator>
template <class InputIt>
void	ft::list<T, Allocator>::insert(iterator pos, InputIt first, InputIt last){
	ft::node<T>*		pre;
	ft::node<T>*		tmp;
	allocator_type		alloc;
	
	pre = pos.getPointer();
	for (InputIt i = 0; i < first; i++){
		tmp = malloc();
		alloc.construct(&tmp->value, last);
		tmp->prev = pre->prev;
		pre->prev->next = tmp;
		tmp->next = pre;
		pre->prev = tmp;
		pre = tmp->next;
		this->sz++;
	}
}

/*
template <class T, class Allocator>
template<>
void	ft::list<T, Allocator>::insert(iterator pos, iterator first, iterator last){
	ft::node<T>*		pre;
	ft::node<T>*		tmp;
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
		this->sz++;
	}
}
*/
template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::erase(iterator pos){
	ft::node<T>*		tmp;
	iterator			it;
	allocator_type		alloc;
	al					re_al;

	if (pos == end())
		return end();
	tmp = pos.getPointer();
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	it = iterator(tmp->next);
	alloc.destroy(&tmp->value);
	re_al.deallocate(tmp, 1);
	this->sz--;
	return (it);
}

template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::erase(iterator first, iterator last){
	ft::node<T>*	tmp;
	ft::node<T>*	next;
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
		this->sz--;
	}
	return iterator(next);
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::resize(size_type count, T value){
	iterator	it;

	if (this->sz == count)
		return ;
	else if (count < this->sz){
		it = this->begin();
		for (size_type i = 0; i < count; i++)
			it++;
		while (this->sz > count)
			it = erase(it);
	}
	else{
		it = this->begin();
		for (size_type i = 0; i < sz; i++)
			it++;
		while (this->sz < count)
			push_back(value);
	}
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::swap(ft::list<T, Allocator>& other){
	size_type		cnt;
	ft::node<T>*	h;
	ft::node<T>*	t;

	if (&other == this)
		return ;
	h = other.head;
	t = other.tail;
	cnt = other.sz;
	other.head = this->head;
	other.tail = this->tail;
	other.sz = this->sz;
	this->head = h;
	this->tail = t;
	this->sz = cnt;
}

//operations
template <class T, class Allocator>
void	ft::list<T, Allocator>::move_node(ft::node<T>* src, ft::node<T>* dst){
	src->prev->next = src->next;
	src->next->prev = src->prev;
	src->prev = dst->prev;
	src->next = dst;
	src->prev->next = src;
	dst->prev = src;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::sort(){
	ft::node<T>*	tmp;

	for (ft::node<T>* i = this->head->next; i != this->tail; i = i->next){
		for (ft::node<T>* j = i->next; j != this->tail; j = j->next){
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

template <class T, class Allocator>
template<class Compare>
void	ft::list<T, Allocator>::sort(Compare cmp){
	ft::node<T>*	tmp;

	for (ft::node<T>* i = this->head->next; i != this->tail; i = i->next){
		for (ft::node<T>* j = i->next; j != this->tail; j = j->next){
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

template <class T, class Allocator>
void	ft::list<T, Allocator>::merge(ft::list<T, Allocator>& other){
	ft::node<T>*	i;
	ft::node<T>*	tmp;

	if (this == &other)
		return ;
	else if (get_allocator() != other.get_allocator())
		return ;
	tmp = this->head->next;
	i = other.head->next;
	while (i != other.tail){
		if (tmp->value > i->value || tmp == this->tail){
			move_node(i, tmp);
			other.sz--;
			this->sz++;
			i = other.head->next;
		}
		else
			tmp = tmp->next;
	}
}

template <class T, class Allocator>
template <class Compare>
void	ft::list<T, Allocator>::merge(ft::list<T, Allocator>& other, Compare comp){
	ft::node<T>*	i;
	ft::node<T>*	tmp;

	if (this == &other)
		return ;
	sort();
	other.sort();
	tmp = this->head->next;
	i = other.head->next;
	while (i != other.tail){
		if (comp(tmp->value, i->value) > 0 || tmp == this->tail){
			move_node(i, tmp);
			other.sz--;
			this->sz++;
			i = other.head->next;
		}
		else
			tmp = tmp->next;
	}
}

template <class T, class Allocator>
void	ft::list<T, Allocator>::splice(const_iterator pos, ft::list<T, Allocator>& other){
	iterator	tmp;

	tmp = other.begin();
	while (tmp != other.end()){
		move_node(tmp.getPointer(), pos.getPointer());
		other.sz--;
		this->sz++;
		tmp = other.begin();
	}
}

template <class T, class Allocator>
void	ft::list<T, Allocator>::splice(const_iterator pos, ft::list<T, Allocator>& other, const_iterator it){
	move_node(it.getPointer(), pos.getPointer());
	other.sz--;
	this->sz++;
}

template <class T, class Allocator>
void	ft::list<T, Allocator>::splice(const_iterator pos, ft::list<T, Allocator>& other, const_iterator first, const_iterator last){
	iterator	tmp;
	iterator	next;

	tmp = first;
	while (tmp != last){
		next = tmp++;
		tmp--;
		move_node(tmp.getPointer(), pos.getPointer());
		other.sz--;
		this->sz++;
		tmp = next;
	}
}

template <class T, class Allocator>
void	ft::list<T, Allocator>::remove(const T& value){
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

template <class T, class Allocator>
template <class UnaryPredicate>
void	ft::list<T, Allocator>::remove_if(UnaryPredicate p){
	for (iterator i = begin(); i != end(); i++){
		if (p(*i) == true){
			i = erase(i);
			i--;
		}
	}
}

template <class T, class Allocator>
void	ft::list<T, Allocator>::reverse(){
	iterator	first;
	iterator	last;

	first = begin();
	last = end()--;
	while (first != last){
		move_node(last.getPointer(), first.getPointer());
		last = end()--;
	}
}

template <class T, class Allocator>
void	ft::list<T, Allocator>::unique(){
	iterator	tmp;

	for (iterator i = begin(); i != end(); i++){
		tmp = i++;
		i--;
		while (*i == *tmp)
			tmp = erase(tmp);
	}
}

template <class T, class Allocator>
template <class BinaryPredicate>
void	ft::list<T, Allocator>::unique(BinaryPredicate p){
	iterator	tmp;

	for (iterator i = begin(); i != end(); i++){
		tmp = i++;
		i--;
		while (p(*i, *tmp))
			tmp = erase(tmp);
	}
}
