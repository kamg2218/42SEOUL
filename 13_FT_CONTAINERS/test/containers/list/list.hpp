#ifndef LIST_HPP
# define LIST_HPP

#include "../../utility.hpp"
#include "../../pair.hpp"

namespace	ft{
	
	template<class T>
	struct node {
		T			value;
		node<T>		*prev;
		node<T>		*next;
	};

	#include "../../iterator_tag.hpp"
	#include "list_iterator.hpp"
	#include "list_const_iterator.hpp"
	#include "list_reverse_iterator.hpp"
	#include "list_const_reverse_iterator.hpp"

	template <class T, class Allocator = std::allocator<T> >
	class	list {
	private:
		node<T>*							head;
		size_t								sz;
		typename Allocator::template rebind<node<T> >::other	al;
	protected:
		node<T>*	malloc();
		void		move_node(node<T>* src, node<T>* dst);
	public:
		typedef node<T>								node;
		typedef	T 									value_type;
		typedef Allocator							allocator_type;
		typedef size_t								size_type;
		typedef ptrdiff_t							difference_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::const_reference	const_reference;
		typedef ListIterator<T>						iterator;
		typedef ListConstIterator<T>				const_iterator;
		typedef ListReverseIterator<T>				reverse_iterator;
		typedef ListConstReverseIterator<T>			const_reverse_iterator;
		list();
		list(const list& other);
		list&	operator=(list const &lst);
		explicit list(const Allocator& alloc);
		explicit list(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template<class InputIt>
		list(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		template<>
		list(iterator first, iterator last, const Allocator& alloc) : head(0), sz(0) {
			push_back(0);
			for (iterator i = first; i != last; i++)
				push_back(*i);
		}
		template<>
		list(pointer first, pointer last, const Allocator& alloc) : head(0), sz(0) {
			push_back(0);
			for (pointer i = first; i != last; i++)
				push_back(*i);
		}
		~list();
		void	assign(size_type count, const T& value);
		template<class InputIt>
		void	assign(InputIt first, InputIt last);
		template<>
		void	assign(iterator first, iterator last){
			clear();
			for (iterator i = first; i != last; i++)
				push_back(*i);
		}
		template<>
		void	assign(pointer first, pointer last){
			clear();
			for (pointer i = first; i != last; i++)
				push_back(*i);
		}
		allocator_type			get_allocator() const;
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;
		bool					empty() const;
		size_type				size() const;
		size_type				max_size() const;
		void					clear();
		void					push_front(const T& value);
		void					pop_front();
		void					push_back(const T& value);
		void					pop_back();
		iterator				insert(iterator pos, const T& value);
		void					insert(iterator pos, size_type count, const T& value);
		template<class InputIt>
		void		insert(iterator pos, InputIt first, InputIt last);
		template<>
		void		insert(iterator pos, iterator first, iterator last){
			node*				pre;
			node*				tmp;
			allocator_type		alloc;

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
		template<>
		void		insert(iterator pos, pointer first, pointer last){
			node*				pre;
			node*				tmp;
			allocator_type		alloc;

			pre = pos.getPointer();
			for (pointer i = first; i != last; i++){
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
		iterator				erase(iterator pos);
		iterator				erase(iterator first, iterator last);
		void					resize(size_type count, T value = T());
		void					swap(list& other);
		void					sort();
		template<class Compare>
		void					sort(Compare cmp);
		void					merge(list& other);
		template <class Compare>
		void					merge(list& other, Compare comp);
		void					splice(const_iterator pos, list& other);
		void					splice(const_iterator pos, list& other, const_iterator it);
		void					splice(const_iterator pos, list& other, const_iterator first, const_iterator last);
		void					remove(const T& value);
		template<class UnaryPredicate>
		void					remove_if(UnaryPredicate p);
		void					reverse();
		void					unique();
		template<class BinaryPredicate>
		void					unique(BinaryPredicate p);
	};
	
	//#include "non_member.hpp"
	template<class T, class Alloc>
	bool	operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		ListConstIterator<T>		tmp;
	
		if (lhs.size() != rhs.size())
			return false;
		tmp = rhs.begin();
		for (ListConstIterator<T> i = lhs.begin(); i != lhs.end(); i++){
			if (tmp == rhs.end())
				break ;
			if (*i != *tmp)
				return false;
			tmp++;
		}
		return true;
	}
	
	template<class T, class Alloc>
	bool	operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){ return !(lhs == rhs); }

	template<class T, class Alloc>
	bool	operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, class Alloc>
	bool	operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		if (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs)
			return true;
		return false;
	}

	template<class T, class Alloc>
	bool	operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template<class T, class Alloc>
	bool	operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		if (lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) || lhs == rhs)
			return true;
		return false;
	}
	
