#ifndef STACK_HPP
# define STACK_HPP

#include "../../utility.hpp"
#include "../../pair.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"

namespace	ft {
	template <class T, class Container = vector<T> >
	class	stack {
	protected:
		Container							c;
	public:
		typedef Container						container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

		explicit stack(const Container& cont = Container());
		stack(const stack& other);
		stack&		operator=(stack const &st);
		~stack();
		reference			top();
		size_type			size() const;
		bool				empty() const;
		void				push(const value_type& value);
		void				pop();
		void				swap(stack& other);
		const Container		getContainer() const;
	};

	template<class T, class Container>
	bool	operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return lhs.getContainer() == rhs.getContainer();
	}

	template<class T, class Container>
	bool	operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return lhs.getContainer() != rhs.getContainer();
	}

	template<class T, class Container>
	bool	operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return lhs.getContainer() < rhs.getContainer();
	}
	
	template<class T, class Container>
	bool	operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return lhs.getContainer() <= rhs.getContainer();
	}

	template<class T, class Container>
	bool	operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return lhs.getContainer() > rhs.getContainer();
	}

	template<class T, class Container>
	bool	operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return lhs.getContainer() >= rhs.getContainer();
	}
	
	template <class T, class Container>
	void	swap(stack<T, Container>& lhs, stack<T, Container>& rhs){
		lhs.swap(rhs);
	}
}

template <class T, class Container>
ft::stack<T, Container>::stack(const Container& cont) { }

template <class T, class Container>
ft::stack<T, Container>::stack(const stack<T, Container>& other) { *this = other; }

template <class T, class Container>
ft::stack<T, Container>&		ft::stack<T, Container>::operator=(stack<T, Container> const &st) {
	if (st == *this)
		return *this;
	this->c = st.c;
	return *this;
}

template <class T, class Container>
ft::stack<T, Container>::~stack() {}

template <class T, class Container>
const Container	ft::stack<T, Container>::getContainer() const { return this->c; }

template <class T, class Container>
typename ft::stack<T, Container>::reference	ft::stack<T, Container>::top() { return this->c.back(); }

template <class T, class Container>
bool		ft::stack<T, Container>::empty() const { if (c.empty()) return true; else return false;}

template <class T, class Container>
typename ft::stack<T, Container>::size_type	ft::stack<T, Container>::size() const { return this->c.size(); }

template <class T, class Container>
void		ft::stack<T, Container>::push(const value_type& value) { this->c.push_back(value); }

template <class T, class Container>
void		ft::stack<T, Container>::pop() { this->c.pop_back(); }

template <class T, class Container>
void		ft::stack<T, Container>::swap(stack<T, Container>& other) { c.swap(other.c); }

#endif
