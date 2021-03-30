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
	fname = static_cast<std::string>(argv[1]) + ".replace";
	ifs.open(argv[1], std::ifstream::in);
	ofs.open(fname, std::ofstream::out);
	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return (-1);
	}
	while (getline(ifs, line))
	{
		num = 0;
		while (num != std::string::npos)
		{
			num = line.find(argv[2], strlen(argv[2]));
			std::cout << num << std::endl;
			if (num == std::string::npos)
				break ;
			line.replace(num, strlen(argv[2]), argv[3]);
		}
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