	template <class T, class Alloc>
	void	swap(list<T, Alloc>& lhs, list<T, Alloc>& rhs){
		lhs.swap(rhs);
	}
}

template <class T, class Allocator>
ft::node<T>*		ft::list<T, Allocator>::malloc(){
	node*		tmp;

	tmp = al.allocate(1);
	tmp->prev = head;
	tmp->next = head;
	return tmp;
}

//constructor
template <class T, class Allocator>
ft::list<T, Allocator>::list() : sz(0), head(0) { push_back(0); }

template <class T, class Allocator>
ft::list<T, Allocator>::list(const list& other) : sz(0), head(0) { push_back(0); *this = other; }

template <class T, class Allocator>
ft::list<T, Allocator>&	ft::list<T, Allocator>::operator=(list const &lst) {
	if (this == &lst)
		return *this;
	iterator	l_it = lst.begin();
	clear();
	for (size_type i = 0; i < lst.sz; i++){
		push_back(*l_it);
		l_it++;
	}
	return *this;
}

template <class T, class Allocator>
ft::list<T, Allocator>::list(const Allocator& alloc) : sz(0), head(0) { push_back(0); }

template <class T, class Allocator>
ft::list<T, Allocator>::list(size_type count, const T& value, const Allocator& alloc) : sz(0), head(0) {
	push_back(0);
	for (size_type i = 0; i < count; i++)
		push_back(value);
	this->sz = count;
}

template <class T, class Allocator>
template <class InputIt>
ft::list<T, Allocator>::list(InputIt first, InputIt last, const Allocator& alloc) : sz(0), head(0) {
	push_back(0);
	for (InputIt i = 0; i < first; i++)
		push_back(last);
	this->sz = first;
}

