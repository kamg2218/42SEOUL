#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP

template<class T, class Category = ft::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	VectorReverseIterator;
#include "vector_const_reverse_iterator.hpp"

template<class T, class Category, class Distance, class Pointer, class Reference>
class	VectorReverseIterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	protected:
		T*					ptr;
	public:
		VectorReverseIterator() : ptr(0) {}
		VectorReverseIterator(T* const p) : ptr(p) {}
		VectorReverseIterator(VectorReverseIterator const &it) { *this = it; }
		VectorReverseIterator(VectorConstReverseIterator<T> const &it) { *this = it; }
		VectorReverseIterator&	operator=(VectorReverseIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		VectorReverseIterator&	operator=(VectorConstReverseIterator<T> const &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		~VectorReverseIterator() {}
		VectorReverseIterator&		operator++(){
			--this->ptr;
			return *this;
		}
		VectorReverseIterator		operator++(int){
			this->ptr--;
			return VectorReverseIterator(this->ptr);
		}
		VectorReverseIterator&		operator--(){
			++this->ptr;
			return *this;
		}
		VectorReverseIterator		operator--(int){
			this->ptr++;
			return VectorReverseIterator(this->ptr);
		}
		VectorReverseIterator&		operator+=(difference_type n){
			this->ptr -= n;
			return *this;
		}
		VectorReverseIterator&		operator-=(difference_type n){
			this->ptr += n;
			return *this;
		}
		reference	operator[](difference_type n) const { return *(this->ptr - n); }
		reference	operator*() const { return getValue(); }
		pointer		operator->() const { return getPointer(); }
		reference	getValue() const { return *this->ptr; }
		pointer		getPointer() const { return this->ptr; }
};

template<class T>
VectorReverseIterator<T>	operator+(VectorReverseIterator<T> vi, ptrdiff_t n){
	return VectorReverseIterator<T>(vi.ptr - n);
}

template<class T>
VectorReverseIterator<T>	operator+(ptrdiff_t n, VectorReverseIterator<T> vi){
	return VectorReverseIterator<T>(vi.ptr - n);
}

template<class T>
VectorReverseIterator<T>	operator-(VectorReverseIterator<T> vi, ptrdiff_t n){
	return VectorReverseIterator<T>(vi.ptr + n);
}

template<class T>
ptrdiff_t	operator-(VectorReverseIterator<T> v, VectorReverseIterator<T> i){
	return (i.ptr - v.ptr);
}

template<class T>
bool	operator==(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator==(VectorReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(VectorReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() < b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<(VectorReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() < b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() > b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>(VectorReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() > b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<=(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() <= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<=(VectorReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() <= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>=(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() >= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>=(VectorReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() >= b.getValue())
		return true;
	return false;
}

#endif
