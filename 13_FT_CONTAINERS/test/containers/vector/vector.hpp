#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../../utility.hpp"
#include "../../pair.hpp"

namespace	ft{
	#include "../../iterator_tag.hpp"
	#include "vector_iterator.hpp"
	#include "vector_const_iterator.hpp"
	#include "vector_reverse_iterator.hpp"
	#include "vector_const_reverse_iterator.hpp"
	
	template <class T, class Allocator = std::allocator<T> >
	class	vector {
	private:
		T*								head;
		T*								tail;
		T* 								cap;
	public:
		typedef	T 							value_type;
		typedef Allocator						allocator_type;
		typedef size_t							size_type;
		typedef ptrdiff_t						difference_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::const_reference	const_reference;
		typedef VectorIterator<T>					iterator;
		typedef VectorConstIterator<T>				const_iterator;
		typedef VectorReverseIterator<T>			reverse_iterator;
		typedef VectorConstReverseIterator<T>		const_reverse_iterator;

		vector();
		vector(const vector& other);
		vector&		operator=(const vector &v);
		explicit vector(const Allocator& alloc);
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template<class InputIt>
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
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
		vector(pointer first, pointer last, const Allocator& alloc) : head(0), tail(0), cap(0) {
			allocator_type	al;

			head = al.allocate(last - first);
			tail = head;
			cap = head + (last - first);
			for (pointer i = first; i != last; i++)
				push_back(*i);
		}
		~vector();
		void	assign(size_type count, const T& value);
		template<class InputIt>
		void	assign(InputIt first, InputIt last);
		template<>
		void	assign(iterator first, iterator last){
			clear();
			if (capacity() < last - first)
				reserve(last - first);
			for (iterator i = first; i != last; i++)
				push_back(*i);
		}
		template<>
		void	assign(pointer first, pointer last){
			clear();
			if (capacity() < last - first)
				reserve(last - first);
			for (T* i = first; i != last; i++)
				push_back(*i);
			tail += last - first;
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
		reference				at(size_type pos);
		const_reference			at(size_type pos) const;
		reference 				operator[](size_type pos);
		const_reference 		operator[](size_type pos) const;
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;
		bool					empty() const;
		size_type				size() const;
		size_type				capacity() const;
		size_type				max_size() const;
		void					reserve(size_type new_cap);
		void					clear();
		void					push_back(const T& value);
		void					pop_back();
		iterator				insert(iterator pos, const T& value);
		void					insert(iterator pos, size_type count, const T& value);
		template<class InputIt>
		void		insert(iterator pos, InputIt first, InputIt last);
		template<>
		void		insert(iterator pos, iterator first, iterator last){
			size_type	cnt;

			cnt = pos - begin();
			while (cap - tail < last - first)
				reserve((cap - head) * 2);
			for (size_type i = size(); i != cnt; i--)
				head[i + last - first] = head[i];
			head[cnt + last - first] = head[cnt];
			for (iterator i = first; i != last; i++)
				head[cnt++] = *i;
			tail += last - first;
		}
		template<>
		void		insert(iterator pos, pointer first, pointer last){
			size_type	cnt;

			cnt = pos - begin();
			while (cap - tail < last - first)
				reserve((cap - head) * 2);
			for (size_type i = size(); i != cnt; i--)
				head[i + last - first] = head[i];
			head[cnt + last - first] = head[cnt];
			for (pointer i = first; i != last; i++)
				head[cnt++] = *i;
			tail += last - first;
		}
		iterator	erase(iterator pos);
		iterator	erase(iterator first, iterator last);
		void		resize(size_type count, T value = T());
		void		swap(vector& other);
	};

	//non_member.hpp
	template<class T, class Alloc>
	bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		VectorConstIterator<T>		tmp;

		if (lhs.size() != rhs.size())
			return false;
		tmp = rhs.begin();
		for (VectorConstIterator<T> i = lhs.begin(); i != lhs.end(); i++){
			if (*i != *tmp)
				return false;
			tmp++;
		}
		return true;
	}

	template<class T, class Alloc>
	bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){ return !(lhs == rhs); }

	template<class T, class Alloc>
	bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, class Alloc>
	bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs)
			return true;
		return false;
	}

	template<class T, class Alloc>
	bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template<class T, class Alloc>
	bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) || lhs == rhs)
			return true;
		return false;
	}

	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs){
		lhs.swap(rhs);
	}
}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector() : head(0), tail(0), cap(0) {}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(const vector& other) : head(0), tail(0), cap(0) { *this = other; }

template <class T, class Allocator>
ft::vector<T, Allocator>&		ft::vector<T, Allocator>::operator=(const vector &v) {
	iterator		it;
	allocator_type	al;
	
	if (this == &v)
		return *this;
	clear();
	al.deallocate(head, capacity());
	head = al.allocate(v.capacity());
	this->tail = this->head;
	for (it = v.begin(); it != v.end(); it++)
		push_back(*it);
	cap = head + v.capacity();
	return *this;
}

