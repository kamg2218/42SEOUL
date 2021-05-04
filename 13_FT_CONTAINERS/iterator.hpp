#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>
	
template <class T>
struct node {
	T*			value;
	node<T>		*prev;
	node<T>		*next;
};

template<class T, class Category = std::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	Iterator : public std::iterator<Category, T> {
	protected:
		node<T>*			ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;

		Iterator() : ptr(0) {}
		Iterator(node<T>* const p) : ptr(p) {}
		Iterator(Iterator const &it) { *this = it; }
		Iterator&	operator=(Iterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~Iterator() {}
		Iterator&		operator++(){
			this->ptr = this->ptr->next;
			return *this;
		}
		Iterator&		operator++(int zero){
			zero = zero;
			this->ptr = this->ptr->next;
			return *this;
		}
		Iterator&		operator--(){
			this->ptr = this->prt->prev;
			return *this;
		}
		Iterator&		operator--(int zero){
			zero = zero;
			this->ptr = this->prt->prev;
			return *this;
		}
		reference	operator*() const { return getValue(); }
		reference	operator->() const { return getValue(); }
		reference	getValue() const { return *(ptr->value); }
};

template<class T>
bool	operator==(Iterator<T> const &a, Iterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator!=(Iterator<T> const &a, Iterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	else
		return false;
}

#endif
