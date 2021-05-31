#include <stack>
#include "../ft.hpp"

int		main()
{
	ft::stack<int> ft_st;
	std::stack<int> std_st;
	
	std::cout << "---- s ------------------------------------" << std::endl;
	std::cout << "std_size = " << std_st.size() << std::endl;

	std::cout << "ft_size = " << ft_st.size() << std::endl;
	
	std::cout << "---- empty() ------------------------------------" << std::endl;
	if (!std_st.empty())
		std::cout << "std_st is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	if (!ft_st.empty())
		std::cout << "ft_st is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	std::cout << "---- push ---------------------------------------" << std::endl;
	std_st.push(1);
	std_st.push(2);
	std_st.push(3);
	std::cout << "std_st size = " << std_st.size() << std::endl;
	std::cout << "std_st top = " << std_st.top() << std::endl;

	ft_st.push(1);
	ft_st.push(2);
	ft_st.push(3);
	std::cout << "ft_st size = " << ft_st.size() << std::endl;
	std::cout << "ft_st top = " << ft_st.top() << std::endl;

	std::cout << "---- empty() ------------------------------------" << std::endl;
	if (!std_st.empty())
		std::cout << "std_st is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	if (!ft_st.empty())
		std::cout << "ft_st is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	std::cout << "---- pop ----------------------------------------" << std::endl;
	std::cout << "std_st top = " << std_st.top() << std::endl;
	std_st.pop();
	std::cout << "std_st top = " << std_st.top() << std::endl;
	std_st.pop();
	std::cout << "std_st top = " << std_st.top() << std::endl;
	std::cout << "std_st size = " << std_st.size() << std::endl;

	std::cout << "ft_st top = " << ft_st.top() << std::endl;
	ft_st.pop();
	std::cout << "ft_st top = " << ft_st.top() << std::endl;
	ft_st.pop();
	std::cout << "ft_st top = " << ft_st.top() << std::endl;
	std::cout << "ft_st size = " << ft_st.size() << std::endl;

	std::cout << "---- swap() --------------------------------------" << std::endl;
	std::stack<int>		std_st2;
	ft::stack<int>		ft_st2;
	
	if (std_st.size())
		std::cout << "std_st top = " << std_st.top() << std::endl;
	std::cout << "std_st size = " << std_st.size() << std::endl;
	std_st.swap(std_st2);
	if (std_st.size())
		std::cout << "std_st top = " << std_st.top() << std::endl;
	std::cout << "std_st size = " << std_st.size() << std::endl;
	std_st.swap(std_st2);
	if (std_st.size())
		std::cout << "std_st top = " << std_st.top() << std::endl;
	std::cout << "std_st size = " << std_st.size() << std::endl;

	if (ft_st.size())
		std::cout << "ft_st top = " << ft_st.top() << std::endl;
	std::cout << "ft_st size = " << ft_st.size() << std::endl;
	ft_st.swap(ft_st2);
	if (ft_st.size())
		std::cout << "ft_st top = " << ft_st.top() << std::endl;
	std::cout << "ft_st size = " << ft_st.size() << std::endl;
	ft_st.swap(ft_st2);
	if (ft_st.size())
		std::cout << "ft_st top = " << ft_st.top() << std::endl;
	std::cout << "ft_st size = " << ft_st.size() << std::endl;
/*
	std::cout << "---- compare -------------------------------------" << std::endl;
	if (ft_st > ft_st2)
		std::cout << "ft_st is bigger\n";
	else if (ft_st < ft_st2)
		std::cout << "ft_st is smaller\n";
	else
		std::cout << "ft_st and ft_st2 is same\n";
	std::cout << "--------------------------------------------------" << std::endl;
	
	ft_st2 = ft_st;

	std::cout << "---- compare -------------------------------------" << std::endl;
	if (ft_st > ft_st2)
		std::cout << "ft_st is bigger\n";
	else if (ft_st < ft_st2)
		std::cout << "ft_st is smaller\n";
	else
		std::cout << "ft_st and ft_st2 is same\n";
	std::cout << "--------------------------------------------------" << std::endl;
*/
	return 0;
}
