#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

template<class T, class Category = ft::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	VectorIterator;
#include "vector_const_iterator.hpp"

template<class T, class Category, class Distance, class Pointer, class Reference>
	class	VectorIterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	protected:
		T*					ptr;
	public:
		VectorIterator() : ptr(0) {}
		VectorIterator(T* const p) : ptr(p) {}
		VectorIterator(VectorIterator const &it) { *this = it; }
		VectorIterator(VectorConstIterator<T> const &it) { *this = it; }
		VectorIterator&	operator=(VectorIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		VectorIterator&	operator=(VectorConstIterator<T> const &it){
			if (it.getPointer() == this->ptr)
				return *this;
			this->ptr = it.getPointer();
			return *this;
		}
		~VectorIterator() {}
		VectorIterator&		operator++(){
			this->ptr++;;
			return *this;
		}
		VectorIterator		operator++(int){
			this->ptr++;
			return VectorIterator(this->ptr);
		}
		VectorIterator&		operator--(){
			--this->ptr;
			return *this;
		}
		VectorIterator		operator--(int){
			--this->ptr;
			return VectorIterator(this->ptr);
		}
		VectorIterator&		operator+=(difference_type n){
			this->ptr += n;
			return *this;
		}
		VectorIterator&		operator-=(difference_type n){
			this->ptr -= n;
			return *this;
		}
		reference	operator[](difference_type n) const { return *(this->ptr + n); }
		reference	operator*() const { return getValue(); }
		pointer		operator->() const { return getPointer(); }
		reference	getValue() const { return *this->ptr; }
		pointer		getPointer() const { return this->ptr; }
};

template<class T>
VectorIterator<T>	operator+(VectorIterator<T> vi, ptrdiff_t n){
	return VectorIterator<T>(vi.getPointer() + n);
}

template<class T>
VectorIterator<T>	operator+(ptrdiff_t n, VectorIterator<T> vi){
	return VectorIterator<T>(vi.getPointer() + n);
}

template<class T>
VectorIterator<T>	operator-(VectorIterator<T> vi, ptrdiff_t n){
	return VectorIterator<T>(vi.getPointer() - n);
}

template<class T>
ptrdiff_t	operator-(VectorIterator<T> v, VectorIterator<T> i){
	return (v.getPointer() - i.getPointer());
}

template<class T>
bool	operator==(VectorIterator<T> const &a, VectorIterator<T> const &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator==(VectorIterator<T> const &a, VectorConstIterator<T> const &b){
	return a.getValue() == b.getValue();
}

template<class T>
bool	operator!=(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator!=(VectorIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() < b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<(VectorIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() < b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() > b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>(VectorIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() > b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<=(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() <= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator<=(VectorIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() <= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>=(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() >= b.getValue())
		return true;
	return false;
}

template<class T>
bool	operator>=(VectorIterator<T> const &a, VectorConstIterator<T> const &b){
	if (a.getValue() >= b.getValue())
		return true;
	return false;
}

#endif
