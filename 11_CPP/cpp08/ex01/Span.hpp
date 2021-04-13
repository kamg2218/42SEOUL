#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>

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
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		class	NoMoreSpace : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class	NoExist : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

#endif
