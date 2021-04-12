#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	print(T a)
{
	std::cout << a;
	return ;
}

template<typename T>
void	iter(T *array, unsigned int size, void (*func)(T))
{
	for (unsigned int i = 0; i < size; i++)
		func(array[i]);
}

#endif
