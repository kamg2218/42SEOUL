#include <vector>
#include <iostream>

int		main(){
	std::vector<int>	v;

	std::cout << "size = " << v.size() << "capacity = " << v.capacity() << std::endl;
	//for (int i = 0; i < 10; i++){
	//	v.insert(v.begin(), 3);
	//	std::cout << "size = " << v.size() << "capacity = " << v.capacity() << std::endl;
	//}
	//v.clear();
	v.insert(v.begin(), 3, 5);
	std::cout << "size = " << v.size() << "capacity = " << v.capacity() << std::endl;
	v.pop_back();
	std::cout << "size = " << v.size() << "capacity = " << v.capacity() << std::endl;
	v.insert(v.begin(), 5, 5);
	std::cout << "size = " << v.size() << "capacity = " << v.capacity() << std::endl;
	//for (int i = 0; i < 10; i++){
	//	v.insert(v.begin(), 3);
	//	std::cout << "size = " << v.size() << "capacity = " << v.capacity() << std::endl;
	//}
	return 0;
}
