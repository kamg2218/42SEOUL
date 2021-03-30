#include <iostream>
#include <string>
#include <fstream>

int		main(int argc, char *argv[])
{
	size_t			num;
	std::ofstream	ofs;
	std::ifstream	ifs;
	std::string		line;
	std::string		fname;

	if (argc != 4)
	{
		std::cout << "Error: Wrong Input!" << std::endl;
		return (-1);
	}
	ifs.open(argv[1], std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return (-1);
	}
	fname = static_cast<std::string>(argv[1]) + ".replace";
	ofs.open(fname, std::ofstream::out);
	if (!ofs.is_open())
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return (-1);
	}
	while (getline(ifs, line))
	{
		num = 0;
		while (num != std::string::npos)
		{
			num = line.find(argv[2], num);
			if (num == std::string::npos)
				break ;
			line.replace(num, strlen(argv[2]), argv[3]);
			num += strlen(argv[3]);
		}
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
