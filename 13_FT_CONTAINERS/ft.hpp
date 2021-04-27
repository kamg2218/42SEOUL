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
	class	list : public Iterator<T>{
	public:
		Allocator							al;
		T*									head;
		size_t								sz;
		typedef	T 							value_type;
		typedef Allocator					allocator_type;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::const_reference	const_reference;
		typedef Iterator<T>					iterator;
		typedef const iterator				const_iterator;
		typedef ReverseIterator<T>			reverse_iterator;
		typedef const reverse_iterator		const_reverse_iterator;
		//constructor
		list() : sz(0) { head = al.allocate(0); }
		list(const list& other) { *this = other; }
		list&	operator=(list const &lst) {
			sz = lst.sz;
			head = al.allocate(sz);
			for (size_type i = 0; i < sz; i++)
				head[i] = lst.head[i];
			return *this;
		}
		explicit list(const Allocator& alloc) : sz(0) { 
			al = alloc;
			head = al.allocate(0);
		}
		explicit list(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : sz(count) {
			al = alloc;
			head = al.allocate(count);
			for (size_type i = 0; i < count; i++)
				head[i] = value;
		}
		template<class InputIt>
		list(InputIt first, InputIt last, const Allocator& alloc = Allocator()){
			sz = last - first;
			al = alloc;
			head = al.allocate(sz);
			for (InputIt i = first; i != last; i++)
				head[i - first] = *i;
		}
		~list() { std::cout << "destructor\n";
			al.deallocate(head, head[0]);}
		void	assign(size_type count, const T& value){
			sz = count;
			al.deallocate(head, head[0]);
			head = al.allocate(count);
			for (size_type i = 0; i < count; i++)
				head[i] = value;
		}
		template<class InputIt>
		void	assign(InputIt first, InputIt last){
			std::cout << "< last all >\n";
			sz = last - first;
			al.deallocate(head, head[0]);
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
			al.deallocate(head, head[0]);
			head = al.allocate(sz);
			for (size_type i = 0; i < sz; i++, first++)
				head[i] = *first;
		}
		template<>
		void	assign(T* first, T* last){
			std::cout << "< pointer >\n";
			sz = last - first;
			al.deallocate(head, head[0]);
			head = al.allocate(sz);
			for (size_type i = 0; i < sz; i++, first++)
				head[i] = *first;
		}
		allocator_type	get_allocator() const{
			return this->al;
		}

		//iterator
		iterator			begin() { return iterator(&head[0]); }
		const_iterator		begin() const { return const_iterator(&head[0]); }
		iterator			end() { return iterator(&head[sz]); }
		const_iterator		end() const { return const_iterator(&head[sz]); }
		reverse_iterator		rbegin() { return reverse_iterator(&head[sz]); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(&head[sz]); }
		reverse_iterator		rend() { return reverse_iterator(&head[0]); }
		const_reverse_iterator	rend() const { return const_reverse_iterator(&head[0]); }
		

		//access
		reference	front() { return *(begin()); } //return head[0];
		const_reference	front() const { return *(begin()); }//head[0]; }
		reference	back() { return *(end()); } //head[sz - 1]; }
		const_reference	back() const { return *(end()); } //head[sz - 1]; }
		//capacity
		bool		empty() const { if (begin() == end()) return true; else return false;}
			//if (this->sz) return true; else return false; }
		size_type	size() const { return this->sz; } //return std::distance(begin(), end());
		size_type	max_size() const { return std::numeric_limits<difference_type>::max(); }
	};
}

#endif
