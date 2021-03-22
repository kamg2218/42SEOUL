#include <iostream>
#include <string>

int			main(void)
{
	std::string		str1 = "HI THIS IS BRAIN";
	std::string		str2 = str1 + ", either";
	std::string		&rfc = str1;
	std::string		ptr;
	
	ptr = str1;
	std::cout << "The Origin is \'" << str1 << "\'" << std::endl;
	std::cout << "The Second is \'" << str2 << "\'" << std::endl;
	std::cout << "The reference is \'" << rfc << "\'" << std::endl;
	std::cout << "The pointer is \'" << ptr << "\'" << std::endl;
	ptr = str2;
	std::cout << std::endl << "The Origin is \'" << str1 << "\'" << std::endl;
	std::cout << "The Second is \'" << str2 << "\'" << std::endl;
	std::cout << "The pointer is changed to \'" << ptr << "\'" << std::endl;
	rfc = str2;
	std::cout << std::endl << "The Origin is \'" << str1 << "\'" << std::endl;
	std::cout << "The Second is \'" << str2 << "\'" << std::endl;
	std::cout << "The reference is changed to \'" << rfc << "\'" << std::endl;
	return (0);
}
