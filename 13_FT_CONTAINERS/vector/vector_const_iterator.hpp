#ifndef VECTOR_CONST_ITERATOR_HPP
# define VECTOR_CONST_ITERATOR_HPP

#include "../ft.hpp"
template<class T, class Category = ft::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	VectorConstIterator;
#include "vector_iterator.hpp"

template<class T, class Category, class Distance, class Pointer, class Reference>
class	VectorConstIterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	protected:
		T*					ptr;
	public:
		VectorConstIterator() : ptr(0) {}
		VectorConstIterator(T* const p) : ptr(p) {}
		VectorConstIterator(VectorConstIterator const &it) { *this = it; }
		VectorConstIterator(VectorIterator<T> const &it) { *this = it; }
		VectorConstIterator&	operator=(VectorConstIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		VectorConstIterator&	operator=(VectorIterator<T> const &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~VectorConstIterator() {}
		VectorConstIterator&		operator++(){
			++ptr;
			return *this;
		}
		VectorConstIterator		operator++(int){
			++ptr;
			return VectorConstIterator(this->ptr);
		}
		VectorConstIterator&		operator--(){
			--ptr;
			return *this;
		}
		VectorConstIterator		operator--(int){
			--ptr;
			return VectorConstIterator(this->ptr);
		}
		VectorConstIterator&		operator+=(difference_type n){
			ptr += n;
			return *this;
		}
		VectorConstIterator&	operator-=(difference_type n){
			ptr -= n;
			return *this;
		}
		const reference		operator[](difference_type n) const { return *(ptr + n); }
		const reference		operator*() const { return getValue(); }
		const pointer		operator->() const { return getPointer(); }
		reference			getValue() const { return *ptr; }
		pointer				getPointer() const { return ptr; }
};

template<class T>
VectorConstIterator<T>	operator+(VectorConstIterator<T> vi, ptrdiff_t n){
	return VectorConstIterator<T>(vi.getPointer() + n);
}

template<class T>
VectorConstIterator<T>	operator+(ptrdiff_t n, VectorConstIterator<T> vi){
	return VectorConstIterator<T>(vi.getPointer() + n);
}

template<class T>
VectorConstIterator<T>	operator-(VectorConstIterator<T> vi, ptrdiff_t n){
	return VectorConstIterator<T>(vi.getPointer() - n);
}

template<class T>
ptrdiff_t	operator-(VectorConstIterator<T> v, VectorConstIterator<T> i){
	return (v.getPointer() - i.getPointer());
}

template<class T>
bool	operator==(VectorConstIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator==(VectorConstIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(VectorConstIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(VectorConstIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<(VectorConstIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() < b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<(VectorConstIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() < b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>(VectorConstIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() > b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>(VectorConstIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() > b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<=(VectorConstIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() <= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<=(VectorConstIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() <= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>=(VectorConstIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() >= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>=(VectorConstIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() >= b.getValue())
		return true;
	return false;
}

#endif
