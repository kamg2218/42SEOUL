#include "stream.hpp"

int		main(int argc, char *argv[])
{
	size_t			num;
	std::string		line;
	std::string		fname;
	stream			stm;

	if (argc != 4)
	{
		std::cout << "Error: Wrong Input!" << std::endl;
		return (-1);
	}
	if (stm.setIfStream(argv[1]))
		return (-1);
	fname = static_cast<std::string>(argv[1]) + ".replace";
	if (stm.setOfStream(fname))
		return (-1);
	while (stm.checkIfs())
	{
		line = stm.getIfLine();
		num = 0;
		while (num != std::string::npos)
		{
			num = line.find(argv[2], num);
			if (num == std::string::npos)
				break ;
			line.replace(num, strlen(argv[2]), argv[3]);
			num += strlen(argv[3]);
		}
		stm.putOfLine(line);
	}
	return (0);
}
