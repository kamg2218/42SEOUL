#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
# define VECTOR_CONST_REVERSE_ITERATOR_HPP

template<class T, class Category = ft::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	VectorConstReverseIterator;
#include "vector_reverse_iterator.hpp"

template<class T, class Category, class Distance, class Pointer, class Reference>
class	VectorConstReverseIterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	protected:
		T*					ptr;
	public:
		VectorConstReverseIterator() : ptr(0) {}
		VectorConstReverseIterator(T* const p) : ptr(p) {}
		VectorConstReverseIterator(const VectorConstReverseIterator &it) { *this = it; }
		VectorConstReverseIterator(const VectorReverseIterator<T> &it) { *this = it; }
		VectorConstReverseIterator&	operator=(const VectorConstReverseIterator &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		VectorConstReverseIterator&	operator=(const VectorReverseIterator<T> &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		~VectorConstReverseIterator() {}
		VectorConstReverseIterator&		operator++(){
			--ptr;
			return *this;
		}
		VectorConstReverseIterator		operator++(int){
			ptr--;
			return VectorConstReverseIterator(this->ptr);
		}
		VectorConstReverseIterator&		operator--(){
			++ptr;
			return *this;
		}
		VectorConstReverseIterator		operator--(int){
			ptr++;
			return VectorConstReverseIterator(this->ptr);
		}
		VectorConstReverseIterator&		operator+=(difference_type n){
			ptr -= n;
			return *this;
		}
		VectorConstReverseIterator&		operator-=(difference_type n){
			ptr += n;
			return *this;
		}
		reference	operator[](difference_type n) const { return *(ptr - n); }
		const reference		operator*() const { return getValue(); }
		const pointer		operator->() const { return getPointer(); }
		reference			getValue() const { return *ptr; }
		pointer				getPointer() const { return ptr; }
};

template<class T>
VectorConstReverseIterator<T>	operator+(VectorConstReverseIterator<T> vi, ptrdiff_t n){
	return VectorConstReverseIterator<T>(vi.ptr - n);
}

template<class T>
VectorConstReverseIterator<T>	operator+(ptrdiff_t n, VectorConstReverseIterator<T> vi){
	return VectorConstReverseIterator<T>(vi.ptr - n);
}

template<class T>
VectorConstReverseIterator<T>	operator-(VectorConstReverseIterator<T> vi, ptrdiff_t n){
	return VectorConstReverseIterator<T>(vi.ptr + n);
}

template<class T>
ptrdiff_t	operator-(VectorConstReverseIterator<T> v, VectorConstReverseIterator<T> i){
	return (i.ptr - v.ptr);
}

template<class T>
bool	operator==(const VectorConstReverseIterator<T> &a, const VectorConstReverseIterator<T> &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator==(const VectorConstReverseIterator<T> &a, const VectorReverseIterator<T> &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator!=(const VectorConstReverseIterator<T> &a, const VectorConstReverseIterator<T> &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(const VectorConstReverseIterator<T> &a, const VectorReverseIterator<T> &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<(const VectorConstReverseIterator<T> &a, const VectorConstReverseIterator<T> &b){
	if (a.getValue() < b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<(const VectorConstReverseIterator<T> &a, const VectorReverseIterator<T> &b){
	if (a.getValue() < b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>(const VectorConstReverseIterator<T> &a, const VectorConstReverseIterator<T> &b){
	if (a.getValue() > b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>(const VectorConstReverseIterator<T> &a, const VectorReverseIterator<T> &b){
	if (a.getValue() > b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<=(const VectorConstReverseIterator<T> &a, const VectorConstReverseIterator<T> &b){
	if (a.getValue() <= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<=(const VectorConstReverseIterator<T> &a, const VectorReverseIterator<T> &b){
	if (a.getValue() <= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>=(const VectorConstReverseIterator<T> &a, const VectorConstReverseIterator<T> &b){
	if (a.getValue() >= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>=(const VectorConstReverseIterator<T> &a, const VectorReverseIterator<T> &b){
	if (a.getValue() >= b.getValue())
		return true;
	return false;
}

#endif
