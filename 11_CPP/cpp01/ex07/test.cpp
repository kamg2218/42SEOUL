#include <iostream>
#include <fstream>
#include <string>

int		main()
{
	size_t			num;
	std::string		line;
	std::ifstream	myfile;
	std::ofstream	ofs;

	myfile.open("test.txt", std::ifstream::in);
	ofs.open("test.txt.replace");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::cout << line << std::endl;
			num = 0;
			while (num != std::string::npos)
			{
				num = line.find(".");
				std::cout << num << std::endl;
				if (num == std::string::npos)
					break ;
				line.replace(num, 1, "!");
				std::cout << line << std::endl;
			}
			ofs << line;
			if (!myfile.eof())
				ofs << std::endl;
		}
	}
	else
		std::cout << "Unable to open file" << std::endl;
	myfile.close();
	ofs.close();
}
