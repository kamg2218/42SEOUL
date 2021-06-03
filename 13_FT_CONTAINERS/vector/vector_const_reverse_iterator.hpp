#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
# define VECTOR_CONST_REVERSE_ITERATOR_HPP

#include "../ft.hpp"

template<class T, class Category = ft::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	VectorConstReverseIterator {
	protected:
		T*					ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	
		VectorConstReverseIterator() : ptr(0) {}
		VectorConstReverseIterator(T* const p) : ptr(p) {}
		VectorConstReverseIterator(VectorConstReverseIterator const &it) { *this = it; }
		VectorConstReverseIterator&	operator=(VectorConstReverseIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
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
		reference			operator*() const { return getValue(); }
		pointer				operator->() const { return getPointer(); }
		const reference		getValue() const { return *ptr; }
		const pointer		getPointer() const { return ptr; }
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
bool	operator==(VectorConstReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() == b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator!=(VectorConstReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator<(VectorConstReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() < b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator>(VectorConstReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() > b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator<=(VectorConstReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() <= b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator>=(VectorConstReverseIterator<T> const &a, VectorConstReverseIterator<T> const &b){
	if (a.getValue() >= b.getValue())
		return true;
	else
		return false;
}

#endif
