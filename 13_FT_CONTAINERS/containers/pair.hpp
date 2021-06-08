#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft{
	template <class T1, class T2>
	class	pair{
		public:
			T1				first;
			T2				second;
			typedef T1		first_type;
			typedef T2		second_type;
			pair();
			pair(const T1& x, const T2& y);
			template <class U1, class U2>
			pair(const pair<U1, U2>& p);
			pair(const pair& p);
			pair&	operator=(const pair& p);
			~pair();
	};

	template <class T1, class T2>
	pair<T1, T2>::pair() : first(0), second(0) {}

	template <class T1, class T2>
	pair<T1, T2>::pair(const T1& x, const T2& y) : first(x), second(y) {}
	
	template <class T1, class T2>
	template <class U1, class U2>
	pair<T1, T2>::pair(const pair<U1, U2>& p) : first(0), second(0) { *this = p; }
	
	template <class T1, class T2>
	pair<T1, T2>&	pair<T1, T2>::operator=(const pair<T1, T2>& other){
		if (this == &other)
			return *this;
		this->first = other.first;
		this->second = other.second;
		return *this;
	}
	
	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 t, T2 u){
		pair<T1, T2>*	tmp;

		tmp = new pair<T1, T2>(t, u);
		return *tmp;
	}
	
	template <class T1, class T2>
	bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return true;
		return false;
	}
	
	template <class T1, class T2>
	bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return false;
		return true;
	}

	template <class T1, class T2>
	bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
		if (lhs.first < rhs.first)
			return true;
		else if (lhs.first == rhs.first && lhs.second < rhs.second)
			return true;
		return false;
	}

	template <class T1, class T2>
	bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
		if (lhs.first < rhs.first)
			return true;
		else if (lhs.first == rhs.first && lhs.second <= rhs.second)
			return true;
		return false;
	}

	template <class T1, class T2>
	bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
		if (lhs.first > rhs.first)
			return true;
		else if (lhs.first == rhs.first && lhs.second > rhs.second)
			return true;
		return false;
	}
	
	template <class T1, class T2>
	bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
		if (lhs.first > rhs.first)
			return true;
		else if (lhs.first == rhs.first && lhs.second >= rhs.second)
			return true;
		return false;
	}
}

#endif
