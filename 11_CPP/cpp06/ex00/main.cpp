#include "srcs/ConvertToChar.hpp"
#include "srcs/ConvertToInt.hpp"
#include "srcs/ConvertToFloat.hpp"
#include "srcs/ConvertToDouble.hpp"

int			main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong Input!" << std::endl;
		return -1;
	}
	
	ConvertToChar ctc;
	ConvertToInt cti;
	ConvertToFloat ctf;
	ConvertToDouble ctd;

	try{
		char c;

		std::cout << "char: ";
		c = ctc.change(argv[1]);
		std::cout << "'" << c << "'" << std::endl;
	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}

	try{
		int i;

		std::cout << "int: ";
		i = cti.change(argv[1]);
		std::cout << i << std::endl;
	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}

	try{
		float f;

		std::cout << "float: ";
		f = ctf.change(argv[1]);
		std::cout << f << std::endl;
	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}

	try{
		double d;

		std::cout << "double: ";
		d = ctd.change(argv[1]);
		std::cout << d << std::endl;
	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}

	return 0;
}
