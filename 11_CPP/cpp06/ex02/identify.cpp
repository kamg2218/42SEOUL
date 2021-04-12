#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

typedef Base* (*function)();

Base*	getA() { return new A; }
Base*	getB() { return new B; }
Base*	getC() { return new C; }

Base*	generate()
{
	Base*		base;
	function	func[3] = {getA, getB, getC};
	
	srand(clock());
	base = func[rand() % 3]();
	return base;
}

void	identify_from_pointer(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "No Exist" << std::endl;
}

void	identify_from_reference(Base& p)
{
	Base*	ptr = &p;

	if (dynamic_cast<A*>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "No Exist" << std::endl;
}

int		main(void)
{
	Base*	base;

	base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;

	std::cout << "------------" << std::endl;
	base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;

	std::cout << "------------" << std::endl;
	base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;

	return 0;
}
