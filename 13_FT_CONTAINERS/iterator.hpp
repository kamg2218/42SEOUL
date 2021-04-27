#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>

template<class T, class Category = std::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	Iterator : public std::iterator<Category, T> {
	protected:
		Pointer				ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;

		Iterator() : ptr(0) {}
		Iterator(pointer const p) : ptr(p) {}
		Iterator(Iterator const &it) { *this = it; }
		Iterator&	operator=(Iterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~Iterator() {}
		Iterator&		operator++(){
			this->ptr += 1;
			return *this;
		}
		Iterator&		operator--(){
			this->ptr -= 1;
			return *this;
		}
		T&		operator*() const { return *ptr; }
		T&		operator->() const { return *ptr; }
};

#endif
