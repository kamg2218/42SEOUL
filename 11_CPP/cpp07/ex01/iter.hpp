#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	print(T a)
{
	std::cout << a << std::endl;
	return ;
}

template<typename T>
void	iter(T *array, unsigned int size, void (*func)(T))
{
	for (unsigned int i = 0; i < size; i++)
		func(array[i]);
}

/*
class Awesome
{
	private:
		int	_n;
	public:
		Awesome(void): _n(42) { return ;}
		int	get(void) const { return this->_n; }
};

std::ostream&	operator<<(std::ostream& os, Awesome const &rhs)
{
	os << rhs.get();
	return os;
}
*/
#endif
