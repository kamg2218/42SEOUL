#include <iostream>
#include <memory>

int		main(){
	int					*ptr[3];
	int					*p;
	std::allocator<int>	al;

	for (int i = 0; i < 3; i++){
		ptr[i] = al.allocate(3);
		ptr[i][0] = 10;
		ptr[i][1] = 12;
		ptr[i][2] = 14;
		for (int j = 0; j < 3; j++)
			std::cout << "al = " << ptr[i][j] << ", " << &ptr[i][j] << std::endl;
		//al.destroy(&ptr[i][1]);
		p = al.allocate(3);
		for (int j = 0; j < 3; j++)
			p[j] = ptr[i][j];
		al.deallocate(ptr[i], 3);
		ptr[i] = p;
		for (int j = 0; j < 3; j++)
			std::cout << "al = " << ptr[i][j] << ", " << &ptr[i][j] << std::endl;
	}
	std::cout << "1 = " << &ptr[0][0] << std::endl;
	std::cout << "2 = " << &ptr[1][0] << std::endl;
	std::cout << "3 = " << &ptr[2][0] << std::endl;
	for (int i = 0; i < 3; i++){
		p = al.allocate(3);
		for (int j = 0; j < 3; j++)
			p[j] = ptr[i][j];
		al.deallocate(ptr[i], 3);
		ptr[i] = p;
		for (int j = 0; j < 3; j++)
			std::cout << "al = " << ptr[i][j] << ", " << &ptr[i][j] << std::endl;
	}
	std::cout << "1 = " << &ptr[0][0] << std::endl;
	std::cout << "2 = " << &ptr[1][0] << std::endl;
	std::cout << "3 = " << &ptr[2][0] << std::endl;
	return 0;
}
