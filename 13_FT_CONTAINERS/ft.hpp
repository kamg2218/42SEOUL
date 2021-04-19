#ifndef FT_HPP
# define FT_HPP

#include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class	list {
		using value_type = T;
		using allocator_type	= Allocator;
		using size_type			= size_t;
	};

	class	vector {
	};

	class	map {
	};

	class	stack {
	};

	class	queue {
	};
}

#endif
