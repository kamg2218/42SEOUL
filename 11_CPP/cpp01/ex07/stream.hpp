#ifndef STREAM_HPP
# define STREAM_HPP

#include <iostream>
#include <string>
#include <fstream>

class	stream
{
	private:
		std::ofstream ofs;
		std::ifstream ifs;
	public:
		bool	checkIfs();
		int setIfStream(std::string filename);
		int setOfStream(std::string filename);
		std::string	getIfLine();
		void	putOfLine(std::string& line);
		~stream() { ofs.close(); ifs.close(); }
};

#endif
