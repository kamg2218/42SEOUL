#ifndef UTILITY_HPP
# define UTILITY_HPP

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
}

#endif
