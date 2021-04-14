#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T		min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>
T		max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}

/*
class	Awesome{
	private:
		int	_n;
	public:
		Awesome() : _n(0) {}
		Awesome(int n) : _n(n) {}
		bool operator==(Awesome const &rhs) { return (this->_n == rhs._n); }
		bool operator!=(Awesome const &rhs) { return (this->_n != rhs._n); }
		bool operator>(Awesome const &rhs) { return (this->_n > rhs._n); }
		bool operator<(Awesome const &rhs) { return (this->_n < rhs._n); }
		bool operator>=(Awesome const &rhs) { return (this->_n >= rhs._n); }
		bool operator<=(Awesome const &rhs) { return (this->_n <= rhs._n); }
		int	getNum() const { return _n; }
};

std::ostream&	operator<<(std::ostream &os, Awesome const &rhs)
{
	os << rhs.getNum();
	return os;
}
*/
#endif
