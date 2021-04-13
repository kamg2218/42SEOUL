#include <iostream>
#include "whatever.hpp"

int		main()
{
	int		a = 2;
	int		b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string	c = "chaine1";
	std::string	d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	Awesome	awe1(5);
	Awesome awe2(8);

	::swap(awe1, awe2);
	std::cout << "awe1 = " << awe1.getNum() << ", awe2 = " << awe2.getNum() << std::endl;
	std::cout << "min(awe1, awe2) = " << ::min(awe1, awe2) << std::endl;
	std::cout << "max(awe1, awe2) = " << ::max(awe1, awe2) << std::endl;
	

	return 0;
}
