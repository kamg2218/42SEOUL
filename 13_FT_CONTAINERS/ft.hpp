#ifndef FT_HPP
# define FT_HPP

#include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class	list {
		typedef value_type 			= T;
		typedef allocator_type		= allocator;
		typedef size_type			= size_t;
		typedef difference_type		= ptrdiff_t;
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
