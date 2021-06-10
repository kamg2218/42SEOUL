#ifndef UTILITY_HPP
# define UTILITY_HPP

#include <stdexcept>
#include <memory>
#include <cstdint>

namespace	ft{

	template<class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2){
		InputIt1 i = first1;
		InputIt2 j = first2;
		for (; i != last1 && j != last2; i++, j++){
			if (*i < *j)
				return true;
			else if (*i > *j)
				return false;
		}
		if (j != last2)
			return true;
		return false;
	}

	template<class T>
	struct		less {
		typedef bool	result_type;
		typedef T		first_argument_type;
		typedef T		second_argument_type;
		bool	operator()(const T& lhs, const T& rhs) const {
			return lhs < rhs;
		}
	};

	template<class T>
	T	numeric_limits(){ return T(); }
	template<>
	bool	numeric_limits() { return true; }
	template<>
	char	numeric_limits() { return CHAR_MAX; }
	template<>
	signed char	numeric_limits() { return SCHAR_MAX; }
	template<>
	unsigned char	numeric_limits() { return UCHAR_MAX; }
	template<>
	wchar_t	numeric_limits() { return WCHAR_MAX; }
	template<>
	char16_t	numeric_limits() { return UINT_LEAST16_MAX; }
	template<>
	char32_t	numeric_limits() { return UINT_LEAST32_MAX; }
	template<>
	short	numeric_limits() { return SHRT_MAX; }
	template<>
	unsigned short	numeric_limits() { return USHRT_MAX; }
	template<>
	int	numeric_limits() { return INT_MAX; }
	template<>
	unsigned int	numeric_limits() { return UINT_MAX; }
	template<>
	long	numeric_limits() { return LONG_MAX; }
	template<>
	unsigned long	numeric_limits() { return ULONG_MAX; }
	template<>
	long long	numeric_limits() { return LLONG_MAX; }
	template<>
	unsigned long long	numeric_limits() { return ULLONG_MAX; }
}

#endif
