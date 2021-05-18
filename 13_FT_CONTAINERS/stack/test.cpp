#include <stack>
#include <vector>
#include <iostream>

int		main(){
	std::stack<int, std::vector<int> >		st;

	std::cout << "stack = " << sizeof(st) << std::endl;
	std::cout << "size = " << st.size() << std::endl;
	
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	std::cout << "stack = " << sizeof(st) << std::endl;
	std::cout << "size = " << st.size() << std::endl;
	
	
	return 0;
}
