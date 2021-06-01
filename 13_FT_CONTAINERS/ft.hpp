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
		//#include "./list/list.hpp"
		node*		malloc();
		void		add_back(const T& value);
		list();
		list(const list& other);
		list&	operator=(list const &lst);
		explicit list(const Allocator& alloc);
		explicit list(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template<class InputIt>
		list(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		//template<>
		//list(iterator first, iterator last, const Allocator& alloc) : sz(0), head(0), tail(0) {
		//template<>
		//list(T* first, T* last, const Allocator& alloc) : sz(0), head(0), tail(0) {
		~list();
		void	assign(size_type count, const T& value);
		template<class InputIt>
		void	assign(InputIt first, InputIt last);
		//template<>
		//void	assign(iterator first, iterator last){
		//template<>
		//void	assign(T* first, T* last){
		allocator_type	get_allocator() const;
		iterator			begin();
		const_iterator		begin() const;
		iterator			end();
		const_iterator		end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
		reference	front();
		const_reference	front() const;
		reference	back();
		const_reference	back() const;
		bool		empty() const;
		size_type	size() const;
		size_type	max_size() const;
		void		clear();
		void		push_front(const T& value);
		void		pop_front();
		void		push_back(const T& value);
		void		pop_back();
		iterator	insert(iterator pos, const T& value);
		void		insert(iterator pos, size_type count, const T& value);
		template<class InputIt>
		void		insert(iterator pos, InputIt first, InputIt last);
		//template<>
		//void		insert(iterator pos, iterator first, iterator last){
		iterator	erase(iterator pos);
		iterator	erase(iterator first, iterator last);
		void		resize(size_type count, T value = T());
		void		swap(list& other);
		void		move_node(node* src, node* dst);
		void		sort();
		template<class Compare>
		void		sort(Compare cmp);
		void		merge(list& other);
		template <class Compare>
		void		merge(list& other, Compare comp);
		void		splice(const_iterator pos, list& other);
		void		splice(const_iterator pos, list& other, const_iterator it);
		void		splice(const_iterator pos, list& other, const_iterator first, const_iterator last);
		void		remove(const T& value);
		template<class UnaryPredicate>
		void		remove_if(UnaryPredicate p);
		void		reverse();
		void		unique();
		template<class BinaryPredicate>
		void		unique(BinaryPredicate p);
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
		
		explicit stack(const Container& cont = Container());
		stack(const stack& other);
		stack&		operator=(stack const &st);
		~stack();
		const Container	getContainer() const;
		reference		top();
		size_type		size() const;
		bool			empty() const;
		void			push(const value_type& value);
		void			pop();
		void			swap(stack& other);
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
		
		explicit queue(const Container& cont = Container());
		queue(const queue& other);
		queue&			operator=(queue const &st);
		~queue();
		const Container	getContainer() const;
		reference		front();
		reference		back();
		bool			empty() const;
		size_type		size() const;
		void			push(const value_type& value);
		void			pop();
		void			swap(queue& other);
	};
	//#include "./queue/non_member.hpp"
/*
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
		//#include "./map/map_bfs.hpp"
		//#include "./map/map_insert.hpp"
		//#include "./map/map_delete.hpp"
		#include "./map/map.hpp"
	};
	//#include "./map/non_member.hpp"
*/
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
