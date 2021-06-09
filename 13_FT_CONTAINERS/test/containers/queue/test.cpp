#include <stack>
#include <vector>
#include <list>
#include <iostream>
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../stack/stack.hpp"

int		main(){
	std::stack<int, std::list<int> >		std_st;

	std::cout << "stack = " << sizeof(std_st) << std::endl;
	std::cout << "size = " << std_st.size() << std::endl;
	
	std_st.push(1);
	std_st.push(2);
	std_st.push(3);
	std_st.push(4);
	std::cout << "stack = " << sizeof(std_st) << std::endl;
	std::cout << "size = " << std_st.size() << std::endl;
	
	
	ft::stack<int, std::list<int> >		ft_st;

	std::cout << "stack = " << sizeof(ft_st) << std::endl;
	std::cout << "size = " << ft_st.size() << std::endl;
	
	ft_st.push(1);
	ft_st.push(2);
	ft_st.push(3);
	ft_st.push(4);
	std::cout << "stack = " << sizeof(ft_st) << std::endl;
	std::cout << "size = " << ft_st.size() << std::endl;
	
	
	ft::stack<int, ft::list<int> >		ft_st2;

	std::cout << "stack = " << sizeof(ft_st2) << std::endl;
	std::cout << "size = " << ft_st2.size() << std::endl;
	
	ft_st2.push(1);
	ft_st2.push(2);
	ft_st2.push(3);
	ft_st2.push(4);
	std::cout << "stack = " << sizeof(ft_st2) << std::endl;
	std::cout << "size = " << ft_st2.size() << std::endl;
	
	return 0;
}
