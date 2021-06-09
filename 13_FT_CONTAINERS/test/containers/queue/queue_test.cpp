#include <queue>
#include <iostream>
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "queue.hpp"

int		main()
{
	ft::queue<int> ft_q;
	std::queue<int> std_q;
	
	std::cout << "---- q ------------------------------------" << std::endl;
	std::cout << "std_size = " << std_q.size() << std::endl;

	std::cout << "ft_size = " << ft_q.size() << std::endl;
	
	std::cout << "---- empty() ------------------------------------" << std::endl;
	if (!std_q.empty())
		std::cout << "std_q is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	if (!ft_q.empty())
		std::cout << "ft_q is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	std::cout << "---- push ---------------------------------------" << std::endl;
	std_q.push(1);
	std_q.push(2);
	std_q.push(3);
	std::cout << "std_q size = " << std_q.size() << std::endl;
	std::cout << "std_q front = " << std_q.front() << std::endl;
	std::cout << "std_q back = " << std_q.back() << std::endl;

	ft_q.push(1);
	ft_q.push(2);
	ft_q.push(3);
	std::cout << "ft_q size = " << ft_q.size() << std::endl;
	std::cout << "ft_q front = " << ft_q.front() << std::endl;
	std::cout << "ft_q back = " << ft_q.back() << std::endl;

	std::cout << "---- empty() ------------------------------------" << std::endl;
	if (!std_q.empty())
		std::cout << "std_q is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	if (!ft_q.empty())
		std::cout << "ft_q is not empty" << std::endl;
	else
		std::cout << "It's empty\n";

	std::cout << "---- pop ----------------------------------------" << std::endl;
	std::cout << "std_q front = " << std_q.front() << std::endl;
	std::cout << "std_q back = " << std_q.back() << std::endl;
	std_q.pop();
	std::cout << "std_q front = " << std_q.front() << std::endl;
	std::cout << "std_q back = " << std_q.back() << std::endl;
	std_q.pop();
	std::cout << "std_q front = " << std_q.front() << std::endl;
	std::cout << "std_q back = " << std_q.back() << std::endl;
	std::cout << "std_q size = " << std_q.size() << std::endl;

	std::cout << "ft_q front = " << ft_q.front() << std::endl;
	std::cout << "ft_q back = " << ft_q.back() << std::endl;
	ft_q.pop();
	std::cout << "ft_q front = " << ft_q.front() << std::endl;
	std::cout << "ft_q back = " << ft_q.back() << std::endl;
	ft_q.pop();
	std::cout << "ft_q front = " << ft_q.front() << std::endl;
	std::cout << "ft_q back = " << ft_q.back() << std::endl;
	std::cout << "ft_q size = " << ft_q.size() << std::endl;

	std::cout << "---- swap() --------------------------------------" << std::endl;
	std::queue<int>		std_q2;
	ft::queue<int>		ft_q2;
	
	if (std_q.size()){
		std::cout << "std_q front = " << std_q.front() << std::endl;
		std::cout << "std_q back = " << std_q.back() << std::endl;
	}
	std::cout << "std_q size = " << std_q.size() << std::endl;
	std_q.swap(std_q2);
	if (std_q.size()){
		std::cout << "std_q front = " << std_q.front() << std::endl;
		std::cout << "std_q back = " << std_q.back() << std::endl;
	}
	std::cout << "std_q size = " << std_q.size() << std::endl;
	std_q.swap(std_q2);
	if (std_q.size()){
		std::cout << "std_q front = " << std_q.front() << std::endl;
		std::cout << "std_q back = " << std_q.back() << std::endl;
	}
	std::cout << "std_q size = " << std_q.size() << std::endl;

	if (ft_q.size()){
		std::cout << "ft_q front = " << ft_q.front() << std::endl;
		std::cout << "ft_q back = " << ft_q.back() << std::endl;
	}
	std::cout << "ft_q size = " << ft_q.size() << std::endl;
	ft_q.swap(ft_q2);
	if (ft_q.size()){
		std::cout << "ft_q front = " << ft_q.front() << std::endl;
		std::cout << "ft_q back = " << ft_q.back() << std::endl;
	}
	std::cout << "ft_q size = " << ft_q.size() << std::endl;
	ft_q.swap(ft_q2);
	if (ft_q.size()){
		std::cout << "ft_q front = " << ft_q.front() << std::endl;
		std::cout << "ft_q back = " << ft_q.back() << std::endl;
	}
	std::cout << "ft_q size = " << ft_q.size() << std::endl;

	std::cout << "---- compare -------------------------------------" << std::endl;
	if (std_q > std_q2)
		std::cout << "std_q is bigger\n";
	else if (std_q < std_q2)
		std::cout << "std_q is smaller\n";
	else
		std::cout << "std_q and std_q2 is same\n";
	
	if (ft_q > ft_q2)
		std::cout << "ft_q is bigger\n";
	else if (ft_q < ft_q2)
		std::cout << "ft_q is smaller\n";
	else
		std::cout << "ft_q and ft_q2 is same\n";
	std::cout << "--------------------------------------------------" << std::endl;
	
	std_q2 = std_q;
	ft_q2 = ft_q;

	std::cout << "---- compare -------------------------------------" << std::endl;
	if (std_q > std_q2)
		std::cout << "std_q is bigger\n";
	else if (std_q < std_q2)
		std::cout << "std_q is smaller\n";
	else
		std::cout << "std_q and std_q2 is same\n";
	
	if (ft_q > ft_q2)
		std::cout << "ft_q is bigger\n";
	else if (ft_q < ft_q2)
		std::cout << "ft_q is smaller\n";
	else
		std::cout << "ft_q and ft_q2 is same\n";
	std::cout << "--------------------------------------------------" << std::endl;
	
	return 0;
}
