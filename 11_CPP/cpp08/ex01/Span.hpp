#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <iterator>

class	Span
{
	private:
		unsigned int				_size;
		std::vector<unsigned int>	_v;
	public:
		Span();
		Span(unsigned int num);
		Span(Span const &sp);
		Span&	operator=(Span const &sp);
		~Span();
		void	addNumber(unsigned int num);
		template<typename T>
		void	addNumber(T begin, T end){
			if (std::distance(begin, end) > static_cast<long>(_size - _v.size()))
				throw NoMoreSpace();
			for (T i = begin; i < end; i++)
				_v.push_back(*i);
		}
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		unsigned int	size();
		class	NoMoreSpace : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class	NoExist : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class	NoSpanToFind : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

#endif
