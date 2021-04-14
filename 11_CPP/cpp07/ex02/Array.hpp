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
			_array = new T[n]();
		}
		Array(Array const &array) { *this = array; }
		Array&	operator=(Array const &array)
		{
			_n = array._n;
			delete[] _array;
			_array = new T[_n];
			for (unsigned int i = 0; i < _n; i++)
				_array[i] = array._array[i];
			return *this;
		}
		T&	operator[](unsigned int num)
		{
			if (num >= _n || num < 0)
				throw OutOfTheLimits();
			return _array[num];
		}
		const T&	operator[](unsigned int num) const
		{
			if (num >= _n || num < 0)
				throw OutOfTheLimits();
			return _array[num];
		}
		void*	operator new[](std::size_t num)
		{
			void*	tmp;
			
			tmp = new T[num];
			return tmp;
		}
		~Array() { delete[] _array; }
		unsigned int	size() const { return _n; }
		class	OutOfTheLimits : public std::exception {
			public:
				virtual const char*	what() const throw(){
					return "The address is out of the limits\n";
				}
		};
};

#endif
