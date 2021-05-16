#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP

#include <iterator>
	
template<class T, class Category = std::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	VectorReverseIterator : public std::iterator<Category, T> {
	protected:
		T*					ptr;
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	
		VectorReverseIterator() : ptr(0) {}
		VectorReverseIterator(T* const p) : ptr(p) {}
		VectorReverseIterator(VectorReverseIterator const &it) { *this = it; }
		VectorReverseIterator&	operator=(VectorReverseIterator const &it){
			if (&it == this)
				return *this;
			this->ptr = it.ptr;
			return *this;
		}
		~VectorReverseIterator() {}
		VectorReverseIterator&		operator++(){
			--ptr;
			return *this;
		}
		VectorReverseIterator		operator++(int){
			ptr--;
			return VectorReverseIterator(this->ptr);
		}
		VectorReverseIterator&		operator--(){
			++ptr;
			return *this;
		}
		VectorReverseIterator		operator--(int){
			ptr++;
			return VectorReverseIterator(this->ptr);
		}
		VectorReverseIterator&		operator+=(difference_type n){
			ptr -= n;
			return *this;
		}
		VectorReverseIterator&		operator-=(difference_type n){
			ptr += n;
			return *this;
		}
		reference	operator[](difference_type n) const { return *(ptr - n); }
		reference	operator*() const { return getValue(); }
		pointer		operator->() const { return ptr; }
		reference	getValue() const { return *ptr; }
		pointer		getPointer() const { return ptr; }
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
	else
		return false;
}

template<class T>
bool	operator!=(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() != b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator<(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() < b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator>(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() > b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator<=(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() <= b.getValue())
		return true;
	else
		return false;
}

template<class T>
bool	operator>=(VectorReverseIterator<T> const &a, VectorReverseIterator<T> const &b){
	if (a.getValue() >= b.getValue())
		return true;
	else
		return false;
}

#endif
