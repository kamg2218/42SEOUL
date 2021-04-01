#include <iostream>

int			main(void)
{
	int			num;

	num = 2;
	std::cout << "num =" << num << std::endl;
	num = num << 1;
	std::cout << "num =" << num << std::endl;

	float		ft;

	ft = 3.42;
	std::cout << "ft = " << ft << std::endl;
	ft = ft * (1 << 1);
	std::cout << "ft = " << ft << std::endl;
	num = (int)ft;
	std::cout << "num = " << num << std::endl;
	num = static_cast<int>(ft);
	std::cout << "num = " << num << std::endl;

	return 0;
}
