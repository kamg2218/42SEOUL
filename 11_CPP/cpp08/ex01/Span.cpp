#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(Span const &sp)
{
	*this = sp;
}

Span&	Span::operator=(Span const &sp)
{
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

unsigned int	Span::shortestSpan()
{
	unsigned int	min;

	if (_v.size() == 0)
		return 0;
	min = this->_v[0];
	for (unsigned int i = 1; i < _v.size(); i++){
		if (min > _v[i])
			min = _v[i];
	}
	return min;
}

unsigned int	Span::longestSpan()
{
	unsigned int	max;

	if (_v.size() == 0)
		return 0;
	max = this->_v[0];
	for (unsigned int i = 1; i < _v.size(); i++){
		if (max < _v[i])
			max = _v[i];
	}
	return max;
}

const char*	Span::NoMoreSpace::what() const throw()
{
	return "No More Space\n";
}

const char*	Span::NoExist::what() const throw()
{
	return "No Exist\n";
}
