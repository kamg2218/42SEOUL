#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <iterator>
	
template<class T, class Category = std::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	VectorIterator {
	protected:
		T*					ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	
		VectorIterator() : ptr(0) {}
		VectorIterator(T* const p) : ptr(p) {}
		VectorIterator(VectorIterator const &it) { *this = it; }
		VectorIterator&	operator=(VectorIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~VectorIterator() {}
		VectorIterator&		operator++(){
			++ptr;
			return *this;
		}
		VectorIterator		operator++(int){
			++ptr;
			return VectorIterator(this->ptr);
		}
		VectorIterator&		operator--(){
			--ptr;
			return *this;
		}
		VectorIterator		operator--(int){
			--ptr;
			return VectorIterator(this->ptr);
		}
		VectorIterator&		operator+=(difference_type n){
			ptr += n;
			return *this;
		}
		VectorIterator&		operator-=(difference_type n){
			ptr -= n;
			return *this;
		}
		reference	operator[](difference_type n) const { return *(ptr + n); }
		reference	operator*() const { return getValue(); }
		pointer		operator->() const { return ptr; }
		reference	getValue() const { return *ptr; }
		pointer		getPointer() const { return ptr; }
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
	if (a.getValue() == b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator!=(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator<(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() < b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator>(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() > b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator<=(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() <= b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator>=(VectorIterator<T> const &a, VectorIterator<T> const &b){
	if (a.getValue() >= b.getValue())
		return true;
	else
		return false;
}

#endif
