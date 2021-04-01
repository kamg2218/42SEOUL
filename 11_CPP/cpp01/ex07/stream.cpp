#include "stream.hpp"

int		stream::setIfStream(std::string filename)
{
	ifs.open(filename, std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return (-1);
	}
	return (0);
}

int		stream::setOfStream(std::string filename)
{
	ofs.open(filename, std::ofstream::out);
	if (!ofs.is_open())
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return (-1);
	}
	return (0);
}

std::string		stream::getIfLine()
{
	std::string		line;

	getline(ifs, line);
	return line;
}

void	stream::putOfLine(std::string& line)
{
	ofs << line;
	if (!ifs.eof())
		ofs << std::endl;
}

bool	stream::checkIfs()
{
	if (ifs.eof())
		return false;
	return true;
}
