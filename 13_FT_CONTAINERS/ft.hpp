#ifndef FT_HPP
# define FT_HPP

#include <iostream>
#include <algorithm>
#include <memory>
#include <typeinfo>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <deque>
#include "./list/list_iterator.hpp"
#include "./list/list_reverse_iterator.hpp"
#include "./vector/vector_iterator.hpp"
#include "./vector/vector_reverse_iterator.hpp"

namespace ft
{
	#include "iterator_tag.hpp"

	template <class T, class Allocator = std::allocator<T> >
	class	list {
	private:
		node<T>*							head;
		node<T>*							tail;
		size_t								sz;
	protected:
		typedef typename Allocator::template rebind<node<T> >::other	al;
		typedef node<T>						node;
	public:
		typedef	T 							value_type;
		typedef Allocator					allocator_type;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::const_reference	const_reference;
		typedef ListIterator<T>				iterator;
		typedef const iterator				const_iterator;
		typedef ListReverseIterator<T>		reverse_iterator;
		typedef const reverse_iterator		const_reverse_iterator;
		#include "./list/list.hpp"
	};
	//#include "./list/non_member.hpp"
	
	template <class T, class Allocator = std::allocator<T> >
	class	vector {
	private:
		T*									head;
		T*									tail;
		T* 									cap;
	//protected:
	public:
		typedef	T 							value_type;
		typedef Allocator					allocator_type;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::const_reference	const_reference;
		typedef VectorIterator<T>					iterator;
		typedef const iterator						const_iterator;
		typedef VectorReverseIterator<T>			reverse_iterator;
		typedef const reverse_iterator				const_reverse_iterator;
		#include "./vector/vector.hpp"
	};
	//#include "./vector/non_member.hpp"
	
	template <class T, class Container = std::deque<T> >
	class	stack {
	protected:
		Container									c;
	public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;
		#include "./stack/stack.hpp"
	};
	//#include "./stack/non_member.hpp"
	
	template <class T, class Container = std::deque<T> >
	class	queue {
	protected:
		Container									c;
	public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;
		#include "./queue/queue.hpp"
	};
	//#include "./queue/non_member.hpp"
	#include "./non_member.hpp"
}

#endif
