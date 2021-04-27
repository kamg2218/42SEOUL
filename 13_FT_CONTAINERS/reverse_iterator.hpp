#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <iterator>

template<class T, class Category = std::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	ReverseIterator : public std::iterator<Category, T> {
	protected:
		Pointer				ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;

		ReverseIterator() : ptr(0) {}
		ReverseIterator(pointer const p) : ptr(p) {}
		ReverseIterator(ReverseIterator const &rit) { *this = rit; }
		ReverseIterator&	operator=(ReverseIterator const &rit){
			if (&rit == this)
				return *this;
			this->ptr = rit.ptr;
			return *this;
		}
		~ReverseIterator() {}
		ReverseIterator&		operator++(){
			this->ptr -= 1;
			return *this;
		}
		ReverseIterator&		operator--(){
			this->ptr += 1;
			return *this;
		}
		T&		operator*() const { return *ptr; }
		T&		operator->() const { return *ptr; }
};

#endif