template<class T, class Allocator>
ft::vector<T, Allocator>::vector(const Allocator& alloc) : head(0), tail(0), cap(0) {}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(size_type count, const T& value, const Allocator& alloc) : head(0), tail(0), cap(0) {
	allocator_type	al;

	head = al.allocate(count);
	for (size_type i = 0; i < count; i++)
		head[i] = value;
	tail = head + count;
	cap = head + count;
}

template <class T, class Allocator>
template<class InputIt>
ft::vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator& alloc) : head(0), tail(0), cap(0) {
	allocator_type	al;

	head = al.allocate(first);
	tail = head;
	cap = head + first;
	for (InputIt i = 0; i < first; i++)
		push_back(last);
}

template <class T, class Allocator>
ft::vector<T, Allocator>::~vector() {
	allocator_type	al;

	clear();
	al.deallocate(head, capacity());
}

//assign
template <class T, class Allocator>
void	ft::vector<T, Allocator>::assign(size_type count, const T& value){
	clear();
	if (capacity() < count)
		reserve(count);
	for (size_type i = 0; i < count; i++)
		head[i] = value;
	tail += count;
}
	
template <class T, class Allocator>
template<class InputIt>
void	ft::vector<T, Allocator>::assign(InputIt first, InputIt last){
	clear();
	if (capacity() < first)
		reserve(first);
	for (InputIt i = 0; i < first; i++)
		head[i] = last;
	tail += first;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::allocator_type	ft::vector<T, Allocator>::get_allocator() const { allocator_type al; return al; }

//iterator
template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator		ft::vector<T, Allocator>::begin() { return iterator(head); }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::begin() const { return const_iterator(head); }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator		ft::vector<T, Allocator>::end() { return iterator(tail); }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::end() const { return const_iterator(tail); }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator		ft::vector<T, Allocator>::rbegin() { return reverse_iterator(tail - 1); }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rbegin() const { return const_reverse_iterator(tail - 1); }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator		ft::vector<T, Allocator>::rend() { return reverse_iterator(head - 1); }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rend() const { return const_reverse_iterator(head - 1); }

//access
template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::at(size_type pos){
	if (pos < 0 || pos >= size())
		throw std::out_of_range("vector");
	return head[pos];
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::at(size_type pos) const{
	if (pos < 0 || pos >= size())
		throw std::out_of_range("vector");
	return head[pos];
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::operator[](size_type pos) { return head[pos]; }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::operator[](size_type pos) const { return head[pos]; }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::front() { return *head; }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::front() const { return *head; }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::back() { return *(tail - 1); }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::back() const { return *(tail - 1); }

//capacity
template <class T, class Allocator>
bool	ft::vector<T, Allocator>::empty() const { if (head == tail) return true; else return false;}
template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::size() const { return tail - head; }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::capacity() const { return cap - head; }
template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::max_size() const { return numeric_limits<difference_type>(); }

template <class T, class Allocator>
void	ft::vector<T, Allocator>::reserve(size_type new_cap){
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
	al.deallocate(head, capacity());
	head = tmp;
	cap = tmp + new_cap;
}

//modifiers
template <class T, class Allocator>
void	ft::vector<T, Allocator>::clear(){
	while (head != tail)
		pop_back();
}

template <class T, class Allocator>
void	ft::vector<T, Allocator>::push_back(const T& value){
	if (tail == 0)
		reserve(1);
	else if (cap == tail)
		reserve((cap - head) * 2);
	*tail = value;
	tail++;
}

template <class T, class Allocator>
void	ft::vector<T, Allocator>::pop_back(){
	allocator_type	al;

	if (head == tail)
		return ;
	al.destroy(tail);
	tail--;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::insert(iterator pos, const T& value){
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

template <class T, class Allocator>
void	ft::vector<T, Allocator>::insert(iterator pos, size_type count, const T& value){
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

template <class T, class Allocator>
template<class InputIt>
void	ft::vector<T, Allocator>::insert(iterator pos, InputIt first, InputIt last){
	size_type	cnt;

	cnt = pos - begin();
	while (cap - tail < first)
		reserve((cap - head) * 2);
	for (size_type i = size(); i != cnt; i--)
		head[i + first - 1] = head[i - 1];
	head[cnt + first] = head[cnt];
	for (size_type i = 0; i < first; i++)
		head[i + cnt] = last;
	tail += first;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::erase(iterator pos){
	pointer			ptr;
	allocator_type	al;

	ptr = pos.getPointer();
	for (pointer i = ptr; i != tail; i++)
		*i = *(i + 1);
	al.destroy(tail);
	tail--;
	return (iterator(ptr));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::erase(iterator first, iterator last){
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

template <class T, class Allocator>
void	ft::vector<T, Allocator>::resize(size_type count, T value){
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
		insert(end(), count - size(), value);
	}
}

template <class T, class Allocator>
void	ft::vector<T, Allocator>::swap(vector& other){
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

#endif
