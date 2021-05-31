#ifndef FT_HPP
# define FT_HPP

#include <iostream>
#include <algorithm>
#include <memory>		//std::allocator
#include <typeinfo>
#include <limits>
#include <stdexcept>
#include <utility>		//std::pair
#include <functional>	//std::less
#include <deque>		//ft::stack

template <class T>
struct node {
	T			value;
	node<T>		*prev;
	node<T>		*next;
};

enum Color { RED, BLACK };
template <class Key, class T>
struct RBTNode {
	enum Color	color;
	std::pair<Key, T>	value;
	RBTNode<Key, T>		*parent;
	RBTNode<Key, T>		*left;
	RBTNode<Key, T>		*right;
};

namespace ft
{
	#include "iterator_tag.hpp"
	#include "./list/list_iterator.hpp"
	#include "./list/list_reverse_iterator.hpp"
	#include "./vector/vector_iterator.hpp"
	#include "./vector/vector_reverse_iterator.hpp"
	#include "./map/map_iterator.hpp"
	#include "./map/map_reverse_iterator.hpp"

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
		/*
		explicit stack(const Container& cont = Container());
		stack(const stack& other);
		stack&		operator=(stack const &st);
		~stack();
		const Container	getContainer() const;
		reference	top();
		bool		empty() const;
		size_type	size() const;
		void		push(const value_type& value);
		void		pop();
		void		swap(stack& other);
		*/
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
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	class	map {
	private:
		RBTNode<Key, T>								*head;
		RBTNode<Key, T>								tail;
		size_t										sz;
	public:
		typedef typename Allocator::template rebind<RBTNode<Key,T> >::other	al;
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef typename std::pair<const Key, T>	value_type;
		typedef typename std::size_t				size_type;
		typedef typename std::ptrdiff_t				difference_type;
		typedef Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef MapIterator<Key, T>					iterator;
		typedef const iterator						const_iterator;
		typedef MapReverseIterator<Key, T>			reverse_iterator;
		typedef const reverse_iterator				const_reverse_iterator;
		#include "./map/map_bfs.hpp"
		#include "./map/map.hpp"
		//#include "./map/map_insert.hpp"
		//#include "./map/map_delete.hpp"
	};
	//#include "./map/non_member.hpp"
	template<class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2){
		InputIt1 i = first1;
		InputIt2 j = first2;
		for (; i != last1 && j != last2; i++, j++){
			if (*i < *j)
				continue;
			else
				return false;
		}
		return true;
	}
	#include "./non_member.hpp"
}

#endif
