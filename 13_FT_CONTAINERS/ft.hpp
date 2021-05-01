#ifndef FT_HPP
# define FT_HPP

#include <iostream>
#include <memory>
#include <typeinfo>
#include <list>
#include <iterator>
#include <limits>
#include "iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class	list : public Iterator<T >{
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
		typedef Iterator<T>						iterator;
		typedef const iterator					const_iterator;
		typedef ReverseIterator<T>				reverse_iterator;
		typedef const reverse_iterator			const_reverse_iterator;
		
		node*		malloc(){
			node*	tmp;

			tmp = new node;
			tmp->prev = 0;
			tmp->next = 0;
			return tmp;
		}

		//constructor
		list() : sz(0), head(0), tail(0) { head = malloc(); head->value = al.allocate(0); tail = head;}
		list(const list& other) { *this = other; }
		list&	operator=(list const &lst) {
			if (this == &lst)
				return *this;
			node*		tmp;
			iterator	l_it = lst.begin();
			clear();
			sz = lst.sz;
			for (size_type i = 0; i < sz; i++){
				push_back(*l_it);
				//tmp = malloc();
				//tmp->value = al.allocator(1);
				//tmp->value[0] = *l_it;
				//if (head == 0)
				//	head = tmp;
				//if (tail)
				//	tail->next = tmp;
				//tmp->prev = tail;
				//tail = tmp;
				l_it++;
			}
			tmp = malloc();
			tmp->value = al.allocate(0);
			tmp->prev = tail;
			if (tail)
				tail->next = tmp;
			if (head == 0)
				head = tmp;
			tail = tmp;
			return *this;
		}
		explicit list(const Allocator& alloc) : sz(0), head(0), tail(0) { 
			al = alloc;
		}
		explicit list(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : sz(count), head(0), tail(0) {
			al = alloc;
			node*		tmp;
			for (size_type i = 0; i < count; i++){
				/*
				node*	tmp = malloc();
				
				tmp->value = alloc.allocator(1);
				tmp->value[0] = 0;
				if (head == 0)
					head = tmp;
				if (tail)
					tail->next = tmp;
				tmp->prev = tail;
				tail = tmp;
				*/
				push_back(0);
			}
			tmp = malloc();
			tmp->value = alloc.allocate(0);
			tmp->prev = tail;
			if (tail)
				tail->next = tmp;
			if (head == 0)
				head = tmp;
			tail = tmp;
		}
		template<class InputIt>
		list(InputIt first, InputIt last, const Allocator& alloc = Allocator()) : sz(first), head(0), tail(0) {
			node*	tmp;

			al = alloc;
			for (InputIt i = 0; i < first; i++){
			/*
				tmp = malloc();
				tmp->value = alloc.allocator(1);
				tmp->value[0] = last;
				if (head == 0)
					head = tmp;
				if (tail)
					tail->next = tmp;
				tmp->prev = tail;
				tail = tmp;
			*/
				push_back(last);
			}
			tmp = malloc();
			tmp->value = alloc.allocate(0);
			tmp->prev = tail;
			if (tail)
				tail->next = tmp;
			if (head == 0)
				head = tmp;
			tail = tmp;
		}
		template<>
		list(iterator first, iterator last, const Allocator& alloc) : sz(0), head(0), tail(0) {
			node*	tmp;
			
			al = alloc;
			for (iterator i = first; i != last; i++){
				sz++;
				/*
				tmp = malloc();
				tmp->value = alloc.allocator(1);
				tmp->value[0] = *i;
				if (head == 0)
					head = tmp;
				if (tail)
					tail->next = tmp;
				tmp->prev = tail;
				tail = tmp;
				*/
				push_back(*i);
			}
			tmp = malloc();
			tmp->value = alloc.allocate(0);
			tmp->prev = tail;
			if (tail)
				tail->next = tmp;
			if (head == 0)
				head = tmp;
			tail = tmp;
		}
		template<>
		list(T* first, T* last, const Allocator& alloc) : sz(0), head(0), tail(0) {
			node*	tmp;
			
			al = alloc;
			for (T* i = first; i != last; i++){
				sz++;
				/*
			   	tmp = malloc();
				if (tmp->value){
					tmp->value = al.allocator(1);
					tmp->value[0] = *i;
				}
				if (head == 0)
					head = tmp;
				if (tail)
					tail->next = tmp;
				tmp->prev = tail;
				tail = tmp;
				*/
				push_back(*i);
			}
			tmp = malloc();
			tmp->value = alloc.allocate(0);
			tmp->prev = tail;
			if (tail)
				tail->next = tmp;
			if (head == 0)
				head = tmp;
			tail = tmp;
		}
		~list() { std::cout << "destructor\n"; clear(); }
		/*
		void	assign(size_type count, const T& value){
			sz = count;
			al.deallocate(head, sz);
			head = al.allocate(count);
			for (size_type i = 0; i < count; i++)
				head[i] = value;
		}
		template<class InputIt>
		void	assign(InputIt first, InputIt last){
			std::cout << "< last all >\n";
			sz = last - first;
			al.deallocate(head, sz);
			head = al.allocate(sz);
			for (size_type i = 0; i < sz; i++)
				head[i] = first++;
		}
		template<>
		void	assign(typename std::list<T>::iterator first, typename std::list<T>::iterator last){
			std::cout << "< iterator >" << std::endl;
			sz = 0;
			for (typename std::list<T>::iterator i = first; i != last; i++)
				sz++;
			al.deallocate(head, sz);
			head = al.allocate(sz);
			for (size_type i = 0; i < sz; i++, first++)
				head[i] = *first;
		}
		template<>
		void	assign(T* first, T* last){
			std::cout << "< pointer >\n";
			sz = last - first;
			al.deallocate(head, sz);
			head = al.allocate(sz);
			for (size_type i = 0; i < sz; i++, first++)
				head[i] = *first;
		}
*/
		allocator_type	get_allocator() const{
			return this->al;
		}

		//iterator
		iterator			begin() { return iterator(head); }
		const_iterator		begin() const { return const_iterator(head); }
		iterator			end() { return iterator(tail); }
		const_iterator		end() const { return const_iterator(tail); }
		reverse_iterator		rbegin() { return reverse_iterator(tail); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(tail); }
		reverse_iterator		rend() { return reverse_iterator(head); }
		const_reverse_iterator	rend() const { return const_reverse_iterator(head); }
		

		//access
		reference	front() { return head[0]; } //*(begin())
		const_reference	front() const { return head[0]; } //*(begin())
		reference	back() { return head[sz - 1]; } //head[sz - 1]; }
		const_reference	back() const { return head[sz - 1]; } //head[sz - 1]; }
		//capacity
		bool		empty() const { if (begin() == end()) return true; else return false;}
			//if (this->sz) return true; else return false; }
		size_type	size() const { return sz; } //std::distance(begin(), end())
		size_type	max_size() const { return std::numeric_limits<difference_type>::max(); }

		//modifiers
		void		clear() {
			if (sz == 0)
				return ;
			node*	tmp;

			while (head){
				tmp = head;
				if (tmp->value)
					al.deallocate(tmp->value, 1);
				head = tmp->next;
				free(tmp);
			}
			head = 0;
			tail = 0;
			sz = 0;
		}
		void		push_front(const T& value){
			node*	tmp;

			tmp = malloc();
			tmp->value = al.allocate(1);
			tmp->value[0] = value;
			tmp->next = head;
			if (head == 0){
				head = tmp;
				tail = tmp;
			}
			else if (head)
				head->prev = tmp;
			head = tmp;
		}
		void		push_back(const T& value){
			node*	tmp;

			tmp = malloc();
			tmp->value = al.allocate(1);
			tmp->value[0] = value;
			tmp->prev = tail;
			if (tail)
				tail->next = tmp;
			if (head == 0){
				head = tmp;
				tail = tmp;
			}
			tail = tmp;
		}
	};
}

#endif