template <class T, class Allocator>
ft::list<T, Allocator>::~list() {
	allocator_type	alloc;

	clear();
	alloc.destroy(&this->head->value);
	al.deallocate(this->head, 1);
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

template <class T, class Allocator>
typename ft::list<T, Allocator>::allocator_type	ft::list<T, Allocator>::get_allocator() const { allocator_type alloc; return alloc; }

//iterator
template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::begin() { return iterator(head->next); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_iterator		ft::list<T, Allocator>::begin() const { return const_iterator(head->next); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::end() { return iterator(head); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_iterator		ft::list<T, Allocator>::end() const { return const_iterator(head); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::reverse_iterator	ft::list<T, Allocator>::rbegin() { return reverse_iterator(head->prev); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_reverse_iterator	ft::list<T, Allocator>::rbegin() const { return const_reverse_iterator(head->prev); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::reverse_iterator	ft::list<T, Allocator>::rend() { return reverse_iterator(head); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_reverse_iterator	ft::list<T, Allocator>::rend() const { return const_reverse_iterator(head); }

//access
template <class T, class Allocator>
typename ft::list<T, Allocator>::reference	ft::list<T, Allocator>::front() { return *(begin()); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_reference	ft::list<T, Allocator>::front() const { return *(begin()); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::reference	ft::list<T, Allocator>::back() { return *(end()); }
template <class T, class Allocator>
typename ft::list<T, Allocator>::const_reference	ft::list<T, Allocator>::back() const { return *(end()); }

//capacity
template <class T, class Allocator>
bool	ft::list<T, Allocator>::empty() const { if (begin() == end()) return true; else return false;}
template <class T, class Allocator>
typename ft::list<T, Allocator>::size_type	ft::list<T, Allocator>::size() const { return this->sz; }
template <class T, class Allocator>
typename ft::list<T, Allocator>::size_type	ft::list<T, Allocator>::max_size() const { return numeric_limits<difference_type>(); }

//modifiers
template <class T, class Allocator>
void		ft::list<T, Allocator>::clear(){
	while (begin() != end())
		pop_front();
	this->sz = 0;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::push_front(const T& value){
	node*			tmp;
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
	node*			tmp;
	allocator_type	alloc;

	tmp = this->head->next;
	if (tmp == head)
		return ;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	alloc.destroy(&tmp->value);
	al.deallocate(tmp, 1);
	this->sz--;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::push_back(const T& value){
	node*			tmp;
	allocator_type	alloc;

	tmp = malloc();
	alloc.construct(&tmp->value, value);
	if (head == 0){
		head = tmp;
		tmp->prev = head;
		tmp->next = head;
		this->sz--;
	}
	else if (head->next == head){
		head->prev = tmp;
		head->next = tmp;
	}
	else {
		tmp->prev = head->prev;
		head->prev->next = tmp;
		head->prev = tmp;
	}
	this->sz++;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::pop_back(){
	node*			tmp;
	allocator_type	alloc;

	tmp = this->head->prev;
	if (tmp == this->head)
		return ;
	tmp->prev->next = this->head;
	this->head->prev = tmp->prev;
	alloc.destroy(&tmp->value);
	al.deallocate(tmp, 1);
	this->sz--;
}

template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::insert(iterator pos, const T& value){
	node*			tmp;
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
void	ft::list<T, Allocator>::insert(iterator pos, size_type count, const T& value){
	node*				pre;
	node*				tmp;
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
	node*				pre;
	node*				tmp;
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

template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::erase(iterator pos){
	node*				tmp;
	iterator			it;
	allocator_type		alloc;

	if (pos == end())
		return end();
	tmp = pos.getPointer();
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	it = iterator(tmp->next);
	alloc.destroy(&tmp->value);
	al.deallocate(tmp, 1);
	this->sz--;
	return (it);
}

template <class T, class Allocator>
typename ft::list<T, Allocator>::iterator	ft::list<T, Allocator>::erase(iterator first, iterator last){
	node*			tmp;
	node*			next;
	allocator_type	alloc;

	next = first.getPointer();
	while (next != last.getPointer()){
		tmp = next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		next = tmp->next;
		alloc.destroy(&tmp->value);
		al.deallocate(tmp, 1);
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
void		ft::list<T, Allocator>::swap(list& other){
	size_type	cnt;
	node*		h;

	if (&other == this)
		return ;
	h = other.head;
	cnt = other.sz;
	other.head = this->head;
	other.sz = this->sz;
	this->head = h;
	this->sz = cnt;
}

//operations
template <class T, class Allocator>
void	ft::list<T, Allocator>::move_node(node* src, node* dst){
	src->prev->next = src->next;
	src->next->prev = src->prev;
	src->prev = dst->prev;
	src->next = dst;
	src->prev->next = src;
	dst->prev = src;
}

template <class T, class Allocator>
void		ft::list<T, Allocator>::sort(){
	node*		tmp;

	for (node* i = head->next; i != head; i = i->next){
		for (node* j = i->next; j != head; j = j->next){
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
	node*		tmp;

	for (node* i = head->next; i != head; i = i->next){
		for (node* j = i->next; j != head; j = j->next){
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
void	ft::list<T, Allocator>::merge(list& other){
	node*	i;
	node*	tmp;

	if (this == &other)
		return ;
	sort();
	other.sort();
	tmp = this->head->next;
	i = other.head->next;
	while (i != other.head){
		if (i->value < tmp->value || tmp == head){
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
void	ft::list<T, Allocator>::merge(list& other, Compare comp){
	node*		i;
	node*		tmp;

	if (this == &other)
		return ;
	sort();
	other.sort();
	tmp = this->head->next;
	i = other.head->next;
	while (i != other.tail){
		if (comp(i->value, tmp->value) || tmp == head){
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
void	ft::list<T, Allocator>::splice(const_iterator pos, list& other){
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
void	ft::list<T, Allocator>::splice(const_iterator pos, list& other, const_iterator it){
	move_node(it.getPointer(), pos.getPointer());
	other.sz--;
	this->sz++;
}

template <class T, class Allocator>
void	ft::list<T, Allocator>::splice(const_iterator pos, list& other, const_iterator first, const_iterator last){
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

#endif
