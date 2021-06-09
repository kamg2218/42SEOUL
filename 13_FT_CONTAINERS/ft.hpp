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
#include "./containers/pair.hpp"

namespace ft
{
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
		RBTNode<Key, T>		*last;
	};

	#include "./containers/iterator_tag.hpp"
	#include "./containers/list/list_iterator.hpp"
	#include "./containers/list/list_const_iterator.hpp"
	#include "./containers/list/list_reverse_iterator.hpp"
	#include "./containers/list/list_const_reverse_iterator.hpp"
	#include "./containers/vector/vector_iterator.hpp"
	#include "./containers/vector/vector_const_iterator.hpp"
	#include "./containers/vector/vector_reverse_iterator.hpp"
	#include "./containers/vector/vector_const_reverse_iterator.hpp"
	#include "./containers/map/map_iterator.hpp"
	#include "./containers/map/map_const_iterator.hpp"
	#include "./containers/map/map_reverse_iterator.hpp"
	#include "./containers/map/map_const_reverse_iterator.hpp"

	template <class T, class Allocator = std::allocator<T> >
	class	vector {
	private:
		T*											head;
		T*											tail;
		T* 											cap;
	public:
		typedef	T 									value_type;
		typedef Allocator							allocator_type;
		typedef size_t								size_type;
		typedef ptrdiff_t							difference_type;
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
		vector&		operator=(vector const &v);
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
		vector(T* first, T* last, const Allocator& alloc) : head(0), tail(0), cap(0) {
			allocator_type	al;

			head = al.allocate(last - first);
			tail = head;
			cap = head + (last - first);
			for (T*	i = first; i != last; i++)
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
		void	assign(T* first, T* last){
			clear();
			if (capacity() < last - first)
				reserve(last - first);
			for (T* i = first; i != last; i++)
				push_back(*i);
			tail += last - first;
		}
		allocator_type	get_allocator() const;
		iterator			begin();
		const_iterator		begin() const;
		iterator			end();
		const_iterator		end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
		reference	at(size_type pos);
		const_reference	at(size_type pos) const;
		reference operator[](size_type pos);
		const_reference operator[](size_type pos) const;
		reference	front();
		const_reference	front() const;
		reference	back();
		const_reference	back() const;
		bool		empty() const;
		size_type	size() const;
		size_type	capacity() const;
		size_type	max_size() const;
		void		reserve(size_type new_cap);
		void		clear();
		void		push_back(const T& value);
		void		pop_back();
		iterator	insert(iterator pos, const T& value);
		void		insert(iterator pos, size_type count, const T& value);
		template<class InputIt>
		void		insert(iterator pos, InputIt first, InputIt last);
		template<>
		void		insert(iterator pos, iterator first, iterator last){
			size_type	cnt;
		
			cnt = pos - begin();
			if (cap - tail < last - first)
				reserve((cap - head) * 2);
			for (size_type i = size(); i != cnt; i--)
				head[i + last - first] = head[i];
			head[cnt + last - first] = head[cnt];
			for (iterator i = first; i != last; i++)
				head[cnt++] = *i;
			tail += last - first;
		}
		iterator	erase(iterator pos);
		iterator	erase(iterator first, iterator last);
		void		resize(size_type count, T value = T());
		void		swap(vector& other);
	};

	template <class T, class Allocator = std::allocator<T> >
	class	list {
	private:
		node<T>*									head;
		size_t										sz;
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
		list(T* first, T* last, const Allocator& alloc) : head(0), sz(0) {
			push_back(0);
			for (T* i = first; i != last; i++)
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
		void	assign(T* first, T* last){
			clear();
			for (T* i = first; i != last; i++)
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
			ft::node<T>*		pre;
			ft::node<T>*		tmp;
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
	
	template <class T, class Container = ft::vector<T> >
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
	
	template <class T, class Container = ft::list<T> >
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

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	class	map {
	private:
		RBTNode<Key, T>								*tail;
		RBTNode<Key, T>								*head;
		size_t										sz;
	public:
		typedef typename Allocator::template rebind<RBTNode<Key,T> >::other	al;
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef typename std::pair<const Key, T>		value_type;
		typedef typename std::size_t				size_type;
		typedef typename std::ptrdiff_t				difference_type;
		typedef Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef MapIterator<Key, T>					iterator;
		typedef MapConstIterator<Key, T>			const_iterator;
		typedef MapReverseIterator<Key, T>			reverse_iterator;
		typedef MapConstReverseIterator<Key, T>		const_reverse_iterator;
		class value_compare;
		map();
		explicit map(const Compare& comp, const Allocator& alloc = Allocator());
		map(const map& other);
		map&	operator=(map const &m);
		template<class InputIt>
		map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator());
		template<>
		map(iterator first, iterator last, const Compare& comp, const Allocator& alloc) : head(0), tail(0), sz(0) {
			tail = make_node(std::make_pair(0, 0));
			head = tail;
			tail->left = tail;
			tail->right = tail;
			tail->last = tail;
			for (iterator i = first; i != last; i++)
				insert(i.getValue());
		}
		~map();
		allocator_type				get_allocator() const;
		iterator					begin();
		const_iterator				begin() const;
		iterator					end();
		const_iterator				end() const;
		reverse_iterator			rbegin();
		const_reverse_iterator		rbegin() const;
		reverse_iterator			rend();
		const_reverse_iterator		rend() const;
		T&	operator[](const Key& key);
		bool						empty() const;
		size_type					size() const;
		size_type					max_size() const;
		void						clear();
		std::pair<iterator, bool>	insert(const value_type& value);
		iterator					insert(iterator hint, const value_type& value);
		template<class InputIt>
		void		insert(InputIt first, InputIt last);
		template<>
		void		insert(iterator first, iterator last){
			for (iterator i = first; i != last; i++){
				if (find(i->first) != end())
					continue ;
				add_node(head, make_node(i.getValue()));
			}
		}
		iterator					erase(iterator pos);
		void						erase(iterator first, iterator last);
		size_type					erase(const key_type& key);
		void						swap(map& other);
		size_type					count(const Key& key);
		iterator					find(const Key& key);
		const_iterator				find(const Key& key) const;
		std::pair<iterator, iterator>	equal_range(const Key& key);
		std::pair<const_iterator, const_iterator>	equal_range (const Key& key) const;
		iterator					lower_bound(const Key& key);
		const_iterator				lower_bound(const Key& key) const;
		iterator					upper_bound(const Key& key);
		const_iterator				upper_bound(const Key& key) const;
		key_compare					key_comp() const;
		typename ft::map<Key, T>::value_compare		value_comp() const;
	protected:
		void				clear_node(RBTNode<Key, T>** node);
		RBTNode<Key, T>*	make_node(const value_type& value);
		RBTNode<Key, T>*	check_hint(iterator hint, RBTNode<Key, T>* node);
		//map_insert
		void	rebuild(RBTNode<Key, T> *node);
		void	rotateLeft(RBTNode<Key, T> *node);
		void	rotateRight(RBTNode<Key, T> *node);
		void	add_node(RBTNode<Key, T>* h, RBTNode<Key, T>* node);
		//map_delete
		void	del(RBTNode<Key, T> *node);
		void	del_left(RBTNode<Key, T> *node);
		void	del_right(RBTNode<Key, T> *node);
		void	one_node(RBTNode<Key, T> *node);
		void	del_one(RBTNode<Key, T> *node, RBTNode<Key, T> *child);
	};

	template<class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2){
		InputIt1 i = first1;
		InputIt2 j = first2;
		for (; i != last1 && j != last2; i++, j++){
			if (*i < *j)
				return true;
			else if (*i > *j)
				return false;
		}
		return false;
	}
	#include "./containers/non_member.hpp"
}

#endif
