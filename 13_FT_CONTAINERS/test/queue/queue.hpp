#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "../utility.hpp"
#include "../pair.hpp"
#include "../list/list.hpp"

namespace	ft {
	template <class T, class Container = list<T> >
	class	queue {
	protected:
		Container							c;
	public:
		typedef Container						container_type;
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

	template<class T, class Container>
	bool	operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return lhs.getContainer() == rhs.getContainer();
	}

	template<class T, class Container>
	bool	operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return lhs.getContainer() != rhs.getContainer();
	}

	template<class T, class Container>
	bool	operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return lhs.getContainer() < rhs.getContainer();
	}

	template<class T, class Container>
	bool	operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return lhs.getContainer() <= rhs.getContainer();
	}

	template<class T, class Container>
	bool	operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return lhs.getContainer() > rhs.getContainer();
	}

	template<class T, class Container>
	bool	operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs){
		return lhs.getContainer() >= rhs.getContainer();
	}

	template <class T, class Container>
	void	swap(queue<T, Container>& lhs, queue<T, Container>& rhs){
		lhs.swap(rhs);
	}
}

template <class T, class Container>
ft::queue<T, Container>::queue(const Container& cont) {}

template <class T, class Container>
ft::queue<T, Container>::queue(const queue<T, Container>& other) { *this = other; }

template <class T, class Container>
ft::queue<T, Container>&		ft::queue<T, Container>::operator=(queue<T, Container> const &st) {
	if (&st == this)
		return *this;
	this->c = st.c;
	return *this;
}

template <class T, class Container>
ft::queue<T, Container>::~queue() {}

template <class T, class Container>
const Container	ft::queue<T, Container>::getContainer() const { return this->c; }

//access
template <class T, class Container>
typename ft::queue<T, Container>::reference	ft::queue<T, Container>::front() { return this->c.front(); }
template <class T, class Container>
typename ft::queue<T, Container>::reference	ft::queue<T, Container>::back() { return this->c.back(); }

//capacity
template <class T, class Container>
bool		ft::queue<T, Container>::empty() const { if (this->c.empty()) return true; else return false;}
template <class T, class Container>
typename ft::queue<T, Container>::size_type	ft::queue<T, Container>::size() const { return this->c.size(); }

//modifiers
template <class T, class Container>
void		ft::queue<T, Container>::push(const queue<T, Container>::value_type& value) { this->c.push_back(value); }
template <class T, class Container>
void		ft::queue<T, Container>::pop() { this->c.pop_front(); }
template <class T, class Container>
void		ft::queue<T, Container>::swap(queue<T, Container>& other) { this->c.swap(other.c); }

#endif
