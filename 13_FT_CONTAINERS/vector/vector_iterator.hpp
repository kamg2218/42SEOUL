#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <iterator>
	
template<class T, class Category = std::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class	VectorIterator : public std::iterator<Category, T> {
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
			ptr++;
			return VectorIterator(this->ptr);
		}
		VectorIterator&		operator--(){
			--ptr;
			return *this;
		}
		VectorIterator		operator--(int){
			ptr--;
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
};

template<class T>
VectorIterator<T>	operator+(VectorIterator<T> vi, difference_type n){
	return VectorIterator<T>(vi.ptr + n);
}

template<class T>
VectorIterator<T>	operator+(difference_type n, VectorIterator<T> vi){
	return VectorIterator<T>(vi.ptr + n);
}

template<class T>
VectorIterator<T>	operator-(VectorIterator<T> vi, difference_type n){
	return VectorIterator<T>(vi.ptr - n);
}

template<class T>
difference_type		operator-(VectorIterator<T> v, VectorIterator<T> i){
	return (v.ptr - i.ptr);
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
