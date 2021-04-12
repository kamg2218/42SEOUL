#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template<typename T>
class	Array
{
	private:
		unsigned int	_n;
		T*				_array;
	public:
		Array() : _n(0), _array(0) { _array = new T(); }
		Array(unsigned int n) : _n(n), _array(0)
		{
			_array = new T[n];
			for (unsigned int i = 0; i < n; i++)
				_array[i] = 0;
		}
		Array(Array const &array) { *this = array; }
		Array&	operator=(Array const &array)
		{
			_n = array._n;
			_array = array._array;
			return *this;
		}
		T*	operator[](unsigned int num)
		{
			if (num >= _n || num < 0)
				throw OutOfTheLimits();
			return _array[num];
		}
		void*	operator new[](std::size_t num)
		{
			void*	tmp;
			
			if (num < 0)
				throw OutOfTheLimits();
			tmp = new T[num];
			return tmp;
		}
		~Array() { delete[] _array; }
		unsigned int	size() const { return _n; }
		T&				getNum(unsigned int num)
		{
			if (num >= _n)
				throw OutOfTheLimits();
			return _array[num];
		}
		class	OutOfTheLimits : public std::exception {
			public:
				virtual const char*	what() const throw(){
					return "The address is out of the limits\n";
				}
		};
};

#endif
