#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include <memory>
#include <typeinfo>
#include <iterator>
#include <limits>
#include "./list/iterator.hpp"
#include "./list/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class	list {
	public:
		Allocator							al;
		T*									tmp;
		node<T>*							head;
		size_t								sz;

		typename Allocator::template rebind<node<T> >::other		re_al;
		//typedef typename Allocator::template rebind<node<T> >::other		re_al;
		typedef node<T>						node;
		typedef	T 							value_type;
		typedef Allocator					allocator_type;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::const_reference	const_reference;
		//typedef Iterator<T>					iterator;
		//typedef const iterator				const_iterator;
		//typedef ReverseIterator<T>			reverse_iterator;
		//typedef const ReverseIterator<T>	const_reverse_iterator;
		//#include "./list/list.hpp"
	
		list() : tmp(0) { tmp = al.allocate(1); std::cout << "tmp = " << tmp << std::endl; head = re_al.allocate(1); std::cout << "head = " << &(*head) << std::endl; std::cout << "size = " << sizeof(*head) << std::endl; }
		~list() { al.deallocate(tmp, 1); }
	};
};

#endif
