#ifndef FT_HPP
# define FT_HPP

#include <iostream>
#include <memory>
#include <typeinfo>
#include <iterator>
#include <limits>
#include "iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class	list : public Iterator<T >, public ReverseIterator<T >{
	public:
		Allocator							al;
		node<T>*							head;
		node<T>*							tail;
		size_t								sz;

		typedef node<T>						node;
		typedef	T 							value_type;
		typedef Allocator					allocator_type;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::const_reference	const_reference;
		///*
		typedef Iterator<T>					iterator;
		typedef const Iterator<T>			const_iterator;
		typedef ReverseIterator<T>			reverse_iterator;
		typedef const ReverseIterator<T>	const_reverse_iterator;
		//*/
		/*
		class	iterator : public Iterator<T >{	
		};
		class	const_iterator : public Iterator<T >{
		};
		class	reverse_iterator : public ReverseIterator<T >{
		};
		class	const_reverse_iterator : public ReverseIterator<T >{
		};
		*/
		node*		malloc(){
			node*	tmp;

			tmp = new node;
			tmp->prev = 0;
			tmp->next = 0;
			return tmp;
		}
		void		add_back(const T& value){
			node*	tmp;

			tmp = malloc();
			tmp->value = al.allocate(1);
			tmp->value[0] = value;
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
			for (InputIt i = first; i < last; i++){
				sz++;
				add_back(i);
			}
			add_back(0);
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
			al.deallocate(head->value, 1);
			free(head);
			al.deallocate(tail->value, 1);
			free(tail);
		}
		//assign
		void	assign(size_type count, const T& value){
			clear();
			for (size_type i = 0; i < count; i++)
				push_back(value);
			sz = count;
		}
		template<class InputIt>
		void	assign(InputIt first, InputIt last){
			clear();
			for (InputIt i = first; i < last; i++)
				push_back(i);
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
		reference	back() { return *(tail->prev->value); } //if (sz > 0) return *(tail->prev->value); else return *(end()); }
		const_reference	back() const { if (sz > 0) return *(tail->prev->value); else return *(end()); }
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
				if (tmp->value)
					al.deallocate(tmp->value, 1);
				pre = tmp->next;
				free(tmp);
			}
			head->next = tail;
			tail->prev = head;
			sz = 0;
		}
		void		push_front(const T& value){
			node*	tmp;

			tmp = malloc();
			tmp->value = al.allocate(1);
			tmp->value[0] = value;
			tmp->next = head->next;
			head->next->prev = tmp;
			head->next = tmp;
			tmp->prev = head;
			sz++;
		}
		void		push_back(const T& value){
			node*	tmp;

			tmp = malloc();
			tmp->value = al.allocate(1);
			tmp->value[0] = value;
			tmp->prev = tail->prev;
			tail->prev->next = tmp;
			tmp->next = tail;
			tail->prev = tmp;
			sz++;
		}
	};
};

#endif
