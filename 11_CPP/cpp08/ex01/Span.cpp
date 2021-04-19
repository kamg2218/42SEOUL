#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(Span const &sp)
{
	*this = sp;
}

Span&	Span::operator=(Span const &sp)
{
	if (this == &sp)
		return *this;
	this->_size = sp._size;
	for (unsigned int i = 0; i < _size; i++)
		this->_v.push_back(sp._v[i]);
	return *this;
}

Span::~Span() {}

void	Span::addNumber(unsigned int num)
{
	if (_v.size() >= _size)
		throw NoMoreSpace();
	_v.push_back(num);
}

unsigned int	Span::size() { return _v.size(); }

unsigned int	Span::shortestSpan()
{
	unsigned int	min;
	std::vector<unsigned int>	tmp = _v;

	if (_v.size() <= 1)
		throw NoSpanToFind();
	sort(tmp.begin(), tmp.end());
	min = tmp[1] - tmp[0];
	for (unsigned int i = 0; i < tmp.size() - 1; i++)
	{
		if (min > tmp[i + 1] - tmp[i])
			min = tmp[i + 1] - tmp[i];
	}
	return min;
}

unsigned int	Span::longestSpan()
{
	std::vector<unsigned int>	tmp = _v;

	if (_v.size() <= 1)
		throw NoSpanToFind();
	sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

const char*	Span::NoMoreSpace::what() const throw()
{
	return "No More Space\n";
}

const char*	Span::NoExist::what() const throw()
{
	return "No Exist\n";
}

const char*	Span::NoSpanToFind::what() const throw()
{
	return "No Span To Find\n";
}
